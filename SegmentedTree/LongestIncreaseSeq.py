class segTree:
    def __init__(self,nums):
        self.segTree=[]
        for i in range(0,len(nums)*2500):
            self.segTree.append(0)
        self.build(0,len(nums)-1,0,nums)
    
    def build(self,segStart,segEnd,currIndex,nums):
        if segStart==segEnd:
            self.segTree[currIndex]=0 
            return self.segTree[currIndex]
        mid=(segStart+segEnd)//2 
        self.segTree[currIndex]=self.build(segStart,mid,currIndex*2+1,nums)+self.build(mid+1,segEnd,currIndex*2+2,nums)
        return self.segTree[currIndex]
    def updateValue(self,segStart,segEnd,currIndex,index):
        if segStart==segEnd:
            self.segtree[currIndex]+=1
            return 
        mid=(segStart+segEnd)//2 
        if index>=segStart and index<=mid:
            self.update_array(segStart,mid,index,currIndex*2+1,index)
        else: 
            self.update_array(mid+1,segEnd,index,currIndex*2+2,index)
        self.segtree[currIndex]=max(self.segtree[currIndex*2+1],self.segtree[currIndex*2+2])
    def maxInRange(self,segStart,segEnd,currIndex,left,right):
        if segStart<=left and segEnd<=right:
            return self.segTree[currIndex]
        if segStart>right or segEnd<left:
            return  0 
        mid=(segStart+segEnd)//2 
        return max(self.maxInRange(segStart,mid,currIndex*2+1,left,right),self.maxInRange(mid+1,segEnd,currIndex*2+2,left,right))
    


nums=[10,9,2,5,3,7,101,18]
s=segTree(nums)
num2=nums 
num2.sort()
for i in range(0,len(nums)):
    print(s.maxInRange(0,len(nums)-1,0,0,7))
    s.updateValue(0,len(nums)-1,0,i) 
    

