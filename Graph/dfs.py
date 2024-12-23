import numpy as np
import pandas as pd
class Graph:
    def __init__(self, adjList:dict):
        self.adjList = adjList
        self.vertices = {v: {"color": "white", "d": None, "pi": None, "f": None} for v in adjList}
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
        self.time += 1
        self.vertices[u]["color"] = "black"
        self.vertices[u]["f"] = self.time
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
        self.time += 1
        self.vertices[u]["color"] = "black"
        self.vertices[u]["f"] = self.time
        print(f"Finish {u}, end time: {self.time}")  # Output node finish info
    
    def transposeGraph(self):
        adjListT = { key: [] for key in self.adjList.keys()}
        for key,neighbors in zip(self.adjList.keys(),self.adjList.values()):
            for neighbor in neighbors:
                adjListT[neighbor].append(key)
        return Graph(adjListT)
    
    def getSCC(self):
        # Step 1: Perform DFS on the original graph to compute finish times
        self.dfs()

        # Step 2: Transpose the graph
        graphT = self.transposeGraph()

        # Step 3: Sort vertices by finish time in descending order
        vertices_df = pd.DataFrame(self.vertices).T
        sorted_vertices = vertices_df.sort_values("f", ascending=False).index.tolist()

        # Step 4: Perform DFS on the transposed graph in the order of sorted_vertices
        graphT.resetVisit()  # Reset visitation state for the transposed graph
        scc = []  # List to hold all strongly connected components

        for vertex in sorted_vertices:
            if graphT.vertices[vertex]["color"] == "white":
                component = []
                graphT._collect_scc(vertex, component)
                scc.append(component)

        return scc
    
    # Helper method for collecting nodes in a single strongly connected component.
    def _collect_scc(self, u, component):
        self.vertices[u]["color"] = "gray"
        component.append(u)

        for v in self.adjList[u]:
            if self.vertices[v]["color"] == "white":
                self._collect_scc(v, component)

        self.vertices[u]["color"] = "black"
    
            
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
adjList_direct = {
    "a": ["b"],
    "b": ["c", "e", "f"],
    "c": ["d", "g"],
    "d": ["c", "h"],
    "e": ["a", "f"],
    "f": ["g"],
    "g": ["f"],
    "h": ["d", "g"],
}

g1 = Graph(adjList_with_cycle)
g2 = Graph(adjList_no_cycle)
g3 = Graph(adjList_direct)

print("Graph with cycle:")
print(g1.isCycle())  # Output: True

print("\nGraph without cycle:")
print(g2.isCycle())  # Output: False
print(g3.getSCC())
