import java.util.*;
import java.io.*;

class JavaLoopsII{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int q=in.nextInt();
        for(int i=0;i<q;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();

            int y = a;
            String[] output = new String[n];
            for(int x = 0; x < n; ++x) {
              y = y + (int)Math.round(Math.pow(2, x)*b);
              output[x] = Integer.toString(y);
            }
            System.out.printf("%s%n", String.join(" ", output));
        }
        in.close();
    }
}
