package com.spbu.group144.baranovsky.calculator;

import com.spbu.group144.baranovsky.stack.CharStackElement;
import com.spbu.group144.baranovsky.stack.GenericStack;
import com.spbu.group144.baranovsky.stack.IntegerStackElement;
import com.spbu.group144.baranovsky.stack.StackElement;

/** A calculator class used to calculate the integer solution to a string of values and operations.*/
public class Calculator {

    /**
     * Calculates an integer output from a string.
     * @param input A string of numbers and operations.
     * @return Returns an integer solution.
     * @throws NullPointerException NullPointerException is thrown when there is no input.
     */
    public int calculate(String input) throws NullPointerException {
        if (input == null) {
            throw new NullPointerException();
        }
        GenericStack stack = new GenericStack();
        processString(input, stack);
        return calculateOutput(stack);
    }

    private void processString(String input, GenericStack stack) {
        int inputLength = input.length();
        GenericStack operations = new GenericStack();
        for (int i = 0; i < inputLength; i++) {
            if(stack.isEmpty() && !operations.isEmpty()) {
                stack.push(0);
            }
            if (input.charAt(i) == '(') {
                i++;
                int innerBrackets = 0;
                StringBuilder stringBuilder = new StringBuilder();
                while (input.charAt(i) != ')' || innerBrackets > 0) {
                    if (input.charAt(i) == '(') {
                        innerBrackets++;
                    } else if (input.charAt(i) == ')') {
                        innerBrackets--;
                    }
                    stringBuilder.append(input.charAt(i++));
                }
                String subString = stringBuilder.toString();
                GenericStack subStack = new GenericStack();
                processString(subString, subStack);
                GenericStack reversedStack = new GenericStack();
                while (!subStack.isEmpty()) {
                    reversedStack.push(subStack.pop());
                }
                while (!reversedStack.isEmpty()) {
                    stack.push(reversedStack.pop());
                }
            } else if (input.charAt(i) == '*' || input.charAt(i) == '/' || input.charAt(i) == '+' || input.charAt(i) == '-') {
                int priority = findPriority(input.charAt(i));
                while (!operations.isEmpty()) {
                    CharStackElement operation = (CharStackElement) operations.pop();
                    if (findPriority(operation.getCharacter()) < priority) {
                        operations.push(operation);
                        break;
                    }
                    stack.push(operation);
                }
                operations.push(input.charAt(i));
            } else if (input.charAt(i) >= '0' && input.charAt(i) <= '9') {
                StringBuilder stringBuilder = new StringBuilder();
                while (i < inputLength && input.charAt(i) >= '0' && input.charAt(i) <= '9') {
                    stringBuilder.append(input.charAt(i++));
                }
                int value = Integer.parseInt(stringBuilder.toString());
                stack.push(value);
                i--;
            }
        }
        while (!operations.isEmpty()) {
            stack.push(operations.pop());
        }
    }

    private static final int BASE_PRIORITY = 0;

    private int findPriority(final char operation) throws IllegalOperationException {

        if (operation == '+' || operation == '-') {
            return BASE_PRIORITY;
        } else if (operation == '*' || operation == '/') {
            return BASE_PRIORITY + 1;
        } else {
            throw new IllegalOperationException();
        }
    }

    private int calculateOutput(GenericStack stack) throws IllegalArgumentException {
        if (stack.isEmpty()) {
            return 0;
        }
        StackElement top = stack.pop();
        if (top instanceof IntegerStackElement) {
            return ((IntegerStackElement) top).getValue();
        } else if (top instanceof CharStackElement) {
            return performOperation(((CharStackElement) top).getCharacter(), calculateOutput(stack), calculateOutput(stack));
        } else {
            throw new IllegalArgumentException();
        }
    }

    private int performOperation(final char operation, int rhsValue, int lhsValue) throws IllegalOperationException {
        switch (operation) {
            case '+': {
                return lhsValue + rhsValue;
            }
            case '-': {
                return lhsValue - rhsValue;
            }
            case '*': {
                return lhsValue * rhsValue;
            }
            case '/': {
                return lhsValue / rhsValue;
            }
            default: {
                throw new IllegalOperationException();
            }
        }
    }
}
