/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
       int maxWater = 0;
       for(int i = 0;i<n;i++){
        for(int j = i+1 ;j<n;j++){
            int w = j - i;
            int h = min(height[i], height[j]);
            int area = w * h;
            maxWater = max(maxWater , area);
        }
       }
       return maxWater;
    }
};
*/
//######### two pointer approach  ########
class Solution {
public:
    
    int maxArea(vector<int>& height) {
        int n = height.size();
       int left = 0,right = n-1;
       int area,w , h;
       int maxWater = 0;

       while(left < right){
        w = right - left;
        h = min(height[left],height[right]);
        area = w * h; 
        maxWater = max(maxWater,area);
        if(height[left] < height[right])
           left++;
        else
           right--;       
       }
       
       return maxWater;
    }
};