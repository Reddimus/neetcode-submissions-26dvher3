class Solution {
public:
    // T: O(t)
    // M: O(26) = O(1)
    // Where t is the number of tasks
    int leastInterval(vector<char>& tasks, const int n) {
        std::int16_t task_count[POSSIBLE_TASKS] = {0};
        for (char task : tasks)
            task_count[task - BASE_TASK]++;
        
        std::priority_queue<std::int16_t> pq;
        for (std::int16_t count : task_count)
            if (count)
                pq.push(count);
        
        int time = 0;
        std::queue<std::pair<std::int16_t, int>> q; // {count, time}
        while (!pq.empty()|| !q.empty()) {
            ++time;

            // Move every task whose cooldown has finished back into the heap
            while (!q.empty() && q.front().second <= time) {
                pq.push(q.front().first);
                q.pop();
            }

            if (pq.empty()) {
                // No task is available, so jump to the next cooldown completion
                time = q.front().second - 1;
                continue;
            }

            // Run the task with the most remaining occurences
            std::int16_t count = pq.top() - 1;
            pq.pop();

            if (count)
                q.push({count, time + n + 1});
        }
        return time;
    }
private:
    static constexpr std::uint8_t POSSIBLE_TASKS = 26;
    static constexpr char BASE_TASK = 'A';
};
