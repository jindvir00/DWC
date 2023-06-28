import java.util.Scanner;

/**
 * problem2
 */

class Room {
    private String name;
    private String description;
    private String item;
    private String exit;

    public Room(String name, String description, String item, String exit) {
        this.name = name;
        this.description = description;
        this.item = item;
        this.exit = exit;
    }

    public String getName() {
        return name;
    }

    public String getDescription() {
        return description;
    }

    public String getItem() {
        return item;
    }

    public String getExit() {
        return exit;
    }

};

class Game {

    private Room[] rooms;
    private Room currentRoom;
    private boolean gameOver;

    Game() {
        rooms = new Room[3];

        rooms[0] = new Room("Living Room", "You are in dusty living room", "key", "Kitchen");
        rooms[1] = new Room("Kitchen", "You are in spooky kitchen", "knife", "Bedroom");
        rooms[2] = new Room("Bedroom", "You are in creepy bedroom", "flashlight", "Living Room");
        currentRoom = rooms[0];
        gameOver = false;
    }

    public void play() {
        System.out.println("Welcome to the Haunted House!");
        System.out.println("You find yourself in the " + currentRoom.getName());
        System.out.println(currentRoom.getDescription());

        while (!gameOver) {
            System.out.println("--------------------------------------");
            System.out.println("What would you like to do?");
            System.out.println("1. Look around");
            System.out.println("2. Take item");
            System.out.println("3. Go to another room");
            System.out.println("4. Quit the game");

            int choice = getInput();

            switch (choice) {
                case 1:
                    lookAround();
                    break;
                case 2:
                    takeItem();
                    break;
                case 3:
                    goToAnotherRoom();
                    break;
                case 4:
                    quitGame();
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    private int getInput() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your choice: ");
        Integer val = scanner.nextInt();
        scanner.close();

        return val;
    }

    private void lookAround() {
        System.out.println("You look around the room.");
        System.out.println(currentRoom.getDescription());

        if (currentRoom.getItem() != null) {
            System.out.println("You see a " + currentRoom.getItem() + " on the floor.");
        }
    }

    private void takeItem() {
        if (currentRoom.getItem() != null) {
            System.out.println("You take the " + currentRoom.getItem() + ".");
        } else {
            System.out.println("There is no item in this room.");
        }
    }

    private void goToAnotherRoom() {
        System.out.println("You go to another room.");

        String nextRoomName = currentRoom.getExit();
        Room nextRoom = null;

        for (Room room : rooms) {
            if (room.getName().equals(nextRoomName)) {
                nextRoom = room;
                break;
            }
        }

        if (nextRoom != null) {
            currentRoom = nextRoom;
            System.out.println("You are now in the " + currentRoom.getName());
            System.out.println(currentRoom.getDescription());
        } else {
            System.out.println("Invalid exit. Please try again.");
        }
    }

    private void quitGame() {
        gameOver = true;
        System.out.println("Thanks for playing. Goodbye!");
    }
}

public class problem2 {

    public static void main(String[] args) {
        Game game = new Game();
        game.play();

    }
}