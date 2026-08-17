class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>>minH;
    priority_queue<int>maxH;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!minH.size() && !maxH.size()) {
            maxH.push(num);
        }

        else if(num > maxH.top()) {
            minH.push(num);
        }

        else {
            maxH.push(num);
        } 
        if (abs((int)minH.size() - (int)maxH.size()) > 1) {
            if(maxH.size() > minH.size()) {
                int temp = maxH.top();
                maxH.pop();
                minH.push(temp);
            }
            else {
                int temp = minH.top();
                minH.pop();
                maxH.push(temp);
            }
        }
    }
    
    double findMedian() {
        if(minH.size() == maxH.size()) {
            if(maxH.size() == 0) return 0.0;
            double median = (minH.top() + maxH.top())/2.0;
            return median;
        }
        else {
            if(maxH.size() > minH.size())
                return maxH.top();
            else return minH.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */