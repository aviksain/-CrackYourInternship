// Solution 1 ----------->>>>>>>>>>>>>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;

        // Iterate through the entire list.
        // For each node, create a deep copy of each node and hash it with it. Store it in the hashmap.
        Node* temp = head;
        while(temp) {
            Node* newNode = new Node(temp->val);
            mp[temp] = newNode;
            temp = temp->next;
        }

        temp = head;

        // Now, again iterate through the given list. For each node, link the deep node present as the hash value of the original node as per original node. 
        // the head of the deep copy list will be the head of hashed value of original node.
        while(temp) {
            Node* curr = mp[temp];

            if(temp->next) 
                curr->next = mp[temp->next];
            else 
                curr->next = NULL;

            if(temp->random) 
                curr->random = mp[temp->random];
            else 
                curr->random = NULL;

            temp = temp->next;
        }

        return mp[head];
    }
};







// Solution 2 ----------------->>>>>>>>>>>>>>>>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while(temp) {
            Node* newNode = new Node(temp->val);
            Node* nxtNode = temp->next;
            temp->next = newNode;
            newNode->next = nxtNode;
            temp = temp->next->next;
        }

        temp = head;

        while(temp) {
            if(temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        
        Node* dummy = new Node(-1);
        Node* itr = head;
        temp = dummy;
        while(itr != NULL) {
            Node* fast = itr->next->next;
            temp->next = itr->next;
            itr->next = fast;
            temp = temp->next;
            itr = fast;
        }
        return dummy->next;
    }
};

