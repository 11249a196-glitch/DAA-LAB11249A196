from collections import defaultdict
class Graph:
    def __init__(self, vertices):
        self.V = vertices  
        self.graph = defaultdict(list)
        self.capacity = {}  
    def add_edge(self, u, v, w):
        self.graph[u].append(v)
        self.graph[v].append(u) 
        self.capacity[(u, v)] = w
        self.capacity[(v, u)] = 0 
    def dfs(self, s, t, visited, parent):
        visited[s] = True
        if s == t:
            return True
        for v in self.graph[s]:
            if not visited[v] and self.capacity[(s, v)] > 0:
                parent[v] = s
                if self.dfs(v, t, visited, parent):
                    return True
        return False
    def ford_fulkerson(self, source, sink):
        parent = [-1] * self.V
        max_flow = 0
        while True:
            visited = [False] * self.V
            if not self.dfs(source, sink, visited, parent):
                break
            path_flow = float('inf')
            s = sink
            while s != source:
                path_flow = min(path_flow, self.capacity[(parent[s], s)])
                s = parent[s]
            v = sink
            while v != source:
                u = parent[v]
                self.capacity[(u, v)] -= path_flow
                self.capacity[(v, u)] += path_flow
                v = parent[v]
            max_flow += path_flow
        return max_flow
if __name__ == "__main__":
    g = Graph(6)
    g.add_edge(0, 1, 16)
    g.add_edge(0, 2, 13)
    g.add_edge(1, 2, 10)
    g.add_edge(2, 1, 4)
    g.add_edge(1, 3, 12)
    g.add_edge(3, 2, 9)
    g.add_edge(2, 4, 14)
    g.add_edge(4, 3, 7)
    g.add_edge(3, 5, 20)
    g.add_edge(4, 5, 4)
    source = 0
    sink = 5
    print("The maximum possible flow is:", g.ford_fulkerson(source, sink))
