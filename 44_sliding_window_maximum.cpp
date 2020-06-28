vector<int> Solution::slidingMaximum(const vector<int> &A, int B)
{
    vector<int> res;
    deque<int> window;
    // data structure where we add and delete elements both from front and back.
    // like a double headed queue.
    for (int i = 0; i < B; i++) {
        // remove the elements that are smaller than the new element from behind.
        while (window.empty() == false && A[window.back()] <= A[i]) {
            window.pop_back();
        }
        // adding new elements
        window.push_back(i);
    }
    for (int i = B; i < A.size(); i++) {
        // Add the head of the queue to the result
        res.push_back(A[window.front()]);
        // make sure there are elements from previous window in the present window
        while (window.empty() == false && window.front() <= i - B) {
            window.pop_front();
        }
        while (window.empty() == false && A[window.back()] <= A[i]) {
            window.pop_back();
        }
        window.push_back(i);
    }
    // add the last element of the head
    res.push_back(A[window.front()]);
    return res;
}
