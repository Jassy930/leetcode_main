/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        vector<pair<int,int>> vv;
        stringstream ss;
        vv.push_back({0,0});
        for(int i=0; i<S.size(); i++)
        {
            if(S.at(i) == '-')
            {
                int k=1;
                while((i+1)<S.size() && S.at(i+1) == '-')
                {
                    k++;
                    i++;
                }
                vv.push_back({k,0});
                ss<<" ";
            }
            else{
                ss<<S.at(i);
            }
        }
        int s;
        auto i = vv.begin();
        while(ss>>s)
        {
            i->second = s;
            i++;
        }
        
        TreeNode* root = new TreeNode(vv.at(0).second);
        int dep = vv.at(0).first;
        stack<TreeNode*> st;
        TreeNode* r = root;
        int flag = 0;
        
        for(auto i = vv.begin()+1; i!= vv.end(); i++)
        {
            if(i->first == dep+1)
            {
                if(root->left == NULL) root->left = new TreeNode(i->second);
                else if(root->right == NULL) root->right = new TreeNode(i->second);
            }
            if(i->first > dep+1)
            {
                st.push(root);
                if(root->right == NULL)
                root = root->left;
                else root = root->right;
                dep++;
                if(root->left == NULL) root->left = new TreeNode(i->second);
                else if(root->right == NULL) root->right = new TreeNode(i->second);
            }
            if(i->first < dep+1)
            {
                while(i->first < dep+1)
                {root = st.top();
                st.pop();
                dep--;
                 if(dep == 1) flag = 1;
                }
                
                if(root->left == NULL) root->left = new TreeNode(i->second);
                else if(root->right == NULL) root->right = new TreeNode(i->second);
            }
            cout<<i->first<<","<<i->second<<"|";
        }

        return r;
    }
};