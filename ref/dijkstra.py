from heapq import *
import copy
import math  # for math.inf

###############################################################################
def printAdjacency(adjacency: list[ list[int] ]) -> None:
    ''' prints an adjacency matrix in easy-to-read format
    Parameters:
        adjacency: a 2D list of edge weights for a graph
    '''
    print("   ", end = "")
    for col in range(len(adjacency)):
        print(f"{col:>2} ", end = '')
    print()
    for row in range(len(adjacency)):
        print(f"{row:>2} ", end = '')
        for col in range(len(adjacency[row])):
            value = adjacency[row][col]
            if value == math.inf: value = "∞"
            print(f"{value:>2} ", end = '')
        print()
    print('---' * (len(adjacency) + 1))

###############################################################################
def dijkstra(adjacency: list[ list[int] ], start: int, dest: int) -> float:
    ''' implements Dijkstra's algorithm on the graph represented by the given
        2D adjacency matrix, finding the shortest path from vertex with index
        start to vertex with index dest, returning the cost/distance of that
        shortest path
    Args:
        adjacency: a 2D adjacency matrix representing the graph, with entries
                    corresponding to edge weights
        start: the index (between 0 and # vertices - 1) of the origin
        dest:  the index (between 0 and # vertices - 1) of the destination
    Returns:
        the length of the shortest path from start to dest
    '''
    # YOUR CODE GOES HERE
    pass

def main():
    num_vertices = 6
    # build a 2D adjacency matrix for 6 vertices, with undirected edges
    # having weights shown below
    adj = [[math.inf] * num_vertices for i in range(num_vertices)]
    adj[0][1] = adj[1][0] = 7
    adj[0][3] = adj[3][0] = 2
    adj[1][2] = adj[2][1] = 2
    adj[1][4] = adj[4][1] = 3
    adj[2][5] = adj[5][2] = 4
    adj[3][4] = adj[4][3] = 1
    adj[4][5] = adj[5][4] = 10

    printAdjacency(adj)
    start = input("Enter a starting vertex ('q' to quit): ")
    while len(start) > 0 and start[0].lower() != 'q':
        end = input("Enter a destination vertex ('q' to quit): ")
        if len(end) > 0 and end[0].lower() == 'q': break
        try:
            start = int(start)
            end   = int(end)
            if 0 <= start < num_vertices and \
               0 <= end   < num_vertices:
                distance = dijkstra(adj, start, end)
                print(f"The shortest path from {start} to {end} is length {distance}")
            else:
                print(f"Invalid indices: {start}, {end}")
        except:
            pass
        start = input("Enter a starting vertex ('q' to quit): ")
 
if __name__ == "__main__":
    main()
    
