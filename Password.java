import java.util.Scanner;

public class Password {
    public static void main(String[] args) {
        System.out.print("Enter password length: ");
        Scanner scanner = new Scanner(System.in);
        int len;
        len = scanner.nextInt();
        System.out.print("Enter number of Passwords: ");
        int number = scanner.nextInt();
        for (int i = 0; i < number; i++) {
            System.out.println(password(len));
        }
        scanner.close();
    }

    public static String password(int length){
        String chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRST1234567890!@#$%^&*()-=+_[]{}|:;,./<?>";
        String s = "";
        for (int i = 0; i < length; i++) {
            s = s.concat(String.valueOf(chars.charAt((int) (Math.random()*chars.length()))));
        }
        return s;
    }
}