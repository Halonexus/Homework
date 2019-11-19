package ru.spbu.baranovsky.dmitry;

/** A class that implements a calculator using stacks **/
public class Calculator {
    /**
     * A method that accepts a formatted String and calculates an expression
     * @param input the input String
     * @throws ExpressionFormatException when the input is formatted incorrectly
     * @throws IllegalArgumentException when input contains symbols other than decimal digits, operations, or parentheses
     * @return an integer solution
     */
    public int calculate(String input) {
        checkInput(input);
        return calculateStack(createStack(input));
    }

    private ArrayStack createStack(String input) {
        ArrayStack stack = new ArrayStack();
        processString(input, stack, 0);
        return stack;
    }

    private int calculateStack(ArrayStack stack) {
        int result = 0;
        if (!stack.isEmpty()) {
            String temp = stack.pop();
            if (isOperation(temp.charAt(0))) {
                result = performOperation(temp.charAt(0), calculateStack(stack), calculateStack(stack));
            } else {
                result = Integer.parseInt(temp);
            }
        }
        return result;
    }

    private int performOperation(char operation, int rhv, int lhv) {
        switch (operation) {
            case '+':
                return lhv + rhv;
            case '-':
                return lhv - rhv;
            case '*':
                return lhv * rhv;
            case '/':
                return lhv / rhv;
            default:
                throw new IllegalArgumentException();
        }
    }

    private void checkInput(String input) throws ExpressionFormatException, NullPointerException, IllegalArgumentException {
        if (input == null)
            throw new NullPointerException();
        int length = input.length();
        int bracketBalance = 0;
        boolean previousOperation = true;
        for (int i = 0; i < length; i++) {
            char temp = input.charAt(i);
            if (temp == '(') {
                bracketBalance++;
            } else if (temp == ')') {
                bracketBalance--;
                if (bracketBalance < 0) {
                    throw new ExpressionFormatException();
                }
            } else if (temp >= '0' && temp <= '9') {
                previousOperation = false;
            } else if (isOperation(temp)) {
                if (previousOperation) {
                    throw new ExpressionFormatException();
                }
                previousOperation = true;
            } else {
                throw new IllegalArgumentException();
            }
        }
        if (bracketBalance != 0 || previousOperation) {
            throw new ExpressionFormatException();
        }
    }

    private int processString(String input, ArrayStack stack, int index) {
        ArrayStack secondary = new ArrayStack();
        int length = input.length();
        int shift = 0;
        for (int i = index; i < length; i++) {
            char temp = input.charAt(i);
            if (temp == '(') {
                i = processString(input, stack, i + 1);
            } else if (temp == ')') {
                shift = i;
                break;
            } else if (temp >= '0' && temp <= '9') {
                StringBuilder out = new StringBuilder();
                while (i < length && input.charAt(i) >= '0' && input.charAt(i) <= '9') {
                    out.append(input.charAt(i));
                    i++;
                }
                stack.push(out.toString());
                i--;
            } else if (isOperation(temp)) {
                if (!secondary.isEmpty() && findPriority(secondary.top().charAt(0)) >= findPriority(temp)) {
                    combineStacks(stack, secondary);
                }
                secondary.push(String.valueOf(temp));
            } else {
                throw new IllegalArgumentException();
            }
        }
        combineStacks(stack, secondary);
        return shift;
    }

    private int findPriority(char input) {
        if (input == '+' || input == '-')
            return 0;
        else if (input == '*' || input == '/')
            return 1;
        else throw new IllegalArgumentException();
    }

    private void combineStacks(ArrayStack main, ArrayStack secondary) {
        while (!secondary.isEmpty()) {
            main.push(secondary.pop());
        }
    }

    private boolean isOperation(char input) {
        return input == '+' || input == '-' || input == '*' || input == '/';
    }
}