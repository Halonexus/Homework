package ru.spbu.baranovsky.dmitry;

/** The interface of a stack **/
public interface Stack {
    /** A method that adds an element **/
    void push(String input);

    /** A method that removes an element **/
    String pop();

    /** A method that checks whether the stack is empty **/
    boolean isEmpty();

    /** A method that counts the amount of elements **/
    int numberOfElements();
}
