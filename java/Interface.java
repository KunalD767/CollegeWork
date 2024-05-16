interface Shape2 {
    void draw();
}

class Triangle implements Shape2 {
    public void draw() {
        System.out.println("Drawing Triangle");
    }
}

class Rectangle implements Shape2 {
    public void draw() {
        System.out.println("Drawing Rectangle");
    }
}

class Drawing {
    void drawShape(Shape2 shape) {
        shape.draw();
    }
}

public class Interface {
    public static void main(String[] args) {
        Shape2 triangle = new Triangle();
        Shape2 rectangle = new Rectangle();

        Drawing drawing = new Drawing();

        drawing.drawShape(triangle);
        drawing.drawShape(rectangle);
    }
}
