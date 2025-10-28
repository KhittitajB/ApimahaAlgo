1. The Core Logic
    The Goal: For each query (budget B_i), you need to find the shortest path (in number of edges) from every node s to node 1. Of all those shortest paths, you want to find the one that is the longest.

    The Constraint: For a given query B_i, you are only allowed to use edges whose difficulty D is less than or equal to B_i. This means for each query, you are working with a different, smaller graph.

    The "Aha!" Moment:

    Finding the shortest path from every node s to node 1 sounds slow. You would have to run a BFS from every single node.

    The Trick: Since the paths are undirected (two-way), the shortest path from s to 1 has the exact same length as the shortest path from 1 to s.

    This is much better! For each query, you only need to run one single BFS starting from node 1. This one BFS will find the shortest path from node 1 to all other reachable nodes simultaneously.

    Finding the Answer: After running your single BFS from node 1, you will have a distances array (e.g., distances[i] = 3). You just need to scan this array and find the maximum value in it. That maximum value is your answer.

2. The Algorithm (Step-by-Step)
    Read All Data:

    Read N, M, Q.

    Do not build a graph yet. Instead, store all M edges in a "master list." A struct or tuple is good for this: (u, v, difficulty).

    You need this master list because you have to re-build a different graph for each query.

    Loop Q times (for each query): a. Read the budget B_i for this query. b. Build a temporary graph: * Create an empty adjacency list: vector<vector<int>> adj(N + 1); * Loop through your master list of all M edges. * For each edge (u, v, difficulty): * If difficulty <= B_i, add it to your temporary graph: adj[u].push_back(v); adj[v].push_back(u); c. Run one BFS: * Call your standard bfs function: vector<int> distances = bfs(1, N, adj); * This distances array now holds the shortest path length from node 1 to every other node i. (Unreachable nodes will have -1). d. Find the Maximum Path: * Initialize max_path = 0. * Loop from i = 1 to N. * If distances[i] > max_path, update max_path = distances[i]. e. Output: Print max_path.

    Repeat for the next query.