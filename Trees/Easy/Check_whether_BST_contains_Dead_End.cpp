// Solution 1 (Using two sets) -------------------->>>>>>>>>>>>>>

void storeNodes(Node *root, set<int>& nonLeafNodes, set<int>& leafNodes) {
    if(!root) return;
    
    if(!root->left && !root->right) {
        leafNodes.insert(root->data);
        return;
    }
    nonLeafNodes.insert(root->data);
    storeNodes(root->left,nonLeafNodes,leafNodes);
    storeNodes(root->right,nonLeafNodes,leafNodes);
}

bool isDeadEnd(Node *root) {
    set<int> nonLeafNodes;
    set<int> leafNodes;
    
    nonLeafNodes.insert(0);
    
    storeNodes(root,nonLeafNodes,leafNodes);
    
    for(auto it : leafNodes) {
        if(nonLeafNodes.find(it+1) != nonLeafNodes.end() 
            && nonLeafNodes.find(it-1) != nonLeafNodes.end()) {
                return true;
            }
    }
    
    return false;
}





// Solution 2 (Using one set) --------------------------->>>>>>>>>>>>>>>>>>>>>>>


void storeNodes(Node *root, set<int>& st) {
    if(!root) return;
    
    if(!root->left && !root->right) {
        st.insert(root->data);
        return;
    }
    st.insert(root->data);
    storeNodes(root->left,st);
    storeNodes(root->right,st);
}

bool check(Node *root, set<int>& st) {
    if(!root) return false;
    if(!root->left && !root->right) {
        int val = root->data;
        
        int cnt = 0;
        if(st.find(val+1) != st.end()) {
            cnt++;
        }
        if(st.find(val-1) != st.end()) {
            cnt++;
        }
        
        if(cnt == 2) {
            return true;
        }
        else {
            return false;
        }
    }
    
    bool left = check(root->left,st);
    bool right = check(root->right,st);
    
    return left | right;
}

bool isDeadEnd(Node *root) {
    set<int> st;
    st.insert(0);
    storeNodes(root,st);
    return check(root,st);
}





// Solution 3 (Using the range of left and right) ----------------------->>>>>>>>>>>>>>>>>>>>>>>>


bool check(Node *root, int mini, int maxi) {
    if(!root) return false;
    
    if(maxi == mini) return true;

    check(root->left,mini,root->data-1)
    || check(root->right,root->data+1,maxi);
}

bool isDeadEnd(Node *root) {
    return check(root,1,INT_MAX);
}


