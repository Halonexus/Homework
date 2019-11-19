package ru.spbu.baranovsky.dmitry;

import java.io.PrintStream;
import java.util.Scanner;

/** Node that contains operand */
public class OperandNode implements Node {
    private int value;

    OperandNode(String input) {
        if (input.charAt(input.length() - 1) == ')') {
            value = Integer.parseInt(input.substring(0, input.indexOf(')')));
        } else {
            value = Integer.parseInt(input);
        }
    }

    /** A method that calculates value of the node */
    @Override
    public int calculate() {
        return value;
    }

    /** A method that prints the node */
    @Override
    public void print(PrintStream stream) {
        stream.print(value);
    }
}
