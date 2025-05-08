import java.io.Serializable;
 
class Person implements Serializable {
   private String name;
   private int age;
 
   // No-argument constructor
   public Person() {}
 
   // Getter for name
   public String getName() {
       return name;
   }
 
   // Setter for name
   public void setName(String name) {
       this.name = name;
   }
 
   public int getAge() {
       return age;
   }
 
   // Setter for age
   public void setAge(int age) {
       this.age = age;
   }
}
 
public class beans {
   public static void main(String[] args) {
       Person person = new Person();
 
       person.setName("Kunal");
       person.setAge(20);
 
       System.out.println("Name: " + person.getName());
       System.out.println("Age: " + person.getAge());
   }
}