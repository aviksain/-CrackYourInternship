// Solution 1 (gives TLE) ----------------->>>>>>>>>>>>>>>>

class Solution {
public:
    int missingNumber(int arr[], int n) { 
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<n; i++) {
            pq.push(arr[i]);
        }
        
        while(pq.top() <= 0) pq.pop();
        
        int num = 1;
        
        while(!pq.empty()) {
            if(pq.top() != num) return num;
            num++;
            pq.pop();
        }
        
        return n+1;
    } 
};






// Solution 2 ------------------------>>>>>>>>>>>>>>>>>>>>

class Solution{
public:
    int missingNumber(int arr[], int n) { 
       sort(arr,arr+n);
       int cnt=1;
       for (int i=0; i<n; i++) {
           if (arr[i] == cnt) cnt++;
       }
       return cnt;
    }
};







// Solution 3 ------------------------>>>>>>>>>>>>>>>>>>>>>>>>

class Solution{
    public:
    int missingNumber(int arr[], int n) {
        int ptr=0;
 
        for (int i=0; i<n; i++) {
            if (arr[i] == 1) {
                ptr = 1;
                break;
            }
        }
     
        if (ptr == 0) return 1;
     
        for (int i=0; i<n; i++) {
            if (arr[i]<=0 || arr[i]>n)
                arr[i] = 1;
        }
            
        for (int i=0; i<n; i++) {
            arr[(arr[i]-1) % n] += n;
        }
            
        for (int i=0; i<n; i++) {
            if (arr[i]<=n) {
                return i+1;
            }
        }
        
        return n+1;
    }
};







