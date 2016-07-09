void process(int vtx) {
	taken[vtx] = 1;
	for (int j = 0; j < AdjList[vtx].size(); j++) {
		ii v = AdjList[vtx][j];
		if (!taken[v.first]) 
			pq.push(ii(-v.second, -v.first));
	}
}

// inside int main() --- assume the graph is stored in AdjList, pq is empty
taken.assign(V, 0);
process(0);
mst_cost = 0;
while (!pq.empty()) {
	ii front = pq.top(); pq.pop();
	u = -front.second, w = -front.first;
	if (!taken[u])
		mst_cost += w, process(u);
}
printf("MST cost = %d\n", mst_cost);

