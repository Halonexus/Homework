package com.spbu.group144.baranovsky.stack;

/**
 * This class consists of objects that are stacks of StackElements.
 */
public class GenericStack implements Stack {
    protected StackElement head;

    public GenericStack() {
        head = null;
    }

    /**
     * This method removes the top element from the stack and returns it.
     *
     * @return The top element of the stack.
     */
    public StackElement pop() {
        StackElement top = head;
        head = head.next;
        return top;
    }

    /**
     * This method adds an element to the top of the stack.
     *
     * @param element The element that will be added.
     */
    public void push(StackElement element) {
        element.next = head;
        head = element;
    }

    /**
     * This method adds an element to the top of the stack.
     * The new element is an object of class IntegerStackElement.
     *
     * @param value The integer value of the new element;
     */
    public void push(int value) {
        head = new IntegerStackElement(value, head);
    }

    /**
     * This method adds an element to the top of the stack.
     * The new element is an object of class CharStackElement.
     *
     * @param character The char value of the new element.
     */
    public void push(char character) {
        head = new CharStackElement(character, head);
    }

    /**
     * This method checks whether the stack is empty.
     *
     * @return Returns true if the stack is empty, otherwise returns false.
     */
    public boolean isEmpty() {
        return head == null;
    }
}
