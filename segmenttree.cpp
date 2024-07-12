vector<int> seg;
void build(vector<int>arr, int index, int start, int end) {
    if (start==end) {
        seg[index] = arr[start];
    } else {
        int mid = (start + end) / 2;
        int left=2*index;
        int right=2*index+1;
        build(arr, left, start, mid);
        build(arr, right, mid+1, end);
        seg[index] = (seg[left]+seg[right]);
    }
}
int sum(int index, int start, int end, int l, int r) {
    if (l > r) 
        return 0;
    if (l == start && r == end) {
        return seg[index];
    }
    
     int mid = (start + end) / 2;
        int left=2*index;
        int right=2*index+1;
        int leftans=sum(left, start, mid, l,min(r,mid));
        int rightans=sum(right, mid+1, end, max(1,mid+1),r);
    return (leftans+rightans);
}
void update(int index, int start, int end, int pos, int val) {
    if (start == end) {
        seg[index] = val;
    } else {
        int mid = (start + end) / 2;
         int left=2*index;
        int right=2*index+1;
        if (pos <= mid)
            update(left, start, mid, pos, val);
        else
            update(right, mid+1, end, pos, val);
            
        seg[index] = (seg[left] + seg[right]);
    }
}

// used to update value and find sum of a range 
//  seg.resize(4*n+1);
//      build(v,1,0,n-1);
//      int s=sum(1,0,n-1,b,c);
//              update(1,0,n-1,b,c);


vector<int> seg;
void build(vector<int>arr, int index, int start, int end) {
    if (start==end) {
        seg[index] = arr[start];
    } else {
        int mid = (start + end) / 2;
        int left=2*index;
        int right=2*index+1;
        build(arr, left, start, mid);
        build(arr, right, mid+1, end);
        seg[index] = min(seg[left],seg[right]);
    }
}
int sum(int index, int start, int end, int l, int r) {
    if (l > r) 
        return INT_MAX;
    if (l == start && r == end) {
        return seg[index];
    }
    
     int mid = (start + end) / 2;
        int left=2*index;
        int right=2*index+1;
        int leftans=sum(left, start, mid, l,min(r,mid));
        int rightans=sum(right, mid+1, end, max(1,mid+1),r);
    return min(leftans,rightans);
}
void update(int index, int start, int end, int pos, int val) {
    if (start == end) {
        seg[index] = val;
    } else {
        int mid = (start + end) / 2;
         int left=2*index;
        int right=2*index+1;
        if (pos <= mid)
            update(left, start, mid, pos, val);
        else
            update(right, mid+1, end, pos, val);
            
        seg[index] = min(seg[left] , seg[right]);
    }
}

// to find min in a range 
// for max change min to max in all functions and intmax to intmin