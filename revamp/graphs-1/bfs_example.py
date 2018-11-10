file_output = open("bfs_example.tex", "w")


V = []
V.append((1, 0, 0))
V.append((2, 2.5, 1.3))
V.append((3, 1.6, -0.25))
V.append((4, 1.8, -1.5))
V.append((5, 1.3, -2.65))
V.append((6, -0.4, -2.1))
V.append((7, 3.8, 0.2))
V.append((8, 3.2, -1.9))
V.append((9, 2.7, -2.85))
V.append((10, 2.5, -1.75/2))

E = []

E.append((1, 2))
E.append((1, 3))
E.append((1, 4))
E.append((1, 5))
E.append((1, 6))
E.append((2, 7))
E.append((3, 7))
E.append((3, 4))
E.append((4, 5))
E.append((4, 6))
E.append((4, 8))
E.append((4, 10))
E.append((5, 6))
E.append((5, 9))
E.append((7, 8))
E.append((7, 10))
E.append((8, 9))

dist = [-1 for i in range(len(V))]

queue = []

queue.append(0)
dist[0] = 0



def bfs():
	global queue, dist
	while(len(queue) != 0):
		first = queue[0]

		queue = queue[1:]

		print_graph(first, -1, queue, dist, -1)

		#print(dist)

		for edge in E:
			t, f = edge
			d = -1

			if t-1 == first:
				d = f

			elif f-1 == first:
				d = t



			if d != -1:
				if dist[d-1] == -1:
					dist[d-1] = dist[first] + 1
					queue.append(d-1)
					print_graph(first, d-1, queue, dist, d)
				else:
					print_graph(first, d-1, queue, dist, -1)
			




def print_graph(current, to, queue, dist, added ):
	file_output.write("\\begin{frame}{BFS : Example}\n")
	file_output.write("\\begin{figure}\n")
	file_output.write("\\vspace*{-1cm} \n")
	file_output.write("\\center\n")
	file_output.write("\\begin{tikzpicture}[scale=1.2] \n")


	file_output.write("\\node[shape=circle, draw=red, 	ultra thick, scale=1.5pt, label={Current}] (U) at (-2.5, 1) {}; \n")
	file_output.write("\\node[shape=circle, draw=green,  ultra thick, scale=1.5pt, label={In queue}] (U) at (-2.5, 0) {}; \n")
	file_output.write("\\node[shape=circle, draw=black, ultra thick, scale=1.5pt, label={Not in queue}] (U) at (-2.5, -1) {}; \n")


	file_output.write("\\draw[thick, rounded corners,draw=black] (4.55, 1.5) rectangle ++(0.9, -1-4*0.85 );\n")

	file_output.write("\\node[draw=white] at (5, 2) {Queue State} ; \n")

	for i in range(len(queue)):
		node = queue[i]
		file_output.write("\\node[shape=circle, draw=black, thick, minimum size=2pt] (U"+str(i)+ ") at (5, "+str(1-0.85*i)+") {\\tiny{" +str(node+1)+"}}; \n")

	for i in range(len(queue)):
		if i + 1 < len(queue):
			file_output.write("\\path[->] (U"+str(i+1)+") edge [out=75, in=-75] (U"+str(i)+");\n")

	if added != -1:
		file_output.write("\\path[->, thick, draw=black] ("+str(added)+") edge [dashed, bend right=30] (U"+str(len(queue)-1)+"); \n")




	for v in V:
		name, x, y = v

		dstring = "$"+str(dist[name-1])+"$" if dist[name-1] != -1 else "$\infty$"

		if name - 1 == current:
			file_output.write("\\node[shape=circle,draw=red, ultra thick, label={"+dstring+"}] (" + str(name) + ") at (" + str(x) + "," + str(y) + ") {" + str(name) + "}; \n")
		elif name - 1 in queue:
			file_output.write("\\node[shape=circle,draw=green, ultra thick, label={"+dstring+"}] (" + str(name) + ") at (" + str(x) + "," + str(y) + ") {" + str(name) + "}; \n")
		else:
			file_output.write("\\node[shape=circle,draw=black, ultra thick, label={"+dstring+"}] (" + str(name) + ") at (" + str(x) + "," + str(y) + ") {" + str(name) + "}; \n")
		

	for j in range(len(E)):
		f, t = E[j]
		bb = (f - 1 == current and t-1== to) or (f-1 == to and t-1 == current)
		if bb:
			file_output.write("\\path [->,very thick, draw=red] ("+str(current+1)+") edge  ("+str(to+1)+");\n")
		else : 
			file_output.write("\\path [-,very thick, draw=black] ("+str(f)+") edge  ("+str(t)+");\n")


	
		

	file_output.write("\\end{tikzpicture} \n")
	file_output.write("\\end{figure} \n")
	file_output.write("\\end{frame} \n")

bfs()
file_output.close()
