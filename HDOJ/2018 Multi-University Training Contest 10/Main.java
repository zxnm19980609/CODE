import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T, n;
        T = sc.nextInt();
        while (T-- > 0) {
            n = sc.nextInt();
            BigInteger ans = new BigInteger("1");
            while (n-- > 0)
                ans = ans.multiply(new BigInteger("2"));
            System.out.println(ans.toString());
        }
        sc.close();
    }
}