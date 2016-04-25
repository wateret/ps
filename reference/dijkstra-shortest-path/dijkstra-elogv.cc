#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int inf = 987654321;
vector< int > dijkstra( const vector< vector< pair<int,int> > > &G, const int start ) {
	const int N = (int)G.size();

	vector< int > dist( N, inf );
	dist[ start ] = 0;

	set< pair<int,int> > pq;

	pq.insert( make_pair( 0, start ) );
	while( !pq.empty() ) {

		pair<int,int> top = *pq.begin();
		pq.erase(top);

		int current = top.second;

		const vector< pair<int,int> > &edges = G[current];

		for( int i = 0 ; i < edges.size() ; ++i ) {
			int next = edges[i].first;

			if( dist[next] > dist[ current ] + edges[i].second ) {
				pq.erase( make_pair( dist[next], next ) );
				pq.insert( make_pair( dist[current] + edges[i].second, next ) );
				dist[next] = dist[ current ] + edges[i].second;
			}

		}

	}

	return dist;

}

int main() {
	int E, V;

	cin >> E >> V;

	vector< vector< pair<int,int> > > G( V );
	for( int i = 0 ; i < E ; ++i ) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;

		G[u].push_back( make_pair(v,w) );
		G[v].push_back( make_pair(u,w) );
	}

	vector<int> ret = dijkstra( G, 0 );

	cout << ret[V-1] << endl;
}
