package ru.spbu.baranovsky.dmitry;

import java.io.IOException;

/** The interface that outputs a converted matrix either to a file or to console */
public interface Writer {
    /** Prints the array */
    void print(int[][] array) throws IOException;

    /** Prints the element of the array */
    void printElement(String element) throws IOException;
}