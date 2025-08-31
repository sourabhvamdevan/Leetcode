#define vi vector<int>
#define umvi unordered_map<int,vector<int>>
#define pb push_back
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vi inDegree(numCourses,0);
    umvi adj;
    for(int i=0;i< prerequisites.size(); i++){
adj[prerequisites[i][0]].pb(prerequisites[i][1]);

    }

    for(auto it:adj){
        for(int node: adj[it.first]){
            inDegree[node]++;

        }
    }

    queue<int> q;
    for(int i=0;i<numCourses; i++){
        if(inDegree[i]==0){
            q.push(i);

        }
    }

    int cnt=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cnt++;
        for(int ngbr: adj[node]){
            inDegree[ngbr]--;
            if(inDegree[ngbr]==0){\
            q.push(ngbr);

            
            }
        }
    }


    if(cnt==numCourses){
        return true;

    }


    return false;
    }
};