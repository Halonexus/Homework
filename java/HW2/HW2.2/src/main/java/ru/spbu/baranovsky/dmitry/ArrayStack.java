package ru.spbu.baranovsky.dmitry;

import java.util.EmptyStackException;

/** The array based string stack class **/
public class ArrayStack implements Stack {
    private String[] stringArray;
    private int maxLength;
    private int top;

    public ArrayStack(int length) {
        stringArray = new String[length];
        maxLength = length;
        top = 0;
    }

    private static final int DEFAULT_LENGTH = 64;

    public ArrayStack() {
        stringArray = new String[DEFAULT_LENGTH];
        maxLength = DEFAULT_LENGTH;
        top = 0;
    }

    /** The amount by which the array length increases if its limit is reached **/
    private static final int ARRAY_GROWTH = 128;

    /**
     * A method that adds a new element to the stack
     *
     * @param input String that will be added
     */
    public void push(String input) {
        if (top >= maxLength) {
            String[] newStringArray = new String[maxLength + ARRAY_GROWTH];
            System.arraycopy(stringArray, 0, newStringArray, 0, maxLength);
            stringArray = newStringArray;
        }
        stringArray[top++] = input;
    }

    /**
     * A method that removes the top element of the stack
     *
     * @return The top String
     * @throws EmptyStackException if method is used when the stack is empty
     */
    public String pop() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return stringArray[top-- - 1];
    }

    /**
     * A method to check the top element without removing it
     *
     * @return the top element of the stack
     */
    public String top() {
        return stringArray[0];
    }

    /**
     * A method that checks whether the stack is empty
     *
     * @return true if the stack is empty
     */
    public boolean isEmpty() {
        return top == 0;
    }

    /**
     * A method that counts the amount of elements in the stack
     *
     * @return the amount of elements in the stack
     */
    public int numberOfElements() {
        return top;
    }
}
