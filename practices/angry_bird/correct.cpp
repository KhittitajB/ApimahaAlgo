#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    while (num_test_cases--) {
        int p, c;
        cin >> p >> c;

        vector<int> producer_prices(p);
        vector<int> consumer_prices(c);
        set<int> candidate_prices;

        candidate_prices.insert(0);

        for (int i = 0; i < p; ++i) {
            cin >> producer_prices[i];
            candidate_prices.insert(producer_prices[i]);
        }

        for (int i = 0; i < c; ++i) {
            cin >> consumer_prices[i];
            candidate_prices.insert(consumer_prices[i]);
        }

        sort(producer_prices.begin(), producer_prices.end());
        sort(consumer_prices.begin(), consumer_prices.end());

        int min_total_angry = p + c + 1;
        int best_price = 0;

        for (int price : candidate_prices) {
            int current_angry = 0;

            auto it_p = upper_bound(producer_prices.begin(), producer_prices.end(), price);
            current_angry += distance(it_p, producer_prices.end());

            auto it_c = lower_bound(consumer_prices.begin(), consumer_prices.end(), price);
            current_angry += distance(consumer_prices.begin(), it_c);

            if (current_angry < min_total_angry) {
                min_total_angry = current_angry;
                best_price = price;
            }
        }

        cout << best_price << " " << min_total_angry << "\n";
    }

    return 0;
}