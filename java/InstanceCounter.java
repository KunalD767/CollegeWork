public class InstanceCounter {
    private static int instanceCount = 0;
    public InstanceCounter() {
        instanceCount++;
    }
    public static int getInstanceCount() {
        return instanceCount;
    }
    public static void main(String[] args) {
        InstanceCounter instance1 = new InstanceCounter();
        InstanceCounter instance2 = new InstanceCounter();
        InstanceCounter instance3 = new InstanceCounter();
        System.out.println("Number of instances created: " + InstanceCounter.getInstanceCount());
    }
}
