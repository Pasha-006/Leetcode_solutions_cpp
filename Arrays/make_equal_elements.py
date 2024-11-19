

#https://www.interviewbit.com/problems/make-equal-elements-array/




class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        update_array=[]
        for i in range(0,len(A)):
            update_array.append(dict())
        for i in range(0,len(A)):
            update_array[i][A[i]+B]=0
            update_array[i][A[i]-B]=0
            update_array[i][A[i]]=0
         
          
        for key in update_array[0]:
            flag=1
            for k in range(1,len(A)):
                if key in update_array[k].keys():
                    flag+=1  
            if flag==len(A):
                return 1 
        return 0
                
            
