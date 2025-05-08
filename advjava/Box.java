public class Box {
    private double width, height, depth;

    public Box(double width, double height, double depth) {
        this.width = width;
        this.height = height;
        this.depth = depth;
    }

    public double getVolume() {
        return width * height * depth;
    }

    public static void main(String[] args) {
        Box box = new Box(5, 10, 3);
        System.out.println("Volume of the Box: " + box.getVolume());
        System.out.println("Kajal Kansal 20914802722");
    }
}
