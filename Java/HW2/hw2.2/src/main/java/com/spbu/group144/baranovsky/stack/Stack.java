package com.spbu.group144.baranovsky.stack;

/**
 * A basic stack interface.
 */
public interface Stack {
    /**
     * This method removes the top element from the stack and returns it.
     *
     * @return The top element of the stack.
     */
    StackElement pop();

    /**
     * This method adds an element to the top of the stack.
     *
     * @param element The element that will be added.
     */
    void push(StackElement element);

    /**
     * This method checks whether the stack is empty.
     *
     * @return Returns true if the stack is empty, otherwise returns false.
     */
    boolean isEmpty();
}