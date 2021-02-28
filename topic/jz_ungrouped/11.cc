class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.empty()) return -1;
        int low = 0;
        int high = numbers.size() - 1;
        int idx = 0;
        while(low < high) {
            auto mid = low + (high - low) / 2;
            auto mid_num = numbers[mid];
            if(mid_num > numbers[high]) {
                low = mid + 1;
            } else if(mid_num < numbers[high]) {
                high = mid;
            } else {
                high--;
            }
        }
        return numbers[low];
    }
};