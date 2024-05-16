class Shape {
    void draw() {
        System.out.println("Drawing a shape");
    }
}

class Circle extends Shape {

    void draw() {
        System.out.println("Drawing a circle");
    }
}

class Square extends Shape {
 
    void draw() {
        System.out.println("Drawing a square");
    }
}

public class Overriding {
    public static void main(String[] args) {
        Shape shape = new Shape();
        Circle circle = new Circle();
        Square square = new Square();

        shape.draw();  
        circle.draw(); 
        square.draw();  
    }
}
