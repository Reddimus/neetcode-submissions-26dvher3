class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for (int i = arr.size() - 2; i >= 0; --i)
            arr[i] = max(arr[i], arr[i + 1]);
        arr.erase(arr.begin());
        arr.push_back(-1);
        return arr;
    }
};