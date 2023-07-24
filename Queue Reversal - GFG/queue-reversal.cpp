//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
class Solution
{
    private:
    void recursion(queue<int> &q){
        if(q.size() == 0) return;
        int temp = q.front();
        q.pop();
        recursion(q);
        q.push(temp);
    }    
    public:
    queue<int> rev(queue<int> q)
    {
        // add code here.
        if(q.size() <= 1 ) return q;
        recursion(q);
        return q;
    }
};


//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends