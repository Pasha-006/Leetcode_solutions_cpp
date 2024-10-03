class Solution:
    # @param A : integer
    # @param B : list of list of integers
    # @return an integer
    def solve(self, A, B): 
        source=1 
        destination=A 
        edges=[]
        for i in range(0,destination+1):
            edges.append(list())
        for i in B: 
            edges[i[0]].append(i[1])
        stack=[]
        print(edges)
        stack.append(1)
        visited=[False for i in range(0,A+1)]
        path=[]
        result=[]
        while len(stack)!=0: 
            current_node=stack.pop()
            print(current_node)
            
            if current_node==A:
                return 1 
            for nodes in edges[current_node]: 
                if visited[nodes]==False: 
                    stack.append(nodes)
                    visited[nodes]=True 
            print(stack)
        return 0
                

s1=Solution() 
nodes=5
B=[]


B.append(list([1, 4]))
B.append(list([2, 1]))
B.append(list([4, 3]))
B.append(list([4, 5]))
B.append(list([2, 3]))
B.append(list([2, 4]))
B.append(list([1, 5]))
B.append(list([5, 3]))
B.append(list([2, 5]))
B.append(list([5, 1]))
B.append(list([4, 2]))
B.append(list([3, 1]))
B.append(list([5, 4]))
B.append(list([3, 4]))
B.append(list([1, 3]))
B.append(list([4, 1]))
B.append(list([3, 5]))
B.append(list([3, 2]))
B.append(list([5, 2]))

print(s1.solve(nodes,B))





  








