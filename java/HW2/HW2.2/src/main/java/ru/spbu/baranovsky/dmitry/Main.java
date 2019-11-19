package ru.spbu.baranovsky.dmitry;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter an expression: ");
        String expression = reader.readLine();
        Calculator calculator = new Calculator();
        System.out.println("The answer = " + calculator.calculate(expression));
    }
}


