package com.spbu.group144.baranovsky.stack;

/** An element of a stack.*/
public abstract class StackElement {
    protected StackElement next;

    public StackElement getNext() {
        return next;
    }

    protected StackElement(StackElement next){
        this.next = next;
    }
}
