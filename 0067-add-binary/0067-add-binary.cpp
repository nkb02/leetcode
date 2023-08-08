class Solution {
public:
    string addBinary(string a, string b) {
        
        int alen = a.size();
        int blen = b.size();
        
        if(alen > blen)
            return addBinary(b, a);
        
        
        string ans = "";
        bool c = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        
        for(int i = 0; i < alen ; i++){
            if(a[i] == '1' && b[i] == '1'){
                if(c == 1){
                    ans.push_back('1');
                    c = 1;
                }
                else{
                    ans.push_back('0');
                    c = 1;
                }
            }
            else if(a[i] == '1' || b[i] == '1'){
                if(c == 1){
                    ans.push_back('0');
                    c = 1;
                }
                else{
                    ans.push_back('1');
                    c = 0;
                }
            }
            else{
                 if(c == 1){
                    ans.push_back('1');
                    c = 0;
                }
                else{
                    ans.push_back('0');
                    c = 0;
                }
            }
        }
        
        if(c == 1){
            int i = alen;
            while(c == 1 && i < blen){
               if(b[i] == '1'){
                   ans.push_back('0');
                   c = 1; 
               }
                else{
                    ans.push_back('1');
                   c = 0;
                }
                
                i++;
            }
            
            
            if(i < blen){
                 while( i < blen){
                     ans.push_back(b[i]);
                     i++;
                 }
            }
            else if (c == 1){
                ans.push_back('1');
            }
        }
        else{
            int i = alen;
             while( i < blen){
                     ans.push_back(b[i]);
                     i++;
                 }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};