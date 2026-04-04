class Order {
private:
    string contents;
    bool takeOut;

public:
    Order(string& contents, bool takeOut) : contents(contents), takeOut(takeOut) {}

    string getOrder() {
        return contents;
    }

    bool isTakeOut() {
        return takeOut;
    }
};

class Cashier {
public:
    Order takeOrder(string& contents, bool takeOut) {
        return Order(contents, takeOut);
    }
};

class Food {
private:
    string contents;

public:
    Food(string order) : contents(order) {}

    string getFood() {
        return contents;
    }
};

class Chef {
public:
    Food prepareFood(Order& order) {
        return Food(order.getOrder());
    }
};

class PackagedFood : public Food {
public:
    PackagedFood(Food& food) : Food(food.getFood() + " in a bag") {}
};

class KitchenStaff {
public:
    PackagedFood packageOrder(Food& food) {
        return PackagedFood(food);
    }
};

class DriveThruFacade {
private:
    Cashier cashier;
    Chef chef;
    KitchenStaff kitchenStaff;

public:
    Food takeOrder(string& orderContents, bool takeOut) {
        Order order = cashier.takeOrder(orderContents, takeOut);
        Food food = chef.prepareFood(order);
        return order.isTakeOut() ? kitchenStaff.packageOrder(food) : food; 
    }
};
