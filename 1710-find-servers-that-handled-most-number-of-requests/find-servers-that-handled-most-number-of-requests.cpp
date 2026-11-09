class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> freeServers;
        for (int i = 0; i < k; i++) freeServers.insert(i);

        // {finishTime, serverId}, min-heap by finishTime
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> busy;
        vector<int> cnt(k, 0);

        for (int i = 0; i < (int)arrival.size(); i++) {
            int t = arrival[i];

            // Free up servers whose jobs are done by time t
            while (!busy.empty() && busy.top().first <= t) {
                freeServers.insert(busy.top().second);
                busy.pop();
            }

            if (freeServers.empty()) continue;   // request dropped

            auto it = freeServers.lower_bound(i % k);
            if (it == freeServers.end()) it = freeServers.begin();  // wrap around

            int s = *it;
            freeServers.erase(it);
            cnt[s]++;
            busy.push({t + load[i], s});
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> res;
        for (int i = 0; i < k; i++)
            if (cnt[i] == mx) res.push_back(i);
        return res;
    }
};