vector<int> get_path() {
        int n,m;
        cin >> n >> m;
        vector<int>adj[n+1];
        for(int i= 0; i < m; i++){
            int u,v;
            cin >> u >> v;
            
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
        
        int src, dest;
        cin >> src >> dest;

        vector<int>visited(n+1, 0), distance(n+1, 0), prev(n+1, 0);
        queue<int>q;

        q.push(src);
        visited[src] = 1;
        distance[src] = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(u == dest) break;
            for(int v: adj[u]){
                if(visited[v]) continue;

                visited[v] = 1;
                distance[v] = distance[u] + 1;
                q.push(v);
                prev[v] = u;
            }
        }
        vector<int>path;
        int x = dest;
        while(1) {
            path.push_back(x);
            if(x == src){
                break;
            }
            x = prev[x];
        }
        reverse(path.begin(), path.end());
        return path;
    }
