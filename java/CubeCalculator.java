public class CubeCalculator {
    public static void main(String[] args) {
        int number = 5;
        int cubeResult = calculateCube(number);
        System.out.println("The cube of " + number + " is: " + cubeResult);
    }

    public static int calculateCube(int num) {
        return num * num * num;
    }
}
