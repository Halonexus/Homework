package ru.spbu.baranovsky.dmitry;

import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try {
            Scanner reader = new Scanner(new File("expression.txt"));
            ExpressionTree tree = new ExpressionTree(reader);
            tree.print(System.out);
            System.out.println();
            System.out.println(tree.calculate());
        } catch (FileNotFoundException e) {
            System.out.println("File not found");
        }
    }
}