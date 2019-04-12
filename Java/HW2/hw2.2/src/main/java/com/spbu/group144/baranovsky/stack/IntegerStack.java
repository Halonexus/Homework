package com.spbu.group144.baranovsky.stack;

/** A stack of integers.*/
public class IntegerStack implements Stack {
    protected IntegerStackElement head;

    public IntegerStack() {
        head = null;
    }

    /**
     * Takes out the last added element.
     * @return Returns an IntegerStackElement.
     */
    public IntegerStackElement pop() {
        IntegerStackElement top = head;
        head = (IntegerStackElement) head.next;
        return top;
    }

    /**
     * Takes out the last added element.
     * @return Returns the integer value of the top element.
     */
    public int top() {
        return pop().value;
    }

    /**
     * Adds an integer to the stack.
     * @param element The element that will be added.
     */
    public void push(StackElement element) {
        if (element instanceof IntegerStackElement) {
            element.next = head;
            head = (IntegerStackElement) element;
        }
    }

    /**
     * Checks whether the stack is empty.
     * @return Returns True if the stack is Empty.
     */
    public boolean isEmpty() {
        return head == null;
    }
}
