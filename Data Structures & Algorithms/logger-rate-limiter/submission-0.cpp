class Logger {
public:
    Logger() {
        message_timestamp.reserve(10001); 
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        // If this unique message is the first instance
        if (message_timestamp.find(message) == message_timestamp.end()) {
            message_timestamp[message] = timestamp;
            return true;
        } 

        if (timestamp >= message_timestamp[message] + BUFFER) {
            message_timestamp[message] = timestamp;
            return true;
        }
        return false;
    }
private:
    static constexpr int BUFFER = 10;
    std::unordered_map<std::string, int> message_timestamp;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
