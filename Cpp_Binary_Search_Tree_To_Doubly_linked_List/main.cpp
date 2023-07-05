class Solution {
    public:
        Node* treeToDoublyList(Node* root) 
        {
            if(!root) return nullptr;
            Node* head = nullptr;
            Node* node = root;
            Node* prev = nullptr;
            stack<Node*> st;
            while(st.size() || node)
            {
                while(node)
                {
                    st.push(node);
                    node = node->left;
                }
                node = st.top(); st.pop();
                if(!prev) 
                    head = node;
                else 
                {
                    prev->right = node;
                    node->left = prev;
                }
                prev = node;
                node = node->right;
            }
            prev->right = head;
            head->left = prev;
            return head;
        }
};