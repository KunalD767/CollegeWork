import java.util.StringTokenizer;  
public class classA{  
 public static void main(String args[]){  
   StringTokenizer st = new StringTokenizer("String tokenizer is part of java");  
     while (st.hasMoreTokens()) {  
         System.out.println(st.nextToken());  
     }  
   }  
} 
