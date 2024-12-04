
#fidning max in the givne range
class SegmentTree:
    def __init__(self,nums):
        self.segtree=[]
        self.size=len(nums)
    
        for i in range(self.size*4):
            self.segtree.append(0)
        self.build(nums,0,self.size-1,0)
        print(self.segtree)
    def build(self,nums,segStart,segEnd,currIndex):
        if segStart==segEnd:
            self.segtree[currIndex]=nums[segStart]
            return self.segtree[currIndex]
        mid=(segStart+segEnd)//2 
        self.segtree[currIndex]=max(self.build(nums,segStart,mid,currIndex*2+1),self.build(nums,mid+1,segEnd,currIndex*2+2))
        return self.segtree[currIndex]
    def max_In_Range(self,segStart,segEnd,left,right,currIndex):
       
        if segStart>=left and segEnd<=right:
            return self.segtree[currIndex]
        if segStart>right or segEnd<left: 
            return -1
        mid=(segStart+segEnd)//2
        return max(self.max_In_Range(segStart,mid,left,right,currIndex*2+1),self.max_In_Range(mid+1,segEnd,left,right,currIndex*2+2))

    


            
  
class Solution: 
    def solve(self,nums,left,right):
        sgTree=SegmentTree(nums) 
        return sgTree.max_In_Range(0,len(nums)-1,left,right,0); 
if __name__=="__main__":
    s=Solution() 
    nums=[1,4,3,10,6]
    queries=[[2,2]]

    for query in queries: 
        start,end=query[0],query[1]
        print(s.solve(nums,start,end)) 

    


