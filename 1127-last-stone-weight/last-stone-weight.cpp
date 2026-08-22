class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        // Put all stones into max heap
        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();

            int x = pq.top();
            pq.pop();

            // If weights are different, add the difference back
            if (x != y) {
                pq.push(y - x);
            }
        }

        // If no stone remains, return 0
        if (pq.empty()) {
            return 0;
        }

        return pq.top();
    }
};