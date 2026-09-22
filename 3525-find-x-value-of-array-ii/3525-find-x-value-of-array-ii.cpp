class Solution {
public:
    struct Node {
        int product;
        int pref[5];

        Node() {
            product = 1;
            for (int i = 0; i < 5; i++)
                pref[i] = 0;
        }
    };

    int k;
    vector<Node> tree;

    Node merge(const Node& a, const Node& b) {
        Node res;

        res.product = (a.product * b.product) % k;

        // Prefixes that end inside the left segment
        for (int r = 0; r < k; r++) {
            res.pref[r] += a.pref[r];
        }

        // Prefixes that go through the left segment
        // and continue into the right segment
        for (int r = 0; r < k; r++) {
            int newRemainder = (a.product * r) % k;
            res.pref[newRemainder] += b.pref[r];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {

        if (l == r) {
            int rem = nums[l] % k;

            tree[node].product = rem;
            tree[node].pref[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(int node, int l, int r,
                int index, int value) {

        if (l == r) {

            int rem = value % k;

            tree[node] = Node();

            tree[node].product = rem;
            tree[node].pref[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            update(node * 2, l, mid, index, value);
        }
        else {
            update(node * 2 + 1, mid + 1, r, index, value);
        }

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r,
               int ql, int qr) {

        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        if (qr <= mid) {
            return query(node * 2, l, mid, ql, qr);
        }

        if (ql > mid) {
            return query(node * 2 + 1, mid + 1, r, ql, qr);
        }

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums,
                            int k,
                            vector<vector<int>>& queries) {

        this->k = k;

        int n = nums.size();

        tree.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> ans;

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update persists
            update(1, 0, n - 1, index, value);

            // We need prefixes of nums[start ... n-1]
            Node res = query(1, 0, n - 1,
                             start, n - 1);

            ans.push_back(res.pref[x]);
        }

        return ans;
    }
};