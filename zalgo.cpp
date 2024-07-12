int zalgo(string &str , string &patt)
{
    str = patt + "&" + str;
    int n = str.length();
    int m = patt.length();
    vector<int> vt(n , 0);
    int l = 0 , r = 0;
    for(int i = 1;i<n;i++)
    {
        if(l <= i) vt[i] = max(0 , min(r - i , vt[i-l]));
        while(i+vt[i] < n && str[vt[i]] == str[i+vt[i]]) vt[i]+=1;

        if(r < i+vt[i])
        {
            l = i;
            r = i+vt[i];
        }
    }

    int cnt = 0;
    for(int i = m+1;i<n;i++) cnt += (vt[i] >= m);
    return cnt;
}