import java.util.Scanner;

/**
 * day3
 */
public class problem1 {

    private static final double COKE_PRICE = 1.50;
    private static final double SPRITE_PRICE = 1.25;
    private static final double WATER_PRICE = 1.00;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        displayMenu();

        System.out.print("Enter your choice (1 for Coke, 2 for Sprite, 3 for Water):\n");
        int choice = scanner.nextInt();
        

        double selectedProductPrice = getProductPrice(choice);
        if (selectedProductPrice == 0) {
            System.out.println("Invalid choice. Please try again.");
            return;
        }

        System.out.printf("Selected product price: $%.2f%n", selectedProductPrice);

        System.out.print("Enter the amount of money you are inserting: $");
        double amountInserted = scanner.nextDouble();

        if (amountInserted < selectedProductPrice) {
            System.out.println("Insufficient amount. Please insert more money.");
            return;
        }

        scanner.close();

        double change = amountInserted - selectedProductPrice;
        System.out.printf("Thank you for your purchase! Your change: $%.2f%n", change);
        
    }

    public static void displayMenu() {
        System.out.println("===== Vending Machine Menu =====");
        System.out.println("1. Coke - $1.50");
        System.out.println("2. Sprite - $1.25");
        System.out.println("3. Water - $1.00");
        System.out.println("===============================");
    }

    private static double getProductPrice(int choice) {
        switch (choice) {
            case 1:
                return COKE_PRICE;
            case 2:
                return SPRITE_PRICE;
            case 3:
                return WATER_PRICE;
            default:
                return 0;
        }
    }
}