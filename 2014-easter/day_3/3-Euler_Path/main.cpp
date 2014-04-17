#include <cstdio>
#include <set>
using namespace std;


set<int> neighbours[1000];

void find_euler_tour(int curr){
    while(!neighbours[curr].empty()){
        int next = *neighbours[curr].begin();
        neighbours[curr].erase(neighbours[curr].begin());
        neighbours[next].erase(curr);
        find_euler_tour(next);
    }
    printf("%d\n", curr+1);
}

int main(){
    int n;
    int e;
    scanf("%d%d", &n, &e);
    for(int i = 0; i < e; ++i){
        int n1, n2;
        scanf("%d%d", &n1, &n2);
        neighbours[n1].insert(n2);
        neighbours[n2].insert(n1);
    }
    int start = 0;
    for(int i = 0; i < n; ++i){
        if(neighbours[i].size()%2==1)
            start = i;
    }
    find_euler_tour(start);
    return 0;
}
