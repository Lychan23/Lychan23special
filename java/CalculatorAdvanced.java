import java.util.Scanner;

public class CalculatorAdvanced {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the first number: ");
        double num1 = scanner.nextDouble();

        System.out.print("Enter the second number: ");
        double num2 = scanner.nextDouble();

        System.out.print("Enter the operator (+, -, *, /, sqrt, log, x2, ^): ");
        String operator = scanner.next();

        double result;

        switch (operator) {
            case "+":
                result = num1 + num2;
                System.out.println("Result: " + result);
                break;

            case "-":
                result = num1 - num2;
                System.out.println("Result: " + result);
                break;

            case "*":
                result = num1 * num2;
                System.out.println("Result: " + result);
                break;

            case "/":
                if (num2 != 0) {
                    result = num1 / num2;
                    System.out.println("Result: " + result);
                } else {
                    System.out.println("Error: Cannot divide by zero.");
                }
                break;

            case "sqrt":
                result = Math.sqrt(num1);
                System.out.println("Square root of " + num1 + " is: " + result);
                break;

            case "log":
                result = Math.log(num1);
                System.out.println("Logarithm of " + num1 + " is: " + result);
                break;

            case "x2":
                result = Math.pow(num1, 2);
                System.out.println("Square of " + num1 + " is: " + result);
                break;

            case "x()":
                System.out.print("Enter the exponent (max 30): ");
                int exponent = scanner.nextInt();
                if (exponent > 30) {
                    System.out.println("Error: Exponent exceeds the limit of 30.");
                } else {
                    result = Math.pow(num1, exponent);
                    System.out.println(num1 + " raised to the power of " + exponent + " is: " + result);
                }
                break;

            default:
                System.out.println("Error: Invalid operator.");
                break;
        }

        scanner.close();
    }
}
