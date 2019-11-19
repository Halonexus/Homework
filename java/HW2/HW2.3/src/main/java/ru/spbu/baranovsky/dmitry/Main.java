package ru.spbu.baranovsky.dmitry;

import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner reader = new Scanner(System.in);
        System.out.print("Enter a size of an array (size must be odd): ");
        int n = reader.nextInt();
        int[][] array = new int[n][n];
        System.out.print("Enter an array: ");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                array[i][j] = reader.nextInt();
            }
        }
        ConsoleWriter writer = new ConsoleWriter();
        writer.print(array);
    }
}
