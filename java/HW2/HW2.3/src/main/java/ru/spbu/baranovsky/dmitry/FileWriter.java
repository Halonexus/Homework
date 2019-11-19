package ru.spbu.baranovsky.dmitry;

import java.io.FileOutputStream;
import java.io.IOException;

/** A class that implements a Writer through file */
public class FileWriter implements Writer {
    private FileOutputStream file;

    public FileWriter(String fileName) throws IOException {
        file = new FileOutputStream(fileName, true);
    }
    /** Prints the array */
    @Override
    public void print(int[][] array) throws IOException {
        ConverterToString.convert(array, this);
    }

    /** Prints the element of the array */
    @Override
    public void printElement(String element) throws IOException {
        file.write(element.getBytes());
    }
}
