#include <queue>
#include <iostream>
using namespace std;
int findNonRepeatingCharacter(string s){
        queue<int> q;
        q.push(0);
        for (int i = 1; i < s.size(); ++i)
        {
            if(!q.empty() && s[q.front()] == s[i]){
                q.pop();
            }else{
                q.push(i);
            }
        }
        if(!q.empty()) return q.front();
        return -1;
}
int main(){
    cout << findNonRepeatingCharacter("aadadaad");
};