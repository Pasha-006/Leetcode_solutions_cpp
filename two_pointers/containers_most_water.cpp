https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
      int left=0;
        int right=height.size()-1;
        int ans=0;
        while(left<right)
        { 
            int min_=min(height[left],height[right]);
           
            ans=max(ans,min_*(right-left));
            if(min_==height[left])
            {
                left++;
            }
            else
            {
                right--;
            }

        }
        return ans;
    }
};
