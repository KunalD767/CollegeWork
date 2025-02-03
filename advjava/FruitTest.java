class Fruit {

    protected String name;
    protected String taste;
    protected String size;

    public Fruit(String name, String taste, String size) {
        this.name = name;
        this.taste = taste;
        this.size = size;
    }

    public void eat() {
        System.out.println("Fruit: " + name + ", Taste: " + taste);
    }
}

class Apple extends Fruit {
    public Apple(String size) {
        super("Apple", "Sweet", size);
    }

    @Override
    public void eat() {
        System.out.println("Fruit: " + name + ", Taste: " + taste);
    }
}

class Orange extends Fruit {
    public Orange(String size) {
        super("Orange", "Citrus", size);
    }

    @Override
    public void eat() {
        System.out.println("Fruit: " + name + ", Taste: " + taste);
    }
}

public class FruitTest {
    public static void main(String[] args) {
        Fruit apple = new Apple("Medium");
        Fruit orange = new Orange("Large");

        apple.eat();
        orange.eat();
    }
}
