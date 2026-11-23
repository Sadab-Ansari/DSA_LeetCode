class ProductOfNumbers {
    vector<long long> pre{1};   // pre[i] = product of the first i numbers since the last 0
public:
    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) pre = {1};          // start over: everything before is cut off by the 0
        else pre.push_back(pre.back() * num);
    }

    int getProduct(int k) {
        int n = pre.size();
        if (k >= n) return 0;             // the last k numbers include a 0
        return pre[n - 1] / pre[n - 1 - k];
    }
};