def find(graph,node):
    if graph[node]<0:
        return node  #parent node
    else:
        return find(graph,graph[node])
        
    


def union(graph,a,b,c,result):
    a=find(graph,a)
    b=find(graph,b)

    if a!=b:
        result.append([a,b,c])
        if graph[a]==graph[b]:
            graph[a]+=graph[b]
            graph[b]=a
        else:
            if graph[a]<graph[b]:
                graph[b]+=graph[a]
                graph[a]=b
            else:
                graph[a]+=graph[b]
                graph[b]=a


G = [
    [0, 1, 4],
    [0, 2, 3],
    [1, 2, 1],
    [1, 3, 2],
    [2, 3, 4],
    [3, 4, 2],
    [4, 5, 6],
    [3, 5, 5]
]

node=5 #no of nodes
result=[]
G=sorted(G,key=lambda x:x[2])
graph=[-1]*(node+1)
for x,y,z in G:
    union(graph,x,y,z,result)

print("Edges in MST:")
total=0
for u, v, w in result:
    print(f"{u} - {v} : weight {w}")
    total +=w
print(f"Total weight of MST IS {total}")
