/*
class Solution { //T.C : O(N) ANS S.C: O(N)
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int num : nums){
            if(s.find(num) != s.end()) // check if it alredy exist
               return num;
            s.insert(num); 
        } 
        return 0;
    }
};
*/

//################ slow fast pointer algo ################33
class Solution { //T.C : O(N) ANS S.C: O(1)
public:
    int findDuplicate(vector<int>& arr) {

        int slow = arr[0] ,fast =  arr[0];
        do
        {
         slow = arr[slow]; // +1
         fast = arr[arr[fast]]; //+2

        } while(slow != fast);
        slow = arr[0];
        while(slow != fast){
            slow = arr[slow]; // +1
            fast = arr[fast]; //+2
        }
        return slow;
    }
};
