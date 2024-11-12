#
#https://leetcode.com/contest/weekly-contest-423/problems/adjacent-increasing-subarrays-detection-i/description/

class Solution:
    def hasIncreasingSubarrays(self, nums: list[int], k: int) -> bool:
        size=len(nums)
        if size//k<2:
            return False 
        for i in range(0,size-k*2+1):
            flag=0
            for j in range(i,i+k-1):
                if nums[j+1]<=nums[j]:
                    flag=1 
                    break 
            if flag==0:
                for j in range(i+k,i+k*2-1):
                    if nums[j+1]<=nums[j]:
                        flag=2 
                        break 
                if flag==0:
                    return True
        return False
                    
                    
                    
       
            
            
                
        