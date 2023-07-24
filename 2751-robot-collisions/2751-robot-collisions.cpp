class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& heal, string dir) {
        int n=dir.size();
        
        vector<vector<int>>v(n);
        for(int i=0;i<n;i++){
            v[i]={pos[i],heal[i],dir[i]=='R'};
        }
        // dir R means 1
        sort(v.begin(),v.end(),comp);
        stack<vector<int>>st;
        for(auto it:v){
            if(it[2]==1 || st.empty()){
                st.push(it);
            }else{
                while(!st.empty() && st.top()[2]==1 && st.top()[1]<it[1]){st.pop();it[1]--;}
                
                  if(!st.empty() && st.top()[2]==1 && st.top()[1]==it[1]){st.pop();}
            
                else if(st.empty() || st.top()[2]==0){st.push(it);}
                else if(!st.empty()){st.top()[1]--;}
                
            }
        }
        vector<int>ans(n,-1);
      map<int,int>m;
        
        for(int i=0;i<pos.size();i++){
            m[pos[i]]=i;
        }
        while(!st.empty()){
            ans[m[st.top()[0]]]=st.top()[1];
            st.pop();
        }
                vector<int>final;
         for(auto it:ans){
             if(it!=-1)final.push_back(it);
         }       
        return final;
           
    }
};