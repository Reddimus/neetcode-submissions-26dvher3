class Square {
    double sideLength;

public:
    Square() : sideLength(0) {}

    Square(double sideLength) : sideLength(sideLength) {}

    virtual double getSideLength() {
        return sideLength;
    }
};

class SquareHole {
    double sideLength;

public:
    SquareHole(double sideLength) : sideLength(sideLength) {}

    bool canFit(Square& square) {
        return sideLength >= square.getSideLength();
    }
};

class Circle {
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double getRadius() {
        return radius;
    }
};

class CircleToSquareAdapter : public Square {
    Circle circle;

public:
    CircleToSquareAdapter(Circle& circle)
        : circle(circle) {}

    double getSideLength() override {
        return 2 * circle.getRadius();  // Get diameter
    }
};
