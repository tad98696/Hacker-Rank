import java.util.*;

public class JavaStdinAndStdoutI {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        // Complete this line
        int b = scan.nextInt();
        // Complete this line
        int c = scan.nextInt();
        scan.close();

        System.out.println(a);
        // Complete this line
        System.out.println(b);
        // Complete this line
        System.out.println(c);
    }
}
