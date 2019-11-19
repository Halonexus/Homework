package ru.spbu.baranovsky.dmitry;

import org.junit.jupiter.api.Test;

import java.io.File;
import java.util.Scanner;

import static org.junit.jupiter.api.Assertions.*;

class ExpressionTreeTest {
    @Test
    public void additionTest() {
        Scanner reader = new Scanner("(+ 1 2)");
        ExpressionTree tree = new ExpressionTree(reader);
        assertEquals(3, tree.calculate());
    }

    @Test
    public void multiplicationTest() {
        Scanner reader = new Scanner("(* 1 2)");
        ExpressionTree tree = new ExpressionTree(reader);
        assertEquals(2, tree.calculate());
    }

    @Test
    public void subtractionTest() {
        Scanner reader = new Scanner("(- 1 2)");
        ExpressionTree tree = new ExpressionTree(reader);
        assertEquals(-1, tree.calculate());
    }

    @Test
    public void divisionTest() {
        Scanner reader = new Scanner("(/ 4 2)");
        ExpressionTree tree = new ExpressionTree(reader);
        assertEquals(2, tree.calculate());
    }

    @Test
    public void usualExpressionText() {
        Scanner reader = new Scanner("(* (+ 1 1) 2)");
        ExpressionTree tree = new ExpressionTree(reader);
        assertEquals(4, tree.calculate());
    }
}