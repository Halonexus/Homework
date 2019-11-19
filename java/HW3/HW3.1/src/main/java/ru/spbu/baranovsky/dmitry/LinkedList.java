package ru.spbu.baranovsky.dmitry;

/** The realization of a singly linked lsit */
public class LinkedList <T> {
    private int length;
    private Node head;

    /** A method that checks if the list is empty */
    public boolean isEmpty() {
        return length == 0;
    }

    /** A method that shows the length of the list */
    public int getLength() {
        return length;
    }

    /** A method that adds a new element to the end of the list */
    public void add(T value) {
        if (isEmpty()) {
            head = new Node(value, null);
            length++;
        } else {
            Node temporary = this.head;
            while (temporary.next != null) {
                temporary = temporary.next;
            }
            temporary.next = new Node(value, null);
            length++;
        }
    }

    /** A method that adds a new element after given index */
    public void add(T value, int index) {
        if (isEmpty()) {
            add(value);
            return;
        }
        if (index > length || index < 0) {
            return;
        }
        if (index == length) {
            add(value);
            return;
        }
        length++;
        if (index == 0) {
            Node prevNode = this.head;
            this.head = new Node(value, prevNode);
            return;
        }

        Node temporary = this.head;
        for (int i = 0; i < index - 1; ++i) {
            temporary = temporary.next;
        }
        temporary.next =  new Node(value, temporary.next);
    }

    /** A method that returns an index of given element (or -1 if the element isn't in the list) */
    public int find(T value) {
        Node temporary = this.head;
        int index = 0;
        while (temporary != null) {
            if (temporary.value.equals(value)) {
                return index;
            }
            index++;
            temporary = temporary.next;
        }
        return -1;
    }

    /** A method that removes the element from the list and returns false if the element isn't in the list */
    public boolean remove(T value) {
        Node thisNode = this.head;
        Node prevNode = null;
        while (thisNode != null) {
            if (thisNode.value.equals(value)) {
                if (prevNode != null) {
                    prevNode.next = thisNode.next;
                    length--;
                    return true;
                } else {
                    length--;
                    this.head = thisNode.next;
                    return true;
                }
            }
            prevNode = thisNode;
            thisNode = thisNode.next;
        }
        return false;
    }

    /** A method that prints the list */
    public void print() {
        Node temporary = this.head;
        while (temporary != null) {
            System.out.print(temporary.value + " ");
            temporary = temporary.next;
        }
    }

    /** A method that return value of the head */
    public T getValue() {
        return head.value;
    }

    private class Node {
        private T value;
        private Node next;
        private Node(T value, Node next) {
            this.value = value;
            this.next = next;
        }
    }
}
