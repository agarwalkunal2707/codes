void dfs(int i,int p,unordered_map<int,list<int>>&adj, vector<vector<int>>&dp){
    
    vector<int> prefix;
    for(auto j:adj[i]){
        if(j==p)continue;
        dfs(j,i,adj,dp);
    }
    
     for(auto j:adj[i]){
        if(j==p)continue;
        
        int x=max(dp[j][0],dp[j][1]);
        prefix.push_back(x);
        dp[i][0]+=x;
    }
    for(int i=1;i<prefix.size();i++){
        prefix[i]+=prefix[i-1];
    }
    int k=0;
     for(auto j:adj[i]){
        if(j==p)continue;
        
        int a=k==0?0:prefix[k-1];
        int b=prefix[prefix.size()-1]-prefix[k];
        dp[i][1]=max(dp[i][1],1+a+b+dp[j][0]);
        k++;
    }
}






void dfs(int i,int p,unordered_map<int,list<pair<int,int>>> &adj,vector<vector<int>> &dp){
 
  if(i!=1&&adj[i].size()==1){
    return;
  } 
    for(auto j:adj[i]){
        if(j.first==p)continue;
        dfs(j.first,i,adj,dp);
    }
    int maxi1=-1e12;int maxi2=-1e12;
     for(auto j:adj[i]){
        if(j.first==p)continue;
        dp[i][0]+=2*j.second+dp[j.first][0];  
    }
   dp[i][1]=dp[i][0];
    for(auto j:adj[i]){
        if(j.first==p)continue;
        dp[i][1]=min(dp[i][1],dp[i][0]-dp[j.first][0]-j.second+dp[j.first][1]);
    }
   }






   void dfs(int i,int p,vector<int> &w,unordered_map<int,list<pair<int,int>>> &adj,vector<vector<int>> &dp){
 
  if(i!=1&&adj[i].size()==1){
    dp[i][0]=w[i];
    dp[i][1]=w[i];
    ans=max(ans,w[i]);
    return;
  } 
    for(auto j:adj[i]){
        if(j.first==p)continue;
        dfs(j.first,i,w,adj,dp);
    }
    int maxi1=-1e12;int maxi2=-1e12;
     for(auto j:adj[i]){
        if(j.first==p)continue;
        dp[i][0]=max(dp[i][0],max(w[i],w[i]-j.second+dp[j.first][0]));
        if(dp[j.first][0]-j.second>=maxi1){
            maxi2=maxi1;
             maxi1=dp[j.first][0]-j.second;
        }
        else if(dp[j.first][0]-j.second>maxi2){
            maxi2=dp[j.first][0]-j.second;
        }
    }
   
    for(auto j:adj[i]){
        if(j.first==p)continue;
        if(maxi1!=-1e12&&maxi2!=-1e12)
        dp[i][1]=max(dp[i][1],max(w[i],w[i]+maxi1+maxi2));
    }
    ans=max(ans,max(dp[i][0],dp[i][1]));
}







// tree diameter 
int ans=0;
int dfs(int i,int p,unordered_map<int,list<int>>&adj, vector<int>&dp){
    
    int x=0;int maxi1=0;int maxi2=0;
    for(auto j:adj[i]){
        if(j==p)continue;
        x=dfs(j,i,adj,dp);
         if(x>maxi1){
          maxi2=maxi1;
          maxi1=x;
      }
      else if(x>maxi2){
          maxi2=x;
      }
    }
     dp[i]=max(dp[i],1+maxi1+maxi2);
  ans=max(ans,dp[i]-1);
    return 1+max(maxi1,maxi2);
}


















