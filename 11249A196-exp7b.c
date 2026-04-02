class Edge:
    def __init__(self, u, v, w):
        self.u = u  # start vertex
        self.v = v  # end vertex
        self.w = w  # weight of edge
def find_parent(parent, i):
    if parent[i] == i:
        return i
    return find_parent(parent, parent[i])
def union(parent, rank, x, y):
    xroot = find_parent(parent, x)
    yroot = find_parent(parent, y)
    if rank[xroot] < rank[yroot]:
        parent[xroot] = yroot
    elif rank[xroot] > rank[yroot]:
        parent[yroot] = xroot
    else:
        parent[yroot] = xroot
        rank[xroot] += 1
def kruskal(vertices, edges):
    edges = sorted(edges, key=lambda edge: edge.w)
    parent = []
    rank = []
    for node in range(vertices):
        parent.append(node)
        rank.append(0)
    mst = []  # Store edges of MST
    for edge in edges:
        x = find_parent(parent, edge.u)
        y = find_parent(parent, edge.v)
        if x != y:
            mst.append(edge)
            union(parent, rank, x, y)
    return mst
if __name__ == "__main__":
    vertices = 4  # Number of vertices
    edges = [
        Edge(0, 1, 10),
        Edge(0, 2, 6),
        Edge(0, 3, 5),
        Edge(1, 3, 15),
        Edge(2, 3, 4)
    ]
    mst = kruskal(vertices, edges)
    print("Edges in the Minimum Spanning Tree:")
    for edge in mst:
        print(f"{edge.u} -- {edge.v} == {edge.w}")
