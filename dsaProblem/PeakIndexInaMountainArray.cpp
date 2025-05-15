class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 0, end = arr.size() - 1;
        
        while (st < end) {
            int mid = st + (end - st) / 2;
            
            // If arr[mid] < arr[mid + 1], the peak must be on the right side
            if (arr[mid] < arr[mid + 1]) {
                st = mid + 1;
            } 
            // Else, the peak is on the left side (including mid)
            else { //arr[mid] >  arr[mid + 1]
                end = mid;
            }
        }
        
        // `st` and `end` converge to the peak index
        return st;
    }
};
