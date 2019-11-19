package ru.spbu.baranovsky.dmitry;

import java.io.IOException;

/** A class that implements a Writer through the console */
public class ConsoleWriter implements Writer{
    /** A method that prints the array **/
    @Override
    public void print(int[][]array) throws IOException {
        ConverterToString.convert(array, this);
    }

    /** A method that prints the array's element */
    @Override
    public void printElement(String element) {
        System.out.print(element);
    }
}
