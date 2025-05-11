class segTree:
    def __init__(self,nums):
        self.segTree=[]
        for i in range(0,len(nums)*4):
            segTree.append({})
        self.build(0,len(nums)-1,)
    

    def build(self,)