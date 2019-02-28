package com.spbu.group144.baranovsky.stack;

/**
 * An element of a stack containing an integer value.
 */
public class StackElement {
    private int value;
    private StackElement next;

    public int getValue() {
        return value;
    }

    public StackElement getNext() {
        return next;
    }

    public StackElement(int value, StackElement next){
        this.next = next;
        this.value = value;
    }
}
