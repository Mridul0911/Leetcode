/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
        Node *dfs(unordered_map<Node*,Node*> &mp,Node *node)
        {
                vector<Node *> neighbour;
                Node *curr=new Node(node->val);
                mp[node]=curr;
                for(auto it:node->neighbors)
                {
                        if(mp.find(it)!=mp.end())
                        {
                                neighbour.push_back(mp[it]);
                        }
                        else
                        {
                             neighbour.push_back(dfs(mp,it));   
                        }
                }
                curr->neighbors=neighbour;
                return curr;
        }
    Node* cloneGraph(Node* node) {
           unordered_map<Node*,Node*> mp;
            if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0)
        {
                return new Node(node->val);
        }
            return dfs(mp,node);
    }
};