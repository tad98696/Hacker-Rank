import java.io.*;
import java.util.*;

public class JavaEndOfFile {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
      Scanner sc = new Scanner(System.in);
      String line;
      int i = 0;
      while(sc.hasNext()) {
        line = sc.nextLine();
        System.out.printf("%d %s%n", ++i, line);
      }
    }
}
