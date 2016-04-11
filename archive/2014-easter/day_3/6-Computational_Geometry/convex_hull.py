#Graham scan
import random
N = 100
MAXCOORDINATE = 1000000
points = [[random.randint(0,MAXCOORDINATE) for i in range(2)]\
	 	for j in range(N)]

def cross_product(v1, v2):
	return v1[0]*v2[1]-v1[1]*v2[0]
def subtract(p1, p2):
	return [p2[0]-p1[0], p2[1]-p1[1]]

points.sort();
def convex_hull(points, cp_val):
	current_connected = [0,1]
	for i in range(len(points)):
		current = points[i]
		previous = points[current_connected[-1]]
		if previous[0] == current[0]:
			if (current[1]-previous[1])*cp_val >= 0:
				del current_connected[-1]
			else:
				continue
		while True:
			if len(current_connected) == 1:
				break;
			v1 = subtract(points[i], points[current_connected[-1]])
			v2 = subtract(points[current_connected[-2]],\
					points[current_connected[-1]])
			cp = cross_product(v1, v2)
			if cp * cp_val >= 0:
				del current_connected[-1]
			else:
				break
		current_connected.append(i)
	return current_connected
top = convex_hull(points, 1)
bottom = convex_hull(points, -1)
result = [points[i] for i in top] +\
		 [points[bottom[i]] for i in range(len(bottom)-1, -1, -1)]
#print "with(plots):with(plottools):points := pointplot(",points,"):","convex_hull:=polygon(",result,",color=red,linestyle=dash,thickness=2):display([points, convex_hull]);"

