int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int ans = 1;
        TreeNode* curr;
        while(!q.empty()){
            curr = q.front();
            q.pop();
            if(curr == NULL){
                if(q.size()){
                    q.push(NULL);
                    ans++;
                }
            }else{
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return ans;
    }