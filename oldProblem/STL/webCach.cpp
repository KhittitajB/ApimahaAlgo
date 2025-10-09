#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// template <typename T>
// void printQueueWithoutPop(std::queue<T> q) { // Pass by value to create a copy
//     if (q.empty()) {
//         std::cout << "Queue is empty." << std::endl;
//         return;
//     }

//     std::cout << ": ";
//     size_t originalSize = q.size();

//     for (size_t i = 0; i < originalSize; ++i) {
//         std::cout << q.front() << " ";
//         q.push(q.front()); // Add the front element to the back
//         q.pop();           // Remove the original front element
//     }
//     std::cout << std::endl;
// }

int main(){
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> cache;
    queue<int> q;
    int miss = 0; // miss count

    for (int i = 0; i < m; i++){
        int a;
        cin >> a;
        // check if in cache
        if (cache[a] == 0 or cache.count(a) == 0){ // not in cache
            
            // cout << "MISS" << a << endl;
            miss ++;
            // check if full
            if (q.size() == n){ // full
                int old = q.front();
                q.pop();
                cache[old] = 0; // remove from cache
            }
            // add to cache
            q.push(a);
            cache[a] = 1;
            // printQueueWithoutPop(q);
        }
        // else do nothing

        
    }

    cout << miss;

}