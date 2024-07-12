int up[200001][20]; int lvl[200001];

 void binarylift(int i,int p,unordered_map<int,list<int>>&adj){
    up[i][0]=p;
    for(int j=1;j<20;j++){
     if(up[i][j-1]!=-1){
        up[i][j]=up[up[i][j-1]][j-1];
     }
     else{
        up[i][j]=-1;
     }
    }

    for(auto j:adj[i]){
        if(j==p)continue;
        binarylift(j,i,adj);
    }
 }

// or 
  for(int i=1;i<=n;i++){
       cin>>up[i][0];
    }
    for (int d = 1; d < 30; d++){
         for (int i = 1; i <= n; i++) {
            up[i][d] = up[up[i][d - 1]][d - 1];
        }
    }




// to lift a node k lvl up 
 int liftnode(int node,int k){  
   

    for(int i=19;i>=0;i--){
         if(node==-1||k==0)break;

        if(k>=(1<<i)){
            k-=(1<<i);
            node=up[node][i];
        }
    }
    return node;
 }
void dfs(int i,int p,int l,unordered_map<int,list<int>>&adj){
    lvl[i]=l;
    for(auto j:adj[i]){
        if(j!=p){
            dfs(j,i,l+1,adj);
        }
    }
}

int lca2(int u,int v){
    if(lvl[u]>lvl[v]){
         swap(u,v);
    }
    v=liftnode(v,lvl[v]-lvl[u]);
    if(u==v)return u;
    for(int i=19;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v=up[v][i];
        }
    }
    return liftnode(u,1);
}
void solve()
{
    int n,q;cin>>n>>q;
    unordered_map<int,list<int>> adj;
    for(int i=2;i<=n;i++){
        int a,b;cin>>a>>b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }

  binarylift(1,-1,adj);
 dfs(1,-1,0,adj);

 while(q--){
    int u,v;cin>>u>>v;
    int lca=lca2(u,v);
 }
}