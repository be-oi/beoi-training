#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class UF {
    private:
        std::vector<int> parent;
        std::vector<int> rank;

    public:
        UF(int num_elements) {
            rank.assign(num_elements, 0);
            parent.assign(num_elements, 0);
            for (int i = 0; i < num_elements; i++)
                parent[i] = i;      //All separate sets, each is its own root
        }

        int find(int a) { // Or getParent of course
            if (parent[a] == a)
                return a;
            return parent[a] = find(parent[a]); //path compression
        }

        bool sameSet(int a, int b) {
            return find(a) == find(b);
        }

        // Unfortunately, union is a keyword
        void merge(int a, int b) {
            int par_a = find(a);
            int par_b = find(b);
            if (par_a == par_b) return;

            //heuristic by rank
            if (rank[par_a] > rank[par_b]) {
                parent[par_b] = par_a;
            } else {
                parent[par_a] = par_b;
                if (rank[par_a] == rank[par_b])
                    rank[par_b]++;
            }
        }
};


int n,m,total=0;
vector< pair<int, pair<int, int> > > G, M;

void Kruskal() {
	UF uf(n);
    sort(G.begin(), G.end());
    for(int i=0;i<m;i++) {
    	int x = G[i].second.first;
    	int y = G[i].second.second;
        if(!uf.sameSet(x, y)) {
            M.push_back(G[i]);
            total += G[i].first;
            uf.merge(x, y);
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i  = 0; i < m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        G.push_back(make_pair(w,make_pair(u,v)));
    }
    Kruskal();
    cout<<total;
    return 0;
}

