# Define the graph dimensions
n = 5  # Number of nodes
adj = [[0 for _ in range(n)] for _ in range(n)]  # Adjacency matrix

# Visited and other helper arrays
visited = [False] * n

tin = [-1] * n
low = [-1] * n
timer = 0

# Depth First Search with bridge detection
def dfs(v, p=-1 ) -> None:
    global timer
    visited[v] = True
    tin[v] = low[v] = timer
    timer += 1

    parentSkipped = False
    for to in range(n):
        if adj[v][to] == 0:
            continue  # Skip if there's no edge

        if to == p & parentSkipped == False:
            parentSkipped = True
            continue  # Skip the parent node

        if visited[to]:
            # Update low value for back edges
            low[v] = min(low[v], tin[to])
        else:
            # Recurse for unvisited nodes
            dfs(to, v)
            low[v] = min(low[v], low[to])

            # Check if the edge is a bridge
            if low[to] > tin[v]:
                print("Bridge found:", v, "-", to)

if __name__ == "__main__":
    # Example graph edges (0-indexed)
    edges = [
        (0, 1),
        (0, 2),
        (1, 2),
        (1, 3),
        (3, 4)
    ]

    # Populate the adjacency matrix
    for u, v in edges:
        adj[u][v] = 1
        adj[v][u] = 1

    # Run DFS for each unvisited node
    for i in range(n):
        if not visited[i]:
            dfs(i)
