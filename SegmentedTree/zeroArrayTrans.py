class segTree:
    def __init__(self,nums):
        self.segTree=[]
        for i in range(0,len(nums)*4):
            self.segTree.append(0)
        self.build(0,len(nums)-1,0,nums)
        print(self.segTree)
    def build(self,segStart,segEnd,currIndex,nums):
        if segStart==segEnd:
            self.segTree[currIndex]=nums[segStart]
            return self.segTree[currIndex]
        mid=(segStart+segEnd)//2
        self.segTree[currIndex]=max(self.build(segStart,mid,currIndex*2+1,nums),self.build(mid+1,segEnd,currIndex*2+2,nums))
        return self.segTree[currIndex]
    def update_array(self,segStart,segEnd,left,right,currIndex,nums):
        if segStart==segEnd:
            if segStart>=left and segEnd<=right:
                self.segTree[currIndex]-=1 
            return 
        mid=(segStart+segEnd)//2 
        if left>=segStart and right<=mid:
            self.update_array(segStart,mid,index,currIndex*2+1,val,nums)
        else: 
            self.update_array(mid+1,segEnd,index,currIndex*2+2,val,nums)
        self.segtree[currIndex]=max(self.segtree[currIndex*2+1],self.segtree[currIndex*2+2])


nums=[10,20,40]
s=segTree(nums)
