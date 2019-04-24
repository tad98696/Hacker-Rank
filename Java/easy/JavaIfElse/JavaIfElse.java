import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class JavaIfElse {



    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int N = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        scanner.close();

        if(N%2 == 1) {
          System.out.println("Weird");
        } else if(N%2 == 0) {
          if(2 <= N && N <= 5) {
            System.out.println("Not Weird");
          } else if(6 <= N && N <= 20) {
            System.out.println("Weird");
          } else if(N > 20) {
            System.out.println("Not Weird");
          }
        }
    }
}
