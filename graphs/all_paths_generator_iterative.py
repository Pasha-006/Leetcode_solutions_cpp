class Solution:
    # @param A : integer
    # @param B : list of list of integers
    # @return a list of lists containing all paths
    def solve(self, A, B):
        source = 1
        destination = A
        edges = [[] for _ in range(destination + 1)]
        
        # Build adjacency list
        for i in B:
            edges[i[0]].append(i[1])
        
        # Stack will store (current_node, path)
        stack = [(source, [source])]
        result = []
        print(edges)
        while stack:
            current_node, path = stack.pop()
            
            # If we reach the destination, store the current path
            if current_node == destination:
                result.append(path)
            else:
                # Explore all connected nodes
                for neighbor in edges[current_node]:
                    if neighbor not in path:  # To avoid revisiting nodes in the same path
                        stack.append((neighbor, path + [neighbor]))
        
        # Print all paths found
        print(result)
        
        return result

# Test the code
s1 = Solution()
nodes = 5
B = [
    [1, 4], [2, 1], [4, 3], [4, 5], [2, 3],
    [2, 4], [1, 5], [5, 3], [2, 5], [5, 1],
    [4, 2], [3, 1], [5, 4], [3, 4], [1, 3],
    [4, 1], [3, 5], [3, 2], [5, 2]
]

print(s1.solve(nodes, B))
