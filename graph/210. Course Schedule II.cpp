class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree (numCourses,0);
        vector<vector<int>>lst(numCourses,vector<int>());
        for(auto v:prerequisites){
            inDegree[v[0]]++;
            lst[v[1]].push_back(v[0]);
        }
        queue<int> que;
        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i]==0){
                que.push(i);
            }
        }

        vector<int>res;
        while(!que.empty()){
            auto q = que.front();
            que.pop();
            res.push_back(q);

            for(auto l : lst[q]){
                if(--inDegree[l]==0){
                    que.push(l);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>();
    }
};


