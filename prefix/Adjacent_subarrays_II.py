#https://leetcode.com/contest/weekly-contest-423/problems/adjacent-increasing-subarrays-detection-ii/submissions/
class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        increase_order=[]
        increase_order.append(1)
        for i in range(1,len(nums)):
            if nums[i]>nums[i-1]:
                increase_order.append(increase_order[-1]+1)
            else: 
                increase_order.append(1)
        print(increase_order)
        max_values=[]
        index=0
        max_values.append(1)
        for i in range(1,len(increase_order)):
            if increase_order[i-1]<increase_order[i]:
                max_values[index]=increase_order[i] 
            else :
                max_values.append(1)
                index+=1 
        print(max_values)
        ans=0 
        if len(max_values)==1:
            return max_values[0]//2
        for i in range(1,len(max_values)):
            if max_values[i]==max_values[i-1]:
                temp=max_values[i]
            else: 
                
                temp=max(max(max_values[i-1],max_values[i])//2,min(max_values[i-1],max_values[i]))
            print(temp)
            if temp>ans:
                ans=temp
        
        if ans==0:
            return 1
       
        return ans
        
                    
       
            
            
                
        