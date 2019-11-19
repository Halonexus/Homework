package ru.spbu.baranovsky.dmitry;

/** The exception that throwed if user is trying to add element that's already in the list */
public class ElementAlreadyInTheListException extends Exception {

    public ElementAlreadyInTheListException() { super(); }

    public ElementAlreadyInTheListException(String msg) { super(msg); }

}