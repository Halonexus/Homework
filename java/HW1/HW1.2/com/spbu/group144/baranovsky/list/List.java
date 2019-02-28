package com.spbu.group144.baranovsky.list;

/**
 * A single-linked list for storing integer values.
 */
public class List {
    private ListElement head;

    public ListElement getHead() {
        return head;
    }

    public void setHead(ListElement head) {
        this.head = head;
    }

    public List() {
        head = null;
    }

    /**
     * Adds a new element at the beginning of the list.
     *
     * @param value The integer value of the new element.
     */
    public void addElement(int value) {
        ListElement currentHead = head;
        head = new ListElement(value, currentHead);
    }

    /**
     * Searches for an element with the correct value and deletes it.
     *
     * @param value The value of the element that needs to be deleted.
     */
    public void deleteElementByValue(int value) {
        if (isEmpty()) {
            return;
        }
        if (head.getValue() == value) {
            head = head.getNext();
            return;
        }
        ListElement current = head;
        while (current.getNext() != null) {
            if (current.getNext().getValue() == value) {
                current.setNext(current.getNext().getNext());
                return;
            }
        }
    }

    /**
     * Checks whether the list is empty.
     *
     * @return Returns True if the list is empty;
     */
    public boolean isEmpty() {
        return head == null;
    }
}
