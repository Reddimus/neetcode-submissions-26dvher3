#include <algorithm>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::map<char, std::int16_t> task_count;
        for (char task : tasks)
            task_count[task]++;
        
        std::vector<std::int16_t> hq;
        hq.reserve(task_count.size());
        for (const auto [_, count] : task_count)
            hq.push_back(count);
        std::make_heap(hq.begin(), hq.end());

        int time = 0;
        std::queue<std::pair<std::int16_t, int>> q; // {count, time}
        while (!hq.empty() || !q.empty()) {
            ++time;

            // Move every task whose cooldown has finished back into the heap
            while (!q.empty() && time >= q.front().second) {
                hq.push_back(q.front().first);
                std::push_heap(hq.begin(), hq.end());
                q.pop();
            }

            // No task is available, so jump time to the next cooldown completion
            if (hq.empty()) {
                time = q.front().second - 1;
                continue;
            }

            // Run the task with the most remaining occurences
            const std::int16_t count = hq.front() - 1;
            std::pop_heap(hq.begin(), hq.end());
            hq.pop_back();
            if (count)
                q.push({count, time + n + 1});
        }
        return time;
    }
};
