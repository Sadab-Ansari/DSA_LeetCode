class FrontMiddleBackQueue {
public:
    deque<int> dq;

    FrontMiddleBackQueue() {
    }

    void pushFront(int val) {
        dq.push_front(val);
    }

    void pushMiddle(int val) {

        int mid = dq.size() / 2;

        dq.insert(dq.begin() + mid, val);
    }

    void pushBack(int val) {
        dq.push_back(val);
    }

    int popFront() {

        if (dq.empty())
            return -1;

        int x = dq.front();

        dq.pop_front();

        return x;
    }

    int popMiddle() {

        if (dq.empty())
            return -1;

        int mid = (dq.size() - 1) / 2;

        int x = dq[mid];

        dq.erase(dq.begin() + mid);

        return x;
    }

    int popBack() {

        if (dq.empty())
            return -1;

        int x = dq.back();

        dq.pop_back();

        return x;
    }
};