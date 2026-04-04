class Coffee {
public:
    virtual double getCost() = 0; // Pure virtual function makes this class abstract
};

class SimpleCoffee : public Coffee {
public:
    double getCost() override {
        return 1.1;
    }
};

class CoffeeDecorator : public Coffee {
protected:
    Coffee* decoratedCoffee;

public:
    CoffeeDecorator(Coffee* coffee) : decoratedCoffee(coffee) {}

    double getCost() override {
        return decoratedCoffee->getCost();
    }
};

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    double getCost() override {
        return CoffeeDecorator::getCost() + 0.5;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    double getCost() override {
        return CoffeeDecorator::getCost() + 0.2;
    }
};

class CreamDecorator : public CoffeeDecorator {
public:
    CreamDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    double getCost() override {
        return CoffeeDecorator::getCost() + 0.7;
    }
};
