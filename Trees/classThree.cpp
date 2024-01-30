#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> topView;
    queue<pair<TreeNode<int>* ,int>> q;
    map<int,int>mpp;
    q.push({root,0});
    pair<TreeNode<int>* ,int> pr;
    TreeNode<int>* node;
    int hd;
    while(!q.empty()){
        pr = q.front();
        q.pop();
        node = pr.first;
        hd = pr.second;
        auto it = mpp.find(hd);
        if(it != mpp.end()){

        }else{
            mpp[hd] = node->data;
        }
        if(node->left) q.push({node->left,hd-1});
        if(node->right) q.push({node->right,hd+1});    
    }
   for(auto it=mpp.begin();it!=mpp.end();it++){
       topView.push_back(it->second);

   }
    return topView;
}