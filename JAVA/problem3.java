import java.util.Scanner;

public class problem3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a positive integer: ");
        Integer num = sc.nextInt();
        
        System.out.println("Output is:\n");
        for(int i = 1; num >= i; i++){
            for (int j = 1; j <= i; j++) {
                System.out.print(j*i + " ");
            }
            System.out.print("\n");
        }
        sc.close();
    }
}
