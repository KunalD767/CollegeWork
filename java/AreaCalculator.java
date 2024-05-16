public class AreaCalculator {
    public static double calculateArea(double base, double height) {
        return 0.5 * base * height;
    }

    public static double calculateArea(double radius) {
        return 3.14 * radius * radius;
    }
    public static double calculateArea(double length, double width) {
        return length * width;
    }

    public static void main(String[] args) {
        double triangleArea = calculateArea(5.0, 8.0);
        System.out.println("Area of Triangle: " + triangleArea);

        double circleArea = calculateArea(3.0);
        System.out.println("Area of Circle: " + circleArea);

        double rectangleArea = calculateArea(4.0, 6.0);
        System.out.println("Area of Rectangle: " + rectangleArea);
    }
}
