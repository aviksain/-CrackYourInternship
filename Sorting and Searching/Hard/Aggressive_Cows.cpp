// Without binary search (gives TLE) -------->>>>>>>>

bool isPossible(vector<int> &st, int k, int minDist) {
    int cows=1, last=st[0];
    int n = st.size();
    for(int i=1; i<n; i++) {
        if(st[i]-last >= minDist) {
            cows++;
            last = st[i]; 
        }
        if(cows >= k) {
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &st, int k) {
    sort(st.begin(),st.end());
    int n = st.size();

    int ans = -1;
    for(int i=1; i<=st[n-1]-st[0]; i++) {
        if(isPossible(st,k,i)) {
            ans = max(ans,i);
        }
    }
    return ans;
}




// With binarySearch ------->>>>>>>>>>

bool isPossible(vector<int> &st, int k, int minDist) {
    int cows=1, last=st[0];
    int n = st.size();
    for(int i=1; i<n; i++) {
        if(st[i]-last >= minDist) {
            cows++;
            last = st[i]; 
        }
        if(cows >= k) {
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &st, int k) {
    sort(st.begin(),st.end());
    int n = st.size();

    int ans = -1;
    int low = 1;
    int high = st[n-1]-st[0];
    while(low <= high) {
        int mid = (low+high)/2;
        if(isPossible(st,k,mid)) {
            ans = max(ans,mid);
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return ans;
}




