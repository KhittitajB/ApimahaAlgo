#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

// A simple structure to hold account information
struct Account {
    int quality; // This is also the cost per token
    int tokens;  // The number of tokens remaining
};

int main() {
    int N, M;
    cin >> N >> M;

    // 1. Store all accounts
    vector<Account> accounts(N);
    for (int i = 0; i < N; ++i) {
        cin >> accounts[i].tokens >> accounts[i].quality;
    }

    // 2. Initialize counters
    long long total_cost = 0;
    int discarded_requests = 0;

    // 3. Main Loop (process each of the M requests)
    for (int i = 0; i < M; ++i) {
        int T, R;
        cin >> T >> R; // T = tokens needed, R = min quality

        // 4. Inner Loop (Find the best account)
        int best_account_index = -1;
        int min_quality_found = INT_MAX; // Cheaper = lower quality

        for (int j = 0; j < N; ++j) {
            // Check the three conditions
            bool quality_ok = (accounts[j].quality >= R);
            bool tokens_ok = (accounts[j].tokens >= T);
            bool is_cheaper = (accounts[j].quality < min_quality_found);

            if (quality_ok && tokens_ok && is_cheaper) {
                // This is our new best candidate
                min_quality_found = accounts[j].quality;
                best_account_index = j;
            }
        }

        // 5. Process the result of the search
        if (best_account_index == -1) {
            // No account was found
            discarded_requests++;
        } else {
            // We found the best account at 'best_account_index'
            // Add to total cost
            total_cost += (long long)T * accounts[best_account_index].quality;
            // Subtract the used tokens
            accounts[best_account_index].tokens -= T;
        }
    }

    // 6. Final Output
    cout << total_cost << "\n";
    cout << discarded_requests << "\n";

    return 0;
}