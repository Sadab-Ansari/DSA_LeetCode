class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using ll = long long;
        // free servers: (weight, index)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> freeS;
        // busy servers: (freeTime, weight, index)
        priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<>> busy;

        for (int i = 0; i < servers.size(); i++) freeS.push({servers[i], i});

        int m = tasks.size();
        vector<int> ans(m);
        ll t = 0;

        for (int j = 0; j < m; j++) {
            t = max(t, (ll)j);                     // task j arrives at second j

            // release servers that are done by time t
            while (!busy.empty() && get<0>(busy.top()) <= t) {
                auto [ft, w, idx] = busy.top(); busy.pop();
                freeS.push({w, idx});
            }

            // nobody free: jump to the next moment a server frees up
            if (freeS.empty()) {
                t = get<0>(busy.top());
                while (!busy.empty() && get<0>(busy.top()) == t) {
                    auto [ft, w, idx] = busy.top(); busy.pop();
                    freeS.push({w, idx});
                }
            }

            auto [w, idx] = freeS.top(); freeS.pop();
            ans[j] = idx;
            busy.push({t + tasks[j], w, idx});
        }
        return ans;
    }
};