class NumArray:

    def __init__(self, nums: List[int]):
        self.segmented_tree=[]
        self.nums=nums
        self.size=len(nums)
        for i in range(0,len(nums)*4):
            self.segmented_tree.append(0)
        self.build(nums,0,self.size-1,0)
        
        

    def build(self,nums,start,end,currIndex):
        if start==end:
        
            self.segmented_tree[currIndex]=nums[start]
            return self.segmented_tree[currIndex]
        
        mid=(start+end)//2 
        self.segmented_tree[currIndex]=self.build(nums,start,mid,2*currIndex+1)+self.build(nums,mid+1,end,2*currIndex+2)
        return self.segmented_tree[currIndex]
    def sum_range(self,start,end,currIndex,left,right):
        if(start>=left and end<=right):
            return self.segmented_tree[currIndex]
        
        if(start>right or end<left):
            return 0 

        mid=(start+end)//2 
        return self.sum_range(start,mid,2*currIndex+1,left,right)+self.sum_range(mid+1,end,2*currIndex+2,left,right) 


    def update_array(self, start,end,index,diff,currIndex):
        if start>index or end<index:
            return 
        self.segmented_tree[currIndex]+=diff 
        if start!=end:
            mid=(start+end)//2
            self.update_array(start,mid,index,diff,currIndex*2+1)
            self.update_array(mid+1,end,index,diff,currIndex*2+2)




    def update(self, index: int, val: int) -> None:
        self.update_array(0,self.size-1,index,val-self.nums[index],0)
        self.nums[index]=val
        
        
        

    def sumRange(self, left: int, right: int) -> int:
        return self.sum_range(0,self.size-1,0,left,right)
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)