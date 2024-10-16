'''



Problem Description

You are given K sorted integer arrays in a form of 2D integer matrix A of size K X N.

You need to merge them into a single array and return it.



Problem Constraints
1 <= K, N <= 103

0 <= A[i][j] <= 108

A[i][j] <= A[i][j+1]



Input Format
First and only argument is an 2D integer matrix A.



Output Format
Return a integer array denoting the merged array you get after merging all the arrays in A.



Example Input
Input 1:

 A = [  [1, 2, 3]
        [2, 4, 6]
        [0, 9, 10]
     ]


Example Output
Output 1:

 [0, 1, 2, 2, 3, 4, 6, 9, 10]


Example Explanation
Explanation 1:

 You need to merge [1, 2, 3] , [2, 4, 6] and [0, 9, 10]  into a single array
 so the merged array will look like [0, 1, 2, 2, 3, 4, 6, 9, 10]



'''

import heapq
import numpy as np
import random
class Solution: 
    
    @staticmethod
    def solve(matrix):
        
        my_heap=[value for x in matrix for value in x]
        print(len(my_heap))
        heapq.heapify(my_heap) 
        sorted_list=[]
        
        while my_heap: 
            sorted_list.append(heapq.heappop(my_heap))
            
        print(sorted_list)



matrix=[[ random.randint(1,100) for x  in range(3)] for y in range(3)]

print(matrix)
Solution.solve(matrix)
