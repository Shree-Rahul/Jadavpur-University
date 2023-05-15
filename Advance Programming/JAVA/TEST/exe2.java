public class exe2 {
    public static void main(String[] args) {
        try {
            int d = 0;
            int a =23 / d;
        } catch (ArithmeticException e) {
            System.out.println("Division by zero: " +e);
        }
        System.out.println("After the Catch block.");
    }
}
