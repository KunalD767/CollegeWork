interface Animal {
    void animalSound();
}

class Cat implements Animal {
    public void animalSound() {
        System.out.println("The cat says: meow");
    }
}

class Dog implements Animal {
    public void animalSound() {
        System.out.println("The dog says: woof");
    }
}


public class interfaces {
    public static void main(String[] args) {
        Animal myCat = new Cat();  
        Animal myDog = new Dog();  
        myCat.animalSound();
        myDog.animalSound();
    }
}
