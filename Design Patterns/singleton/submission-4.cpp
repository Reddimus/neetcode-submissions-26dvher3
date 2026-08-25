class Singleton {
private:
    std::string value;

    Singleton() {}

public:
    static Singleton* getInstance() {
        static Singleton unique_instance;
        return &unique_instance;
    }

    string getValue() {
        return value;
    }

    void setValue(string &value) {
        this->value = value;
    }
};
