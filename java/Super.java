class Vehicle {
    String type = "Vehicle";

    Vehicle() {
        System.out.println("Vehicle constructor");
    }

    void start() {
        System.out.println("Vehicle is starting");
    }
}

class Car extends Vehicle {
    String type = "Car";

    Car() {
        super();
        System.out.println("Car constructor");
    }

    void start() {
        super.start();
        System.out.println("Car is starting");
    }

    void display() {
        System.out.println("Type from Vehicle class: " + super.type);
        super.start();
    }
}

public class Super {
    public static void main(String[] args) {
        Car myCar = new Car();
        myCar.display();
    }
}
