package com.spbu.group144.baranovsky.stack;

/**
 * A stack for storing integer values.
 */
public class Stack {
    private StackElement head;

    public Stack(){
    }

    /**
     * Removes an element from the top of the stack.
     * @return Returns the integer value of the top element.
     */
    public int pop(){
        if(!isEmpty()){
            StackElement top = head;
            head = head.getNext();
            return top.getValue();
        }
        return 0;
    }

    /**
     * Adds a new element to the stack.
     * @param value The integer value of the new element.
     */
    public void push(int value){
        head = new StackElement(value, head);
    }

    /**
     * Checks whether the stack is empty.
     * @return True if the stack is empty. False otherwise.
     */
    public boolean isEmpty(){
        return head == null;
    }
}
