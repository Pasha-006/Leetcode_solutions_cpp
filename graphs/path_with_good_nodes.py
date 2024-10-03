#https://www.interviewbit.com/problems/path-with-good-nodes/
from collections import deque
class Solution:
    # @param A : list of integers
    # @param B : list of list of integers
    # @param C : integer
    # @return an integer
    def solve(self, A, B, C): 
        print("helllp")
        edges=[[] for i in range(A+1)]
        for i in B: 
            edges[i[0]].append(i[1])
        visited=set()
        print(edges)
        visited.add(1)
        queue=deque()
        count+=edges[1]
        queue.append((1,[1],visited,))
        result=[]
        
        while queue: 
            current_node,current_path,visit_list=queue.popleft()
            if not edges[current_node]: 
                result.append(current_path)
            print(current_node)
            
            for neightbours in edges[current_node]:
                if neightbours not in visit_list: 
                    visit_list.add(neightbours) 
                    queue.append((neightbours,current_path+[neightbours],visit_list))
       
            
        print(result)
A= [0, 1, 0, 1, 1, 1]
B = [  [1, 2],
        [1, 5],
        [1, 6],
        [2, 3],
        [2, 4]
     ]
s=Solution()
c=1 
s.solve(A,B,c)


            
                   

