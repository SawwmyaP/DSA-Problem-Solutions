// SlidingWindowMedian.cpp
#include <bits/stdc++.h>
using namespace std;

class SlidingWindowMedian {
private:
    multiset<int> lowerHalf;
    multiset<int> upperHalf;
 
    void balanceHeaps() {
        while (lowerHalf.size() > upperHalf.size() + 1) {
            auto it = prev(lowerHalf.end());
            upperHalf.insert(*it);
            lowerHalf.erase(it);
        }

        while (lowerHalf.size() < upperHalf.size()) {
            auto it = upperHalf.begin(); 
            lowerHalf.insert(*it);
            upperHalf.erase(it);
        }
    }

public:
    vector<double> getMedians(vector<int>& nums, int windowSize) {
        vector<double> medians;

        for (int i = 0; i < nums.size(); i++) {
            if (lowerHalf.empty() || nums[i] <= *prev(lowerHalf.end()))
                lowerHalf.insert(nums[i]);
            else
                upperHalf.insert(nums[i]);

            balanceHeaps();
            if (i >= windowSize) {
                int elementToRemove = nums[i - windowSize];

                if (lowerHalf.find(elementToRemove) != lowerHalf.end())
                    lowerHalf.erase(lowerHalf.find(elementToRemove));
                else
                    upperHalf.erase(upperHalf.find(elementToRemove));

                balanceHeaps();
            }
            if (i >= windowSize - 1) {
                if (windowSize % 2 == 1) {
                    medians.push_back(*prev(lowerHalf.end()));
                } else {
                    double leftMax = *prev(lowerHalf.end());
                    double rightMin = *upperHalf.begin();
                    medians.push_back((leftMax + rightMin) / 2.0);
                }
            }
        }
        return medians;
    }
};

int main() {
    SlidingWindowMedian solver;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<double> result = solver.getMedians(nums, k);
    cout << "Medians: ";
    for (double val : result) {
        cout << val << " ";
    }
    return 0;
}
