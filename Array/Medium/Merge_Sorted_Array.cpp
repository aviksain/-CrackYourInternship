class Solution {
public:
    void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {
        int idx1 = n-1, idx2 = 0;

        while(idx1 >=0  && idx2 < m) {
            if(arr1[idx1] > arr2[idx2]) {
                swap(arr1[idx1],arr2[idx2]);
                idx1--;
                idx2++;
            }
            else {
                break;
            }
        }

        sort(arr1.begin(),arr1.end()-m);
        sort(arr2.begin(),arr2.end());
        for(int i=n, x=0; i<n+m; i++,x++) {
            arr1[i] = arr2[x];
        }
    }
};







// By using gap method

class Solution {
public:
    void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {
        // len of the imaginary single array:
        int len = n + m;
        
        // Initial gap:
        int gap = (len / 2) + (len % 2);
        
        while (gap > 0) {
            // Place 2 pointers:
            int left = 0;
            int right = left + gap;
            while (right < len) {
                // case 1: left in arr1[]
                //and right in arr2[]:
                if (left < n && right >= n) {
                    int idx1 = left, idx2 = right - n;
                    if (arr1[idx1] > arr2[idx2]) {
                        swap(arr1[idx1], arr2[idx2]);
                    }
                }
                // case 2: both pointers in arr2[]:
                else if (left >= n) {
                    int idx1 = left - n, idx2 = right - n;
                    if (arr2[idx1] > arr2[idx2]) {
                        swap(arr2[idx1], arr2[idx2]);
                    }
                }
                // case 3: both pointers in arr1[]:
                else {
                    if (arr1[left] > arr1[right]) {
                        swap(arr1[left], arr1[right]);
                    }
                }
                left++, right++;
            }
            // break if iteration gap=1 is completed:
            if (gap == 1) break;
        
            // Otherwise, calculate new gap:
            gap = (gap / 2) + (gap % 2);
        }
        
        for(int i=n, x=0; i<n+m; i++,x++) {
            arr1[i] = arr2[x];
        }
    }
};






