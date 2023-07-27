// Using merge Sort ------------------->>>>>>>>>>>>>>>>>>>

Node* mergeSort(Node* a, Node* b) {
    Node* temp = new Node(0);
    Node* res = temp;
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    
    if(a) temp->bottom = a;
    else temp->bottom = b;
    return res->bottom;
}

Node* flatten(Node *root) {
    if(root == NULL || root->next == NULL) {
        return root;
    }
    
    root->next = flatten(root->next);
    root = mergeSort(root,root->next);
    return root;
}








// Using priority queue  ------------------------->>>>>>>>>>>>>>>>>>>>>>>

// We have joined the linked list using the bottom pointer we can do it with the next pointer as well

Node* flatten(Node* root) {
    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> PQ;
    PQ.push({root->data,root});
    
    Node* dummy = new Node(0);
    Node* temp = dummy;
    
    while(!pq.empty()){
        Node* curr = pq.top().second;
        PQ.pop();
        
        temp->bottom = curr;
        temp = temp->bottom;
    
        if(curr->next) 
            PQ.push({curr->next->data,curr->next});
        if(curr->bottom) 
            PQ.push({curr->bottom->data,curr->bottom});
    }
    
    return dummy->bottom;
}

