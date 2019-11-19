package ru.spbu.baranovsky.dmitry;

import java.util.EmptyStackException;

/** The link based string stack class **/
public class LinkedStack implements Stack {
    private StackElement head;

    public LinkedStack() {
        head = null;
    }

    /**
     * A method that adds a new element to the stack
     *
     * @param input String that will be added
     */
    public void push(String input) {
        head = new StackElement(input, head);
    }

    /**
     * A method that removes the top element of the stack
     *
     * @return The top String
     * @throws EmptyStackException if method is used when the stack is empty
     */
    public String pop() {
        if(isEmpty()){
            throw new EmptyStackException();
        }
        String temp = head.data;
        head = head.next;
        return temp;
    }

    /**
     * A method that checks whether the stack is empty
     *
     * @return true if the stack is empty
     */
    public boolean isEmpty() {
        return head == null;
    }

    /**
     * A method that counts the amount of elements in the stack
     *
     * @return the amount of elements in the stack
     */
    public int numberOfElements() {
        StackElement temp = head;
        int amount = 0;
        while (temp != null) {
            amount++;
            temp = temp.next;
        }
        return amount;
    }

    private static class StackElement {//static?
        private String data;
        private StackElement next;

        private StackElement(String data, StackElement next) {
            this.data = data;
            this.next = next;
        }
    }
}
