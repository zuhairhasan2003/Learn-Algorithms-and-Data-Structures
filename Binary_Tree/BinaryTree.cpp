#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

class Node{
    int val;
    Node * left;
    Node * right;

    public:
    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }

    static Node * BuildTreePreOrder(vector<int> seq)
    {
        int i = 0;
        return buildTree(seq, i);
    }

    void PreOrderPrint()
    {
        cout << "Pre Order : " << endl;
        preOrderPrint(this);
    }

    void Bfs(Node * head) // O(N)
    {
        cout << "BFS : " << endl;
        queue<Node *> queue;

        queue.push(head);

        while (queue.size() != 0)
        {
            Node * curr = queue.front();
            queue.pop();
            cout << curr->val << "      ";
            
            if(curr->left != NULL)
                queue.push(curr->left);
            
            if(curr->right != NULL)
                queue.push(curr->right);
        }
    }

    void Dfs(Node * head)
    {
        cout << "DFS : " << endl;

        stack<Node *> s;

        s.push(head);

        while (s.size() != 0)
        {
            Node * curr = s.top();
            s.pop();
            cout << curr->val << "      ";
            
            if(curr->right != NULL)
            s.push(curr->right);

            if(curr->left != NULL)
                s.push(curr->left);
        }
        
        cout << endl;
    }

    int height(Node * node)
    {
        if (node == NULL)
            return 0;

        int left = height(node->left);
        int right = height(node->right);

        if(left > right)
            return left + 1;
        
        return right + 1;
    }

    int count(Node * node)
    {
        if(node == NULL)
            return 0;

        return count(node->left) + count(node->right) + 1;
    }

    int Sum(Node * node)
    {
        if (node == NULL)
            return 0;
        
        return Sum(node->left) + Sum(node->right) + node->val;
    }

    bool IsEqual(Node * node1, Node * node2)
    {
        if(node1 == NULL || node2 == NULL) 
            return node1 == node2;

        bool left = IsEqual(node1->left, node2->left);
        bool right = IsEqual(node1->right, node2->right);

        return (node1->val == node2->val) && left && right;
    }

    bool IsSubtree(Node * n1, Node * n2) // is n2 a subtree of n1?
    {
        if(n2 == NULL)
            return true;
        if(n1 == NULL)
            return false;
        
        return IsEqual(n1, n2) || IsSubtree(n1->left, n2) || IsSubtree(n1->right, n2); 
    }

    int Diameter(Node * node)
    {
        int max = 0;
        diameter(node, max);
        return max;
    }

    void TopView(Node * node)
    {
        cout << "Top view of a tree : " ;
        queue<int> toViewDist;
        vector<int> viewedDist;
        queue<Node *> toView;
        int currDist = 0;

        toView.push(node);
        toViewDist.push(currDist);

        Node * currNode = node;

        while (toView.size() != 0)
        {
            currNode = toView.front();
            currDist = toViewDist.front();
            toView.pop();
            toViewDist.pop();
            
            if(std::count(viewedDist.begin(), viewedDist.end(), currDist) <= 0)
            {
                cout << currNode->val << "       ";
                viewedDist.push_back(currDist);
            }

            if(currNode->left != NULL)
            {
                toView.push(currNode->left);
                toViewDist.push(currDist - 1);
            }
            
            if(currNode->right != NULL)
            {
                toView.push(currNode->right);
                toViewDist.push(currDist + 1);
            }
        }

        cout << endl;
    }

    void KthNodes(Node * node, int k)
    {
        if(node == NULL)
            return;
        if(k == 1)
        {
            cout << node->val << "       ";
            return;
        }

        KthNodes(node->left , k-1);
        KthNodes(node->right , k-1);
    }

    void LowestCommonAncestor(Node * node, int p, int q)
    {
        cout << "Lowest common ancestor of " << p << " and " << q << " is : "  << lowestCommonAncestor(node, p , q)->val << endl;
    }

    private:

    Node * lowestCommonAncestor(Node * node, int p, int q)
    {
        if(node == NULL)
            return NULL;

        if(node->val == p || node->val == q)
            return node;
        
        Node * left_lcm = lowestCommonAncestor(node->left, p, q);
        Node * right_lcm = lowestCommonAncestor(node->right, p, q);

        if(left_lcm != NULL && right_lcm != NULL)
            return node;
        else if(left_lcm == NULL)
            return right_lcm;
        return left_lcm;
    }

    int diameter(Node * node, int & max_dia)
    {
        if (node == NULL)
            return 0;
        
        int left_height = diameter(node->left, max_dia);
        int right_height = diameter(node->right, max_dia);
        
        int curr_node_dia = left_height + right_height; 
        
        if(curr_node_dia > max_dia)
            max_dia = curr_node_dia;

        return max(left_height, right_height) + 1;
    }

    static Node * buildTree(vector<int> seq, int & i)               // Time complexity : O(N)
    {
        if(seq[i] == -1 || i >= seq.size()) // base condition
        {
            i++;
            return NULL;
        }

        Node * node = new Node(seq[i]);
        i++;

        node->left = buildTree(seq, i);
        node->right = buildTree(seq, i);

        return node;
    }

    void preOrderPrint(Node * root)
    {
        if(root == NULL)
        {
            return;
        }

        cout << root->val << "      ";
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }

};

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1}; // the data to be inserted into binary tree in preorder seq (root - left - right); -1 indicates null
    vector<int> preorder2 = {1, 2, 9, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1}; // to check if trees are equal

    vector<int> preorder3 = {2, 2, 3, 6, -1, -1, -1, 4, -1, -1, -1}; // to check subtree
    vector<int> preorder4 = {2, 3, -1, -1, 4, -1, -1}; // to check subtree

    vector<int> preorder5 = {1,2,-1,-1,3,4,5,6,-1,-1,-1,-1,7,-1,8,-1,9,-1,-1}; // to check diameter

    Node * root = Node::BuildTreePreOrder(preorder);
    Node * root2 = Node::BuildTreePreOrder(preorder2);
    Node * root3 = Node::BuildTreePreOrder(preorder3);
    Node * root4 = Node::BuildTreePreOrder(preorder4);
    Node * root5 = Node::BuildTreePreOrder(preorder5);

    root->PreOrderPrint();
    cout << endl;
    root->Bfs(root);
    cout << endl;
    root->Dfs(root);

    cout << "Height of the tree : " << root->height(root) << endl;
    cout << "Total number of nodes : " << root->count(root) << endl;
    cout << "Total sum of tree : " << root->Sum(root) << endl;

    cout << "Is tree1 and tree2 same ? " << root->IsEqual(root, root2) << endl;

    cout << "Is tree4 a subtree of tree3 ? " << root->IsSubtree(root3, root4) << endl;

    cout << "Diameter of tree5 : " << root5->Diameter(root5) << endl;

    root5->TopView(root5);

    cout << "3rd level nodes for root5 :      ";
    root5->KthNodes(root5, 3);
    cout << endl;

    root5->LowestCommonAncestor(root5, 6, 9);

    return 0;
}