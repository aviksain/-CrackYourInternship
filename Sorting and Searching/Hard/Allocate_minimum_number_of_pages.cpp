// Without Binary search ------------>>>>>>>>>

class Solution {
private:
    int countStudent(int arr[], int maxPages, int n, int m) {
        int students = 1;
        int pages = 0;
        for (int i = 0; i < n; i++) {
            if (pages + arr[i] <= maxPages) {
                pages += arr[i];
            }
            else {
                students++;
                pages = arr[i];
            }
        }
        return students <= m;
    }
    
public:
    int findPages(int arr[], int n, int m) {
        if(m>n) return -1;
        
        int low = *max_element(arr,arr+n);
        int high = accumulate(arr,arr+n,0);
        
        for(int pages=low; pages<=high; pages++) {
            if(countStudent(arr,pages,n,m)) {
                return pages;
            }
        }
        
        return -1;
    }
};







// With Binary Search ---------------->>>>>>>>>>>>>>



class Solution  {
private:
    bool isPossible(int arr[], int n, int m, int maxPages) {
        int students = 1;
        int pages = 0;
        for (int i = 0; i < n; i++) {
            if (pages + arr[i] <= maxPages) {
                pages += arr[i];
            }
            else {
                students++;
                pages = arr[i];
            }
        }
        return students <= m;
    }
    
public:
    int findPages(int arr[], int n, int m) {
        if(m>n) return -1;
        
        int low = *max_element(arr,arr+n);
        int high = accumulate(arr,arr+n,0);
        
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(arr, n, m, mid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};





