// Author : Naimul Haque, 29/11/2019
// Spreading of the Z virus

#include <iostream>
#include <vector>
#include <queue>
#include <utility> 

using namespace std;

typedef pair<int,int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;

vvi adj;
vi visited;
vi infected;

queue<ii> q;

void bfs(int s,int day){
    
    q.push(ii(s,day));
    visited[s] = true;
    
     while(!q.empty()){
         ii u = q.front();
         q.pop();
         
         day = u.second;
         infected[day]++;
         
         cout << "Visiting node "<< u.first <<" in day "<< day<< endl;
         
         for(auto next: adj[u.first]){
             if(!visited[next]) q.push(ii(next,day+1)),visited[next] = true;
         }
        
         
     }
     
    cout << "debug "<< infected[1] << endl;
}
int main() {
	
	int n,m,t,s;
	
	cin >> n;
	
	adj.resize(n);
	
	for(int u = 0; u < n; u++){
	    cin >> m;
	    
	    int v;
	    
	    while(m--){cin >> v; adj[u].push_back(v); }
	    
	}
	
	cin >> t;
	
	while(t--){
	    cin >> s;
	    int day = 1;
	    
	    visited.assign(n,false);
	    infected.assign(n,0);
	    
	    bfs(s,day);
	    
	    int max_infected, day_of_max;
	    
	    max_infected = 0;
	    day_of_max = 0;
	    
	    for(int i = 0; i < n; i++){
	        if(max_infected<infected[i]) max_infected = infected[i], day_of_max = i;
	    }
	    
	    cout << max_infected << " " << day_of_max << endl;
	}

	
	return 0;
}
