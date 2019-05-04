package com.spbu.group144.baranovsky.list;

/** An element of a list that stores an integer value.*/
public class ListElement {
    private int value;
    private ListElement next;

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public ListElement getNext() {
        return next;
    }

    public void setNext(ListElement next) {
        this.next = next;
    }

    public ListElement(int value, ListElement next) {
        this.value = value;
        this.next = next;
    }
}
