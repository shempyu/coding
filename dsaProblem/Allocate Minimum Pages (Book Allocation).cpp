//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages){ // O(n)
        int stu = 1,pages = 0;
        for(int i = 0; i< n; i++){ 
            
            if(arr[i] > maxAllowedPages)
               return false;
               
            if(pages + arr[i] <= maxAllowedPages){
                pages += arr[i];
            }
             else{
                 stu++;
                 pages = arr[i];
             }  
        }
        if(stu > m)
          return false;
        else
          return true;
       
    }
    int findPages(vector<int> &arr, int m) {  // O(logN * n)
        
       
       int sum = 0, n = arr.size();
       
       if(m > n)
         return - 1;
         
       for(int i = 0;i<n;i++){    // O(n)
           sum += arr[i];
       }
       
       int ans = -1;
       int st = 0,end = sum;
       
       while(st <= end){          //O(logN * n)
           int mid = st + (end - st)/2;
           
           if(isValid(arr,n,m,mid)){ // left
               ans = mid;
               end = mid - 1;
           } else{ // right
               st = mid  + 1;
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends