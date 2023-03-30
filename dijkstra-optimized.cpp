#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+5;
const long long INF= 1e18;
int visited[N];
long long dis[N];
int parent[N];
vector<pair<int ,int>>adj_list[N];
int nodes,edges;
void dij(int node){
    for(int i=1 ; i <= nodes ; i++){
        dis[i]=INF;
    }
    dis[node]=0;
    priority_queue<pair<long long  , int >>pq;
    pq.push({0,node});
    while(!pq.empty()){
        pair<long long , int>head = pq.top();
        pq.pop();
        int selected_node = head.second;
        if(visited[selected_node]== 1){
            continue;
        }
        visited[selected_node]= 1;

        for(auto adj_entry : adj_list[selected_node]){
            int adj_node = adj_entry.first;
            int cost = adj_entry.second;
            if(dis[selected_node] + cost < dis[adj_node]){
                dis[adj_node] = dis[selected_node] + cost;
                parent[adj_node]=selected_node;
                pq.push({-dis[adj_node],adj_node}); 
            }
        }
    }
}
int main(){
    cin >> nodes >> edges;

    for(int i=1 ; i <= edges ;i++){
        int u,v,w;
        cin>> u >> v >> w;
        adj_list[u].push_back({v,w});
        adj_list[v].push_back({u,w});
    }
    int src = 1;
    int dst = nodes;
    dij(src);
    vector<int>path;
    int select = dst;
    if(visited[nodes] == 0){
        cout<<"-1"<<"\n";
        return 0;
    }
    while(true){
        path.push_back(select);
        if(select == src){
            break;
        }
        select = parent[select];
    }
    reverse(path.begin(),path.end());
    for(auto v : path){
        cout <<v<< " ";
    }
    return 0;
}