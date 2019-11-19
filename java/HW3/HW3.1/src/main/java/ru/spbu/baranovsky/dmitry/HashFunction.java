package ru.spbu.baranovsky.dmitry;

/** The interface that allows user to change the hash function */
public interface HashFunction {

    /** A method that gets hash */
    int Hash(String string);
}
