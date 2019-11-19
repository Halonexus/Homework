package ru.spbu.baranovsky.dmitry;

import java.io.IOException;

/** A class that allows to convert an array to a String */
public class ConverterToString {
    public static void convert(int[][] array, Writer writer) throws IOException {
        if (array == null || array.length % 2 == 0) {
            System.out.println("Incorrect array size");
            return;
        }
        int moveRight = 2;
        int moveUp = 2;
        int moveDown = 2;
        int moveLeft = 1;
        int column = array.length / 2;
        int row = array.length / 2;
        writer.printElement("Elements of the array: " + array[row][column] + " ");
        while (!(row == 0 && column == array.length - 1)) {
            row--;
            writer.printElement(array[row][column] + " ");
            for (int i = 0; i < moveLeft; ++i) {
                column--;
                writer.printElement(array[row][column] + " ");
            }
            for (int i = 0; i < moveDown; ++i) {
                row++;
                writer.printElement(array[row][column] + " ");
            }
            for (int i = 0; i < moveRight; ++i) {
                column++;
                writer.printElement(array[row][column] + " ");
            }
            for (int i = 0; i < moveUp; ++i) {
                row--;
                writer.printElement(array[row][column] + " ");
            }
            moveDown += 2;
            moveLeft += 2;
            moveRight += 2;
            moveUp += 2;
        }
    }
}
