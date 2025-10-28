#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    int num_plateaus = 0;
    int num_swamps = 0;

    // Start at i = 1, and stop before the last element (N-1)
    int i = 1;
    while (i < n - 1) {

        // Find the end of the flat area
        int j = i;
        // Keep moving 'j' forward as long as it's not the last element
        // and the height is the same as the next one.
        while (j < n - 1 && heights[j] == heights[j + 1]) {
            j++;
        }

        // Now, the flat area is from heights[i] to heights[j]

        // We can only check if the *end* of our flat area (j)
        // is not the last element of the array.
        if (j < n - 1) {
            int left_neighbor = heights[i - 1];
            int right_neighbor = heights[j + 1];
            int current_height = heights[i]; // or heights[j]

            // Check for plateau
            if (current_height > left_neighbor && current_height > right_neighbor) {
                num_plateaus += (j - i + 1); // Add the size of the plateau
            }
            // Check for swamp
            else if (current_height < left_neighbor && current_height < right_neighbor) {
                num_swamps += (j - i + 1); // Add the size of the swamp
            }
        }

        // Move 'i' to the next *new* area, right after the flat one we just checked
        i = j + 1;
    }

    cout << num_plateaus << " " << num_swamps << "\n";

    return 0;
}