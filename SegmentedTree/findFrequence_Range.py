#https://leetcode.com/problems/range-frequency-queries/description/?envType=problem-list-v2&envId=segment-tree


from collections import Counter
class RangeFreqQuery:

    def __init__(self, arr: List[int]):
        self.segmentTree=[]
        self.nums=arr
        for i in range(len(arr)*4):
            self.segmentTree.append(dict({}))
        self.build(0,len(arr)-1,0,arr)
        print(self.segmentTree[0])
        


    def build(self,segStart,segEnd,currIndex,nums):
        if segStart==segEnd: 
            self.segmentTree[currIndex][nums[segStart]]=1
            return self.segmentTree[currIndex]
        mid=(segStart+segEnd)//2  
        self.segmentTree[currIndex]=Counter(self.build(segStart,mid,currIndex*2+1,nums))+Counter(self.build(mid+1,segEnd,currIndex*2+2,nums))
        return self.segmentTree[currIndex]


     
    def findFreq(self,currIndex,start,end,left,right,value):
        if left<=start and right>=end:
            #freq=self.segmentTree[currIndex][value]
            #print(self.segmentTree[currIndex].get(value,0))
            
            return self.segmentTree[currIndex].get(value,0)
        if end<left or start>right:
            return 0 
        mid=(start+end)//2
        return self.findFreq(currIndex*2+1,start,mid,left,right,value)+self.findFreq(currIndex*2+2,mid+1,end,left,right,value)


    def query(self, left: int, right: int, value: int) -> int:
        return self.findFreq(0,0,len(self.nums)-1,left,right,value)

        
        
        


# Your RangeFreqQuery object will be instantiated and called as such:
# obj = RangeFreqQuery(arr)
# param_1 = obj.query(left,right,value)