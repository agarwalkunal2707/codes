void dfs1(int i,int p,unordered_map<int,list<int>>&adj, vector<int>&dp, vector<int>&nodes){
    
    int x=0;int c=0;
    for(auto j:adj[i]){
        if(j==p)continue;
        dfs1(j,i,adj,dp,nodes);
    }
     for(auto j:adj[i]){
        if(j==p)continue;
        nodes[i]+=nodes[j];
        dp[i]+=dp[j]+nodes[j];
    }
    nodes[i]+=1;
}
void dfs2(int i,int p,int n,unordered_map<int,list<int>>&adj, vector<int>&dp, vector<int>&nodes){
    
     for(auto j:adj[i]){
        if(j==p)continue;
       dp[j]+= dp[i]-(dp[j]+nodes[j])+(n-nodes[j]);
        dfs2(j,i,n,adj,dp,nodes);
    }
    
}
void solve()
{
     int n;cin>>n;
    unordered_map<int,list<int>> adj;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> dp(n+1,0); vector<int> nodes(n+1,0);
    dfs1(1,-1,adj,dp,nodes);
    dfs2(1,-1,n,adj,dp,nodes);
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    
    
}
