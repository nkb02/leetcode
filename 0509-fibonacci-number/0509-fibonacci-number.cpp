class Solution {
public:
   
    int fib(int n) { 
        // 1d dp
         int prev1 = 1;
         int prev2 = 0;
        if(n == 0) return n;
  
          for(int i=2; i<=n; i++){
             int cur = prev1 + prev2;
              
              prev2 =prev1;
              prev1 =cur;
          }
          return prev1;
    }
};