package ru.spbu.baranovsky.dmitry;

/** The exception that throwed if user is trying to remove element that's not in the list */
public class ElementIsNotInTheListException extends Exception {

    public ElementIsNotInTheListException() { super(); }

    public ElementIsNotInTheListException(String msg) { super(msg); }
}