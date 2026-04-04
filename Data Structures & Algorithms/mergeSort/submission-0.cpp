// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        std::function<void(int, int)> recursiveSort = [&](int l, int r) -> void {
            if (r - l + 1 <= 1)
                return;
            
            int mid = (r + l) / 2;
            recursiveSort(l, mid);
            recursiveSort(mid + 1, r);

            std::vector<Pair> leftSide(pairs.begin() + l, pairs.begin() + mid + 1);
            std::vector<Pair> rightSide(pairs.begin() + mid + 1, pairs.begin() + r + 1);

            // leftSideIndex, rightSideIndex, mainIndex
            int lsi = 0, rsi = 0, i = l;

            // Merge the 2 sorted halves into the original array
            while (lsi < leftSide.size() && rsi < rightSide.size()) {
                if (leftSide[lsi].key <= rightSide[rsi].key)
                    pairs[i++] = leftSide[lsi++];
                else
                    pairs[i++] = rightSide[rsi++];
            }

            // One of the halves will have elements remaining
            while (lsi < leftSide.size())
                pairs[i++] = leftSide[lsi++];
            
            while (rsi < rightSide.size())
                pairs[i++] = rightSide[rsi++];
        };
        
        recursiveSort(0, pairs.size() - 1);
        return pairs;
    }
};
