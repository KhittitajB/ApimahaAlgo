#include <iostream>
#include <vector>
#include <list> // Use list for efficient removal

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Use a std::list for fast O(1) removal
    list<int> cards;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        cards.push_back(val);
    }

    // This iterator will always point to the "current card"
    auto current_iter = cards.begin();

    // Loop for M rounds
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x; // Read this round's target value

        int current_sum = 0;

        // This iterator is used for counting in this round
        auto count_iter = current_iter;

        // Inner counting loop
        while (true) {
            current_sum += *count_iter; // Add card's value

            // Check if we've reached the target
            if (current_sum >= x) {
                // Found the card to discard (the one count_iter points to)

                // .erase() removes the element AND returns an
                // iterator to the element *after* it.
                // This is exactly what the problem requires.
                auto next_iter = cards.erase(count_iter);

                // Handle wrap-around for the new "current card"
                if (next_iter == cards.end()) {
                    next_iter = cards.begin();
                }

                // This is the new current card for the *next* round
                current_iter = next_iter;

                break; // Stop this round
            }

            // If not done, move to the next card
            count_iter++;

            // Handle wrap-around for the *counting* iterator
            if (count_iter == cards.end()) {
                count_iter = cards.begin();
            }
        }
    }

    // Output the remaining cards
    for (int val : cards) {
        cout << val << "\n";
    }

    return 0;
}