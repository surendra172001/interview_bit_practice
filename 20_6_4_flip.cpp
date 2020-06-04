vector<int> Solution::flip(string A) {
    int maxStart = -1, maxEnd = -1, maxSum = 0, start = 0, end = 0, sum = 0;
    for(int i = 0; i < A.length(); i++) {
        if(A[i] == '0') {
            sum += 1;
            if(maxSum < sum) {
                maxSum = sum;
                maxStart = start;
                maxEnd = i;
            }
        } else {
            sum -= 1;
            if(sum < 0) {
                sum = 0;
                start = i+1;
                end = i+1;
            }
        }
    }
    
    if(maxSum <= 0) {
        return vector<int>();
    } else {
        return vector<int>({maxStart+1, maxEnd+1});
    }
}
