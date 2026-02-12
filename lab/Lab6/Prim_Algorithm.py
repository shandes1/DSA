
G = {
    'A': {'B': 2, 'C': 3},
    'B': {'A': 2, 'C': 1, 'D': 4},
    'C': {'A': 3, 'B': 1, 'D': 5, 'E': 6},
    'D': {'B': 4, 'C': 5, 'E': 7},
    'E': {'C': 6, 'D': 7}
}

def Prims(G,start):
    visited=[start]
    graph=[]

    while len(visited)<len(G):
        min_weight=float('inf')
        min_edge=None
        for x in visited:
           for neighbour,weight in G[x].items():
               if neighbour not in visited and weight<min_weight:
                min_weight=weight
                min_edge=(x,neighbour)

        if min_edge is None:
           break

        _,v2=min_edge
        graph.append(min_edge)
        visited.append(v2)
    return graph

start='A'
result=Prims(G,start)
     
print("Edges in MST:")
total = 0
for u, v in result:
    w = G[u][v] 
    print(f"{u} - {v} : weight {w}")
    total += w
print(f"Total weight of MST: {total}")
