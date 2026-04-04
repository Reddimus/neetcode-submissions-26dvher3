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
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        const std::size_t N = pairs.size();
        vector<vector<Pair>> sortHistory(N);

        for (int i = 0; i < N; ++i) {
            int j = i - 1;

            for (int j = i - 1; j >= 0 && pairs[j].key > pairs[j + 1].key; --j)
                swap(pairs[j], pairs[j + 1]);

            sortHistory[i] = vector<Pair>(pairs);
        }
        return sortHistory;
    }
};
