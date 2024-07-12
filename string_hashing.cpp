class StringHasher {
private:
    string s;
    vector<long long> prefixHash;
    vector<long long> suffixHash;
    vector<long long> power;
    const int MOD = 1e9 + 7;
    const int BASE = 31;

public:
    StringHasher(const string& str) {
        s = str;
        int n = s.size();
        prefixHash.resize(n + 1);
        suffixHash.resize(n + 1);
        power.resize(n + 1);

        prefixHash[0] = 0;
        suffixHash[n] = 0;
        power[0] = 1;

        for (int i = 1; i <= n; ++i) {
            prefixHash[i] = (prefixHash[i - 1] * BASE + s[i - 1]) % MOD;
            power[i] = (power[i - 1] * BASE) % MOD;
        }

        for (int i = n - 1; i >= 0; --i) {
            suffixHash[i] = (suffixHash[i + 1] * BASE + s[i]) % MOD;
        }
    }

    long long getPrefixHash(int l, int r) {
        long long hashValue = (prefixHash[r + 1] - (prefixHash[l] * power[r - l + 1]) % MOD + MOD) % MOD;
        return hashValue;
    }

    long long getSuffixHash(int l, int r) {
        long long hashValue = (suffixHash[l] - (suffixHash[r + 1] * power[r - l + 1]) % MOD + MOD) % MOD;
        return hashValue;
    }

    bool isPrefix(int l, int r) {
        int len = r - l + 1;
        if (len > s.size()) return false; // Invalid range
        return getPrefixHash(l, r) == getPrefixHash(0, len - 1);
    }

    bool isSuffix(int l, int r) {
        int len = r - l + 1;
        int n = s.size();
        if (len > n) return false; // Invalid range
        return getSuffixHash(l, r) == getSuffixHash(n - len, n - 1);
    }
};


int main() {
    string s = "examplestring";
    StringHasher hasher(s);

    // Example for prefix
    int l1 = 2, r1 = 4;
    if (hasher.isPrefix(l1, r1)) {
        cout << "The substring from index " << l1 << " to " << r1 << " matches the prefix of the string." << endl;
    } else {
        cout << "The substring from index " << l1 << " to " << r1 << " does not match the prefix of the string." << endl;
    }

    // Example for suffix
    int l2 = 9, r2 = 11;
    if (hasher.isSuffix(l2, r2)) {
        cout << "The substring from index " << l2 << " to " << r2 << " matches the suffix of the string." << endl;
    } else {
        cout << "The substring from index " << l2 << " to " << r2 << " does not match the suffix of the string." << endl;
    }