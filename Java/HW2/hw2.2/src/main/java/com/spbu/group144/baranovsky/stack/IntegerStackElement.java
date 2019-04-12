package com.spbu.group144.baranovsky.stack;

/** An element of an IntegerStack that contains an integer value.*/
public class IntegerStackElement extends StackElement {
    protected int value;

    public int getValue() {
        return value;
    }

    public IntegerStackElement(int value, StackElement next) {
        super(next);
        this.value = value;
    }
}
