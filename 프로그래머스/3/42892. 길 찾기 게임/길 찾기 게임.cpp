#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int id, x, y;
    Node *left = nullptr;
    Node *right = nullptr;
    
    Node(int id, int x, int y) : id(id), x(x), y(y) {}
};

class BinaryTree
{
private :
    Node *root = nullptr;
    
    static bool CompareNodes(Node *a, Node *b)
    {
        if(a->y != b->y)
            return a->y > b->y;
        return a->x < b->x;
    }
    
    Node* AddNode(Node *current, Node *newNode)
    {
        if(current == nullptr)
            return newNode;
        
        if(newNode->x < current->x)
            current->left = AddNode(current->left, newNode);
        else
            current->right = AddNode(current->right, newNode);
        
        return current;
    }
    
    void PreOrder(Node *node, vector<int>& traversal)
    {
        if(node == nullptr)
            return;
        
        traversal.push_back(node->id);
        PreOrder(node->left, traversal);
        PreOrder(node->right, traversal);
    }
    
    void PostOrder(Node *node, vector<int>& traversal)
    {
        if(node == nullptr)
            return;
        
        PostOrder(node->left, traversal);
        PostOrder(node->right, traversal);
        traversal.push_back(node->id);
    }
    
public :
    BinaryTree() : root(nullptr) {}
    
    void BuildTree(const vector<vector<int>>& nodeInfo)
    {
        vector<Node*> nodes;
        for(int i = 0; i < nodeInfo.size(); i++)
            nodes.push_back(new Node(i+1, nodeInfo[i][0], nodeInfo[i][1]));
        
        sort(nodes.begin(), nodes.end(), CompareNodes);
        
        for(Node* node : nodes)
            root = AddNode(root, node);
    }
    
    vector<int> GetPreOrderTraversal()
    {
        vector<int> traversal;
        PreOrder(root, traversal);
        
        return traversal;
    }
    
    vector<int> GetPostOrderTraversal()
    {
        vector<int> traversal;
        PostOrder(root, traversal);
        
        return traversal;
    }
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    BinaryTree tree;
    
    tree.BuildTree(nodeinfo);
    vector<int> preOrder = tree.GetPreOrderTraversal();
    vector<int> postOrder = tree.GetPostOrderTraversal();
    
    
    return {preOrder, postOrder};
}