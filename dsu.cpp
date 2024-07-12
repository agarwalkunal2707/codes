class disjointset{
    public:
     vector<int> parent,size,rank;
    disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findparent(int u){
        if(u==parent[u])
            return u;
        return parent[u]=findparent(parent[u]);
    }
    
    void unionbysize(int u,int v){
        
        int p1=findparent(u);
        int p2=findparent(v);
        if(p1==p2)return;
        
        if(size[p1]<size[p2]){
            parent[p1]=p2;
            size[p2]+=size[p1];
        }
        else{
            parent[p2]=p1;
            size[p1]+=size[p2];
        }
    }
    
     void unionbyrank(int u, int v) {
        int p1=findparent(u);
        int p2=findparent(v);
         if(p1==p2)return;
         
        if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
        }
        else if (rank[p2] < rank[p1]) {
            parent[p2] = p1;
        }
        else {
            parent[p2] = p1;
            rank[p1]++;
        }
    }

};

//  if(ds.findparent(u)==ds.findparent(v)){
    //  ds.unionbysize(u,v);
    //  if(ds.parent[i]==i)