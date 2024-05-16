class MedianFinder
{
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    MedianFinder() {}
    /**
    LeetCode Hard 295. Find Median from Data Stream
    두개의 Heap을 이용하여 실시간으로 중간 값 계산을 최적화할 수 있음.

    max_heap 하나 min_heap 하나를 두고
    두 heap 의 원소 개수의 균형을 맞추어 주면서, 항상 max_heap < min_heap 이
    되도록 한다. 그러면 자연스럽게 max_heap 과 min_heap 의 top 에는 중간 값
    후보들이 유지된다.
    */
    void addNum(int num)
    {

        if (minHeap.empty() || num >= minHeap.top())
        {
            minHeap.push(num);

            if (minHeap.size() - maxHeap.size() > 1)
            {
                // minHeap 에 원소가 더 많은 경우 maxHeap 으로 이동
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        else
        {
            maxHeap.push(num);

            if (maxHeap.size() - minHeap.size() >=
                1)
            { // 원소가 1개 차이일 경우는 항상 min heap 에 하나가 더 많도록 유지
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }

    double findMedian()
    {

        // 원소가 짝수개
        if ((maxHeap.size() + minHeap.size()) % 2 == 0)
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else
        {
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */