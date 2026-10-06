class Logger {
public:
    Logger() {
        message_timestamp.reserve(10001); 
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        // If this unique message is the first instance
        // Or this message has been seen and is passed buffered time
        const auto it = message_timestamp.find(message);
        if (it == message_timestamp.end() ||
            timestamp - it->second >= BUFFER) {
            message_timestamp[message] = timestamp;
            return true;
        }  // else the message has previously been seen and is not within buffer
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
