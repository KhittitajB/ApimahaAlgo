#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 100010;

int n, m;
vector<int> adj[MAX_N];
vector<int> edge_weight[MAX_N];  // Store edge weights

void read_input()
{
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cout << "Enter edge (u v weight): ";
    cin >> u >> v >> w;  u--;  v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    edge_weight[u].push_back(w);
    edge_weight[v].push_back(w);
  }
}

// Get edge weight between two nodes
int get_edge_weight(int u, int v) {
  for(int i = 0; i < adj[u].size(); i++) {
    if(adj[u][i] == v) {
      return edge_weight[u][i];
    }
  }
  return -1;  // Edge not found
}

// Standard BFS - returns distances from start node
vector<int> bfs(int start) {
  vector<int> dist(n, -1);
  queue<int> q;
  
  q.push(start);
  dist[start] = 0;
  
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    
    for(int v : adj[u]) {
      if(dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  
  return dist;
}

// BFS with distance limit - will not traverse edge if weight > limit
vector<int> bfs_with_distance_limit(int start, int limit_distance) {
  vector<int> dist(n, -1);
  queue<int> q;
  
  q.push(start);
  dist[start] = 0;
  
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    
    for(int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      int edge_dist = edge_weight[u][i];
      
      // Check if edge distance exceeds limit
      if(edge_dist > limit_distance) {
        continue;  // Skip this edge
      }
      
      if(dist[v] == -1) {
        dist[v] = dist[u] + edge_dist;
        q.push(v);
      }
    }
  }
  
  return dist;
}

// BFS with path tracking and distance limit
vector<int> bfs_with_path_and_limit(int start, int target, int limit_distance) {
  vector<int> dist(n, -1);
  vector<int> parent(n, -1);
  queue<int> q;
  
  q.push(start);
  dist[start] = 0;
  
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    
    if(u == target) break;
    
    for(int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      int edge_dist = edge_weight[u][i];
      
      // Check if edge distance exceeds limit
      if(edge_dist > limit_distance) {
        continue;  // Skip this edge
      }
      
      if(dist[v] == -1) {
        dist[v] = dist[u] + edge_dist;
        parent[v] = u;
        q.push(v);
      }
    }
  }
  
  // Reconstruct path
  vector<int> path;
  if(dist[target] == -1) return path;
  
  int curr = target;
  while(curr != -1) {
    path.push_back(curr);
    curr = parent[curr];
  }
  reverse(path.begin(), path.end());
  
  return path;
}

// BFS level by level with distance limit
vector<vector<int>> bfs_by_levels_with_limit(int start, int limit_distance) {
  vector<vector<int>> levels;
  vector<bool> visited(n, false);
  queue<int> q;
  
  q.push(start);
  visited[start] = true;
  
  while(!q.empty()) {
    int level_size = q.size();
    vector<int> current_level;
    
    for(int i = 0; i < level_size; i++) {
      int u = q.front();
      q.pop();
      current_level.push_back(u);
      
      for(int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        int edge_dist = edge_weight[u][j];
        
        // Check if edge distance exceeds limit
        if(edge_dist > limit_distance) {
          continue;  // Skip this edge
        }
        
        if(!visited[v]) {
          visited[v] = true;
          q.push(v);
        }
      }
    }
    
    levels.push_back(current_level);
  }
  
  return levels;
}

// BFS with condition and distance limit
vector<int> bfs_with_condition_and_limit(int start, bool (*condition)(int), int limit_distance) {
  vector<int> dist(n, -1);
  queue<int> q;
  
  if(!condition(start)) return dist;
  
  q.push(start);
  dist[start] = 0;
  
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    
    for(int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      int edge_dist = edge_weight[u][i];
      
      // Check if edge distance exceeds limit
      if(edge_dist > limit_distance) {
        continue;  // Skip this edge
      }
      
      if(dist[v] == -1 && condition(v)) {
        dist[v] = dist[u] + edge_dist;
        q.push(v);
      }
    }
  }
  
  return dist;
}

// Multi-source BFS with distance limit
vector<int> multi_source_bfs_with_limit(vector<int>& sources, int limit_distance) {
  vector<int> dist(n, -1);
  queue<int> q;
  
  for(int src : sources) {
    q.push(src);
    dist[src] = 0;
  }
  
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    
    for(int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      int edge_dist = edge_weight[u][i];
      
      // Check if edge distance exceeds limit
      if(edge_dist > limit_distance) {
        continue;  // Skip this edge
      }
      
      if(dist[v] == -1) {
        dist[v] = dist[u] + edge_dist;
        q.push(v);
      }
    }
  }
  
  return dist;
}

// Example condition function
bool example_condition(int node) {
  return true;
}

int main()
{
  read_input();
  
  int start, limit;
  cout << "\nStart node: ";
  cin >> start;
  cout << "Distance limit (max edge weight): ";
  cin >> limit;
  
  // Example 1: BFS with distance limit
  cout << "\n=== BFS with Distance Limit ===" << endl;
  vector<int> distances = bfs_with_distance_limit(start, limit);
  for(int i = 0; i < n; i++) {
    if(distances[i] != -1) {
      cout << "Distance to node " << i << ": " << distances[i] << endl;
    } else {
      cout << "Node " << i << ": unreachable (blocked by limit)" << endl;
    }
  }
  
  // Example 2: BFS with path and limit
  int target;
  cout << "\nTarget node: ";
  cin >> target;
  
  cout << "\n=== BFS with Path and Distance Limit ===" << endl;
  vector<int> path = bfs_with_path_and_limit(start, target, limit);
  if(path.empty()) {
    cout << "No path exists within distance limit" << endl;
  } else {
    cout << "Shortest path: ";
    for(int node : path) {
      cout << node << " ";
    }
    cout << "\nTotal distance: " << distances[target] << endl;
  }
  
  // Example 3: BFS by levels with limit
  cout << "\n=== BFS by Levels with Distance Limit ===" << endl;
  vector<vector<int>> levels = bfs_by_levels_with_limit(start, limit);
  for(int i = 0; i < levels.size(); i++) {
    cout << "Level " << i << ": ";
    for(int node : levels[i]) {
      cout << node << " ";
    }
    cout << endl;
  }
  
  return 0;
}