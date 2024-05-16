public class Person {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void introduce() {
        System.out.println("Hello, my name is " + this.name + " and I am " + this.age + " years old.");
    }

    public void haveBirthday() {
        this.age++;
        System.out.println("Happy Birthday! Now I am " + this.age + " years old.");
    }

    public static void main(String[] args) {
        Person person1 = new Person("Alice", 25);
        Person person2 = new Person("Bob", 30);
        person1.introduce();
        person2.introduce();
        person1.haveBirthday();
        person2.haveBirthday();
       
    }
}
