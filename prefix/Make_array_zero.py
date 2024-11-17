#https://leetcode.com/contest/weekly-contest-424/problems/make-array-elements-equal-to-zero/description/
class Solution:
    def countValidSelections(self, nums: List[int]) -> int:

        leftCount=[]
        leftCount.append(0)
        for i in range(1,len(nums)):
            leftCount.append(leftCount[-1]+nums[i-1])
        rightCount=[]
        for j in range(0,len(nums)):
            rightCount.append(0)
        for j in range(len(nums)-2,-1,-1):
            rightCount[j]=rightCount[j+1]+nums[j+1]
        length=len(nums)
        print(leftCount)
        print(rightCount)
        count=0
        for i in range(0,len(nums)):
            if nums[i]==0:
                if leftCount[i]==rightCount[i]:
                    count+=2
                elif abs(leftCount[i]-rightCount[i])==1:
                    count+=1
        return count
            
            