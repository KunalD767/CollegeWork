public class Box {
    private double width;
    private double height;
    private double depth;

    public Box(double width, double height, double depth) {
        this.width = width;
        this.height = height;
        this.depth = depth;
    }

    public double calculateVolume() {
        return width * height * depth;
    }

    public static void main(String[] args) {
        Box myBox = new Box(3.0, 4.0, 5.0);

        System.out.println("Box Dimensions:");
        System.out.println("Width: " + myBox.width);
        System.out.println("Height: " + myBox.height);
        System.out.println("Depth: " + myBox.depth);
        System.out.println("Volume: " + myBox.calculateVolume());
    }
}
