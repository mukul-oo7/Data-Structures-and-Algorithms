class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        // floyd warshall algorithm
        vector<vector<long long>> minCost(26, vector<long long>(26, 1e16));

        for(int i=0; i<original.size(); i++){
            minCost[original[i]-'a'][changed[i]-'a']=min((long long)cost[i], minCost[original[i]-'a'][changed[i]-'a']);
        }

        for(int i=0; i<26; i++) minCost[i][i]=0;


        for(int k=0; k<26; k++){
            for(int u=0; u<26; u++){
                for(int v=0; v<26; v++){
                    minCost[u][v] = min(minCost[u][v], minCost[u][k]+minCost[k][v]);
                }
            }
        }

        long long ans=0;
        for(int i=0; i<source.size(); i++){
            if(minCost[source[i]-'a'][target[i]-'a']==1e16) return -1;
            ans+=minCost[source[i]-'a'][target[i]-'a'];
        }

        return ans;
    }
};