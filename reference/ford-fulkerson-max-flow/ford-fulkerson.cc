
#define MAX_V 100

const int INF = 987654321;
int V;

int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

int networkFlow(int source, int sink)
{
	memset(flow, 0, sizeof(flow));
	int totalFlow = 0;
	while(true) {
		// find augmenting path with BFS
		vector<int> parent(MAX_V, -1);
		queue<int> q;
		parent[source] = source;	// set root
		q.push(source);
		while(!q.empty()) {
			int here = q.front(); q.pop();
			for (int there = 0; there < V; ++there)
				// follow an edge that has capacity remaining
				if (capacity[here][there] - flow[here][there] > 0 && parent[there]) {
					q.push(there);
					parent[there] = here;
				}
		}
		// end when there is no more augmenting path
		if (parent[sink] == -1) break;
		// get amount of flow (minimum in path)
		int amount = INF;
		for (int p = sink; p != source; p = parent[p])
			amount = min(capacity[parent[p][p] - flow[parent[p]][p]], amount);
		// send flow and update flow graph
		for (int p = sink; p != source; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalFlow += amount;
	}
	return totalFlow;
}

