// Person.java
import java.io.Serializable;
 
class Person implements Serializable {
   private String name;
   private int age;
 
   public Person() {}
 
   // Getter for name
   public String getName() {
       return name;
   }
 
   public void setName(String name) {
       this.name = name;
   }
 
   public int getAge() {
       return age;
   }
 
   public void setAge(int age) {
       if (age > 0) {
           this.age = age;
       } else {
           System.out.println("Age must be positive.");
       }
   }
}
 
// Main.java
public class encapsulation {
   public static void main(String[] args) {
       // Create a Person JavaBean instance
       Person person = new Person();
 
       // Set properties using setters
       person.setName("Kunal");
       person.setAge(20);
 
       // Attempt to set invalid age
       person.setAge(-5);
 
       // Access properties using getters
       System.out.println("Name: " + person.getName());
       System.out.println("Age: " + person.getAge());
   }
}