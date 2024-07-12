struct Node {
    int maxVal;
    int index;

    Node() {
        maxVal = INT_MIN;
        index = -1;
    }
};

class SegmentTree {
private:
    vector<Node> tree;
    int n;

    void buildTree(vector<int>& arr, int start, int end, int treeNode) {
        if (start == end) {
            tree[treeNode].maxVal = arr[start];
            tree[treeNode].index = start;
            return;
        }

        int mid = (start + end) / 2;
        buildTree(arr, start, mid, 2 * treeNode);
        buildTree(arr, mid + 1, end, 2 * treeNode + 1);

        if (tree[2 * treeNode].maxVal > tree[2 * treeNode + 1].maxVal) {
            tree[treeNode].maxVal = tree[2 * treeNode].maxVal;
            tree[treeNode].index = tree[2 * treeNode].index;
        } else {
            tree[treeNode].maxVal = tree[2 * treeNode + 1].maxVal;
            tree[treeNode].index = tree[2 * treeNode + 1].index;
        }
    }

    void updateTree(int idx, int val, int start, int end, int treeNode) {
        if (start == end) {
            tree[treeNode].maxVal = val;
            return;
        }

        int mid = (start + end) / 2;
        if (idx <= mid)
            updateTree(idx, val, start, mid, 2 * treeNode);
        else
            updateTree(idx, val, mid + 1, end, 2 * treeNode + 1);

        if (tree[2 * treeNode].maxVal > tree[2 * treeNode + 1].maxVal) {
            tree[treeNode].maxVal = tree[2 * treeNode].maxVal;
            tree[treeNode].index = tree[2 * treeNode].index;
        } else {
            tree[treeNode].maxVal = tree[2 * treeNode + 1].maxVal;
            tree[treeNode].index = tree[2 * treeNode + 1].index;
        }
    }

    Node query(int left, int right, int start, int end, int treeNode) {
        // Completely outside the range
        if (start > right || end < left) {
            Node result;
            return result;
        }

        // Completely inside the range
        if (start >= left && end <= right) {
            return tree[treeNode];
        }

        // Partially inside and partially outside
        int mid = (start + end) / 2;
        Node ans1 = query(left, right, start, mid, 2 * treeNode);
        Node ans2 = query(left, right, mid + 1, end, 2 * treeNode + 1);

        Node result;
        if (ans1.maxVal > ans2.maxVal) {
            result.maxVal = ans1.maxVal;
            result.index = ans1.index;
        } else {
            result.maxVal = ans2.maxVal;
            result.index = ans2.index;
        }

        return result;
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, n - 1, 1);
    }

    void update(int idx, int val) {
        updateTree(idx, val, 0, n - 1, 1);
    }

    pair<int, int> getMaxInRange(int left, int right) {
        Node result = query(left, right, 0, n - 1, 1);
        return make_pair(result.maxVal, result.index);
    }
};

int main() {
    vector<int> arr = {1, 3, 2, 7, 9, 11};
    SegmentTree segTree(arr);

    cout << "Maximum value in range [1, 4]: " << segTree.getMaxInRange(1, 4).first << " at index " << segTree.getMaxInRange(1, 4).second << endl;

    segTree.update(2, 8);

    // maximum value with index 
















    struct Node {
    int minVal;
    int index;

    Node() {
        minVal = INT_MAX;
        index = -1;
    }
};

class SegmentTree {
private:
    vector<Node> tree;
    int n;

    void buildTree(vector<int>& arr, int start, int end, int treeNode) {
        if (start == end) {
            tree[treeNode].minVal = arr[start];
            tree[treeNode].index = start;
            return;
        }

        int mid = (start + end) / 2;
        buildTree(arr, start, mid, 2 * treeNode);
        buildTree(arr, mid + 1, end, 2 * treeNode + 1);

        if (tree[2 * treeNode].minVal < tree[2 * treeNode + 1].minVal) {
            tree[treeNode].minVal = tree[2 * treeNode].minVal;
            tree[treeNode].index = tree[2 * treeNode].index;
        } else {
            tree[treeNode].minVal = tree[2 * treeNode + 1].minVal;
            tree[treeNode].index = tree[2 * treeNode + 1].index;
        }
    }

    void updateTree(int idx, int val, int start, int end, int treeNode) {
        if (start == end) {
            tree[treeNode].minVal = val;
            return;
        }

        int mid = (start + end) / 2;
        if (idx <= mid)
            updateTree(idx, val, start, mid, 2 * treeNode);
        else
            updateTree(idx, val, mid + 1, end, 2 * treeNode + 1);

        if (tree[2 * treeNode].minVal < tree[2 * treeNode + 1].minVal) {
            tree[treeNode].minVal = tree[2 * treeNode].minVal;
            tree[treeNode].index = tree[2 * treeNode].index;
        } else {
            tree[treeNode].minVal = tree[2 * treeNode + 1].minVal;
            tree[treeNode].index = tree[2 * treeNode + 1].index;
        }
    }

    Node query(int left, int right, int start, int end, int treeNode) {
        // Completely outside the range
        if (start > right || end < left) {
            Node result;
            return result;
        }

        // Completely inside the range
        if (start >= left && end <= right) {
            return tree[treeNode];
        }

        // Partially inside and partially outside
        int mid = (start + end) / 2;
        Node ans1 = query(left, right, start, mid, 2 * treeNode);
        Node ans2 = query(left, right, mid + 1, end, 2 * treeNode + 1);

        Node result;
        if (ans1.minVal < ans2.minVal) {
            result.minVal = ans1.minVal;
            result.index = ans1.index;
        } else {
            result.minVal = ans2.minVal;
            result.index = ans2.index;
        }

        return result;
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, n - 1, 1);
    }

    void update(int idx, int val) {
        updateTree(idx, val, 0, n - 1, 1);
    }

    pair<int, int> getMinInRange(int left, int right) {
        Node result = query(left, right, 0, n - 1, 1);
        return make_pair(result.minVal, result.index);
    }
};

int main() {
    vector<int> arr = {1, 3, 2, 7, 9, 11};
    SegmentTree segTree(arr);

    cout << "Minimum value in range [1, 4]: " << segTree.getMinInRange(1, 4).first << " at index " << segTree.getMinInRange(1, 4).second << endl;

    segTree.update(2, 0);

    // minimum value with index 
















    struct Node {
    int sum;

    Node() {
        sum = 0;
    }
};

class SegmentTree {
private:
    vector<Node> tree;
    int n;

    void buildTree(vector<int>& arr, int start, int end, int treeNode) {
        if (start == end) {
            tree[treeNode].sum = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        buildTree(arr, start, mid, 2 * treeNode);
        buildTree(arr, mid + 1, end, 2 * treeNode + 1);

        tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;
    }

    void updateTree(int idx, int val, int start, int end, int treeNode) {
        if (start == end) {
            tree[treeNode].sum = val;
            return;
        }

        int mid = (start + end) / 2;
        if (idx <= mid)
            updateTree(idx, val, start, mid, 2 * treeNode);
        else
            updateTree(idx, val, mid + 1, end, 2 * treeNode + 1);

        tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;
    }

    int query(int left, int right, int start, int end, int treeNode) {
        // Completely outside the range
        if (start > right || end < left) {
            return 0;
        }

        // Completely inside the range
        if (start >= left && end <= right) {
            return tree[treeNode].sum;
        }

        // Partially inside and partially outside
        int mid = (start + end) / 2;
        int ans1 = query(left, right, start, mid, 2 * treeNode);
        int ans2 = query(left, right, mid + 1, end, 2 * treeNode + 1);

        return ans1 + ans2;
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, n - 1, 1);
    }

    void update(int idx, int val) {
        updateTree(idx, val, 0, n - 1, 1);
    }

    int getSumInRange(int left, int right) {
        return query(left, right, 0, n - 1, 1);
    }
};

int main() {
    vector<int> arr = {1, 3, 2, 7, 9, 11};
    SegmentTree segTree(arr);

    cout << "Sum of values in range [1, 4]: " << segTree.getSumInRange(1, 4) << endl;

    segTree.update(2, 5);


    // sum 