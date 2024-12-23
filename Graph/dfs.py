import numpy as np

class Graph:
    def __init__(self, adjList):
        self.adjList = adjList
        self.vertices = {v: {"color": "white", "d": None, "pi": None} for v in adjList}
        self.time = 0

    def resetVisit(self):
        for vertex in self.adjList.keys():
            self.vertices[vertex]["color"] = "white"
            self.vertices[vertex]["d"] = None
            self.pi = None
                
        self.time = 0

    def dfs(self):
        self.resetVisit()
        for vertex in self.adjList.keys():
            if self.vertices[vertex]["color"] == "white":
                self._dfs_visit(vertex)

    def _dfs_visit(self, u):
        self.time += 1
        self.vertices[u]["color"] = "gray"
        self.vertices[u]["d"] = self.time
        print(f"Visit {u}, start time: {self.vertices[u]['d']}")  # Output node visit info
        
        for v in self.adjList[u]:
            if self.vertices[v]["color"] == "white":
                self.vertices[v]["pi"] = u
                self._dfs_visit(v)
        
        self.vertices[u]["color"] = "black"
        self.time += 1
        print(f"Finish {u}, end time: {self.time}")  # Output node finish info
    
    def isCycle(self):
        self.resetVisit()
        for vertex in self.adjList.keys():
            if self.vertices[vertex]["color"] == "white":
                if(self._isCycle_visit(vertex,None)):
                    return True
        return False

    def _isCycle_visit(self, u, p):
        self.time += 1
        self.vertices[u]["color"] = "gray"
        self.vertices[u]["d"] = self.time
        print(f"Visit {u}, start time: {self.vertices[u]['d']}")  # Output node visit info
        
        for v in self.adjList[u]:
            if self.vertices[v]["color"] == "gray" and v != p:
                return True
            
            if self.vertices[v]["color"] == "white":
                self.vertices[v]["pi"] = u
                if self._isCycle_visit(v, u):
                    return True
        
        self.vertices[u]["color"] = "black"
        self.time += 1
        print(f"Finish {u}, end time: {self.time}")  # Output node finish info
    
    
            
# Example graph with a cycle
adjList_with_cycle = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A'],
    'D': ['B', 'E'],
    'E': ['B', 'D']
}

# Example graph without a cycle
adjList_no_cycle = {
    'A': ['B', 'C'],
    'B': ['A', 'D'],
    'C': ['A'],
    'D': ['B']
}

g1 = Graph(adjList_with_cycle)
g2 = Graph(adjList_no_cycle)

print("Graph with cycle:")
print(g1.isCycle())  # Output: True

print("\nGraph without cycle:")
print(g2.isCycle())  # Output: False
