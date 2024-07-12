// used to find longest palindromic substring centred at centre 
// used to check if substring(l,r) is pal or not 


struct manacher{
  vector<int> p;

  void run_manacher(string s){
    int n=s.length();
    p.assign(n,1);
    int l=1;int r=1;
    for(int i=1;i<n;i++){
         if(l+r-i>=0)
        p[i]=max(0,min(r-i,p[l+r-i]));
        else p[i]=0;
        while(i+p[i]<n&&i-p[i]>=0&&s[i+p[i]]==s[i-p[i]]){
            p[i]++;
        }
       if(i+p[i]>r){
        l=i-p[i];
        r=i+p[i];
       }
    }
  }
    

void build(string s){
    string t;
    for(auto v:s){
        t+=string("#")+v;
    }
    run_manacher(t+"#");
  }

// odd=1 -> odd centre
// else even centre 
  // even means suppose babbab
  // and cen=2 and even it means centre is b/w 2 and 3
  int getLongestPal(int cen,bool odd){
    int pos=2*cen+1+(!odd);
    return p[pos]-1;
  }

  bool checkPal(int l,int r){
    if((r-l+1)<=getLongestPal((l+r)/2,l%2==r%2)){
        return 1;
    }
    else{
        return 0;
    }
  }
}manacher;



 string s;cin>>s;
    manacher.build(s);

      int len=manacher.getLongestPal(cen,1); // 0 for even
      bool check=manacher.checkPal(l,r);