class Solution {
public:
struct Node {
    set<int> even;
    set<int> odd;
};

/* -------- Segment Tree -------- */
class SegmentTree {

private:
    int n;
    vector<Node> tree;
    vector<int> arr;

    /* Merge two nodes */
    Node merge(const Node& a, const Node& b) {

        Node res = a;

        for (int x : b.even)
            res.even.insert(x);

        for (int x : b.odd)
            res.odd.insert(x);

        return res;
    }

    /* Build */
    void build(int idx, int l, int r) {

        if (l == r) {

            if (arr[l] % 2 == 0)
                tree[idx].even.insert(arr[l]);
            else
                tree[idx].odd.insert(arr[l]);

            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx + 1, l, mid);
        build(2 * idx + 2, mid + 1, r);

        tree[idx] = merge(
            tree[2 * idx + 1],
            tree[2 * idx + 2]
        );
    }

    /* Query */
    Node query(int idx, int l, int r, int ql, int qr) {

        // No overlap
        if (r < ql || l > qr)
            return Node();

        // Full overlap
        if (l >= ql && r <= qr)
            return tree[idx];

        int mid = (l + r) / 2;

        Node left = query(2 * idx + 1, l, mid, ql, qr);
        Node right = query(2 * idx + 2, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    /* Update */
    void update(int idx, int l, int r, int pos, int val) {

        if (l == r) {

            tree[idx].even.clear();
            tree[idx].odd.clear();

            arr[pos] = val;

            if (val % 2 == 0)
                tree[idx].even.insert(val);
            else
                tree[idx].odd.insert(val);

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * idx + 1, l, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, r, pos, val);

        tree[idx] = merge(
            tree[2 * idx + 1],
            tree[2 * idx + 2]
        );
    }

public:

    /* Constructor */
    SegmentTree(vector<int>& input) {

        arr = input;
        n = arr.size();

        tree.resize(4 * n);

        build(0, 0, n - 1);
    }

    /* Query */
    pair<int,int> rangeQuery(int l, int r) {

        Node res = query(0, 0, n - 1, l, r);

        return {
            (int)res.even.size(),
            (int)res.odd.size()
        };
    }

    /* Update */
    void pointUpdate(int pos, int val) {

        update(0, 0, n - 1, pos, val);
    }
};

    int longestBalanced(vector<int>& nums) {
        int s=0;
        int e=0;
        // map<int,int>cont;
        // int od=0;
        // int ev=0;
        // int ind=0;
        int ans=0;
        // for(int i:nums){
        //     int diff=ev-od;
        //     if(ev==od) ans=max(ans,ind+1);
        //     if(cont[diff]) ans=max(ans,ind-cont[diff]+1);
        //     else{
        //         cont[diff]=ind;
        //     }
        //     ind++;
        // }
        // map<int,int> od,ev;
        // while(e<nums.size()){
        //     if(nums[e]&1) od[nums[e]]++;
        //     else ev[nums[e]]++;
        //     while(od.size()==ev.size()){
        //         ans=max(ans,e-s+1);
        //         if(nums[s]&1)
        //         {
        //             od[nums[s]]--;
        //             if(od[nums[s]]==0) od.erase(nums[s]);
        //         }
        //         else{
        //             ev[nums[s]]--;
        //             if(ev[nums[s]]==0) ev.erase(nums[s]);
        //         }
        //         s++;
        //     }
        //     e++;
        // // }
        // for(int i=0;i<nums.size();i++){
        //     set<int> ev,od;
        //     for(int j=0;i<=i;i++){
        //         if(nums[j]&1) od.insert(nums[j]);
        //         else ev.insert(nums[j]);
        //     }
        //     if(ev.size()==od.size()) ans=max(ans,)
        // }
        // return ans;
        //    SegmentTree st(nums);
        //    int ans=0;
        //    unordered_set<int> evenSet, oddSet;

    // int l = 0;
    // int ans = 0;

    // for (int r = 0; r < nums.size(); r++) {
    //     while (
    //         (nums[r] % 2 == 0 && evenSet.count(nums[r])) ||
    //         (nums[r] % 2 == 1 && oddSet.count(nums[r]))
    //     ) {
    //         if (nums[l] % 2 == 0)
    //             evenSet.erase(nums[l]);
    //         else
    //             oddSet.erase(nums[l]);

    //         l++;
    //     }

    //     if (nums[r] % 2 == 0)
    //         evenSet.insert(nums[r]);
    //     else
    //         oddSet.insert(nums[r]);

    //     ans = max(ans, r - l + 1);
    // }

    // return ans;
    map<int,int> cont;
    for(int i=0;i<nums.size();i++){
        set<int>od,ev;
        for(int j=i;j<nums.size();j++){
            if(nums[j]&1) od.insert(nums[j]);
            else ev.insert(nums[j]);
            if(ev.size()==od.size()) ans=max(ans,j-i+1);
        }
    }
           return ans;
    }
};