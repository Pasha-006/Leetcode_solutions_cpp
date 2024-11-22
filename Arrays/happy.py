class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        left=0
        right=len(A)-1
         
        result=0
        if A[left]>A[right]:
            result=A[left]
            left+=1 
        else:
            result=A[right]
            right-=1 
            
        if right==0:
            return result 
        while B>1: 
            if A[left]>A[right]:
                result=A[left]
                left+=1 
            else:
                result=A[right]
                right-=1  
            B-=1
        return result
            
            



s=Solution()





num=[ -533, -666, -500, 169, 724, 478, 358, -38, -536, 705, -855, 281, -173, 961, -509, -5, 942, -173, 436, -609, -396, 902, -847, -708, -618, 421, -284, 718, 895, 447, 726, -229, 538, 869, 912, 667, -701, 35, 894, -297, 811, 322, -667, 673, -336, 141, 711, -747, -132, 547, 644, -338, -243, -963, -141, -277, 741, 529, -222, -684, 35 ]
print(s.solve(num,48))
print(len(num))