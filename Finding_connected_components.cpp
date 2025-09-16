int connected_components() {
        int n,m;
        cin >> n >> m;
        vector<int>adj[n+1];
        for(int i= 0; i < m; i++){
            int u,v;
            cin >> u >> v;
            
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
        
        vector<bool>visited(n+1, 0);
        int count = 0;
        for(int i = 1; i <= n; i++){
            if(visited[i]) continue;
            count++;
          
            queue<int>q;
            q.push(i);
            visited[i] = 1;
           
            while(!q.empty()){
                int u = q.front();
                q.pop();
           
                for(int v : adj[u]){
                    if(visited[v]) continue;

                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
        return count;

    }
