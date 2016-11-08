class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> maxH;       // stores the smaller half
    priority_queue<int, vector<int>, greater<int>> minH;    // stores the larger half
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        int maxSize = maxH.size();
        int minSize = minH.size();
        if((maxSize == 0) && (minSize == 0)) {
            maxH.push(num);
        } else if(minSize > maxSize) {
            if(num > minH.top()) {
                maxH.push(minH.top());
                minH.pop();
                minH.push(num);
            } else {
                maxH.push(num);
            }
        } else if(minSize < maxSize) {
            if(num < maxH.top()) {
                minH.push(maxH.top());
                maxH.pop();
                maxH.push(num);
            } else {
                minH.push(num);
            }
        } else {
            if(num < maxH.top()) {
                maxH.push(num);
            } else {
                minH.push(num);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int maxSize = maxH.size();
        int minSize = minH.size();
        if(!maxSize && !minSize) {
            return 0.0;
        }
        if(maxSize == minSize) {
            return (maxH.top() + minH.top()) / 2.0;
        }
        return (maxSize > minSize) ? maxH.top() : minH.top();
    }
};
