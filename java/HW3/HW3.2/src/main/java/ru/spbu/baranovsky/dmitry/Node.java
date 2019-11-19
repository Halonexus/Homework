package ru.spbu.baranovsky.dmitry;

import java.io.PrintStream;

/** The node of the tree */
public interface Node {
    /** A method that calculates value in the node */
    public int calculate();

    /** A method that prints the node */
    public void print(PrintStream stream);
}
