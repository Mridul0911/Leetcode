class MedianFinder {
public:
    multiset<int> nums;
    multiset<int>::iterator it = nums.begin();
    bool is_even = true;
        
    MedianFinder() {}
        
    void addNum(int num) {
        nums.insert(num);
        is_even=!is_even;
        if(it==nums.end() || (is_even && (*it)<=num)) it++;
        if(!is_even &&(*it)>num) it--;
    }
    double findMedian() {
        return (!is_even)?*it:(*it+*prev(it))/2.0;
    }
// private:
};