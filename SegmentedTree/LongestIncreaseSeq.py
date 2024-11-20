class segTree:
    def __init__(self,nums):
        self.segTree=[]
        for i in range(0,nums*4):
            self.segTree.append(0)
        self.build(0,nums,0,nums)
      
    
    def build(self,segStart,segEnd,currIndex,nums):
        if segStart==segEnd:
            self.segTree[currIndex]=0 
            return self.segTree[currIndex]
        mid=(segStart+segEnd)//2 
        self.segTree[currIndex]=self.build(segStart,mid,currIndex*2+1,nums)+self.build(mid+1,segEnd,currIndex*2+2,nums)
        return self.segTree[currIndex] 
    def max_IN_range(self,segStart,segEnd,left,right,currIndex):
        if segStart<=left and segEnd<=right:
            return self.segTree[currIndex]
        if segStart>right or segEnd<left:
            return 0 
        
        mid=(segStart+segEnd)//2 
        return max(self.max_IN_range(segStart,mid,left,right,currIndex*2+1),self.max_IN_range(mid+1,segEnd,left,right,currIndex*2+2))

    def updateValue(self,segStart,segEnd,currIndex,index,maxValue):
        if segStart==segEnd: 
            self.segTree[currIndex]=maxValue
            return 
        mid=(segStart+segEnd)//2 
        if index>=segStart and index<=mid:
            self.updateValue(segStart,mid,currIndex*2+1,index,maxValue)
        else :
            self.updateValue(mid+1,segEnd,currIndex*2+2,index,maxValue)
        self.segTree[currIndex]=max(self.segTree[currIndex*2+1],self.segTree[currIndex*2+2]) 
        return 
        
        
    def maxInRange(self,unqueu_value):
        max_sequence=0
        n=len(unqueu_value)-1
        for i in range(0,len(unqueu_value)):
            curr_max=0
            if unqueu_value[i]==0:
                curr_max=0
            else:
                curr_max=self.max_IN_range(0,max(unqueu_value),0,unqueu_value[i]-1,0)
            max_sequence=max(max_sequence,curr_max) 
          
            if curr_max==0:
                self.updateValue(0,n,0,unqueu_value[i],curr_max)
            else : 
                self.updateValue(0,n,0,unqueu_value[i],curr_max+1)

        
        return max_sequence
                

nums=[0,1,0,3,2,3]
max2=max(nums)

s=segTree(max2)
print(s.maxInRange(nums))

