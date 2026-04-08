class Solution {
public:
    int partition(vector<int>& arr, int l, int r){
        int p = l + rand() % (r - l + 1);
        swap(arr[l], arr[p]);
        
        int pivot = arr[l];
        int i = l + 1;
        int j = r;
        
        while (i <= j) {
            while (i <= j && arr[i] < pivot) {
                i++;
            }
            while (i <= j && arr[j] > pivot) {
                j--;
            }
            
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        
        // Place the pivot in its final, sorted position
        swap(arr[l], arr[j]);
        return j;
    }
    
    void qs(vector<int>& arr, int l, int r){
        if (l < r) {
            int p = partition(arr, l, r);
            qs(arr, l, p - 1);
            qs(arr, p + 1, r);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        srand(time(NULL)); 
        qs(nums, 0, nums.size() - 1);
        return nums;
    }
};