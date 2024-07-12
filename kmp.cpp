 vector<int> kmp(string &text, string &pattern, vector<int>& prefix) {
        vector<int> a;
        int j = 0;
        for (int i = 0; i < text.length(); i++) {
            while (j > 0 && text[i] != pattern[j]) {
                j = prefix[j - 1];
            }
            if (text[i] == pattern[j]) {
                j++;
            }
            if (j == pattern.length()) {
                a.push_back(i - j + 1);
                j = prefix[j - 1];
            }
        }
        return a;
    }
    
      vector<int> solve(string &pattern) {
        vector<int> p(pattern.length());
        int j = 0;
        for (int i = 1; i < pattern.length(); i++) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = p[j - 1];
            }
            if (pattern[i] == pattern[j]) {
                j++;
            }
            p[i] = j;
        }
        return p;
    }
    
      vector<int> p1 = solve(a);
        vector<int> v1=kmp(s,a,p1);
        
        // v1 contains all those indices which contains a in s;