package ru.spbu.baranovsky.dmitry;


import java.io.PrintStream;
import java.util.Scanner;
import java.util.regex.Pattern;

/** Realization of the arithmetic tree */
public class ExpressionTree {
    private Node root;

    public ExpressionTree(Node root) {
        this.root = root;
    }

    public ExpressionTree(Scanner expression) {
        root = new OperatorNode(expression.next().charAt(1));
        createTreeRecursive(expression, (OperatorNode) root);
    }

    private Node createTreeRecursive(Scanner expression, OperatorNode node) {
        if (expression.hasNextInt()) {
            node.setLeftChild(new OperandNode(expression.next()));
        } else {
            node.setLeftChild(new OperatorNode(expression.next().charAt(1)));
            createTreeRecursive(expression, (OperatorNode) node.getLeftChild());
        }
        if (expression.hasNext(Pattern.compile("[-]?[0-9]+([)]+)?"))) {
            node.setRightChild(new OperandNode(expression.next()));
        } else {
            node.setRightChild(new OperatorNode(expression.next().charAt(1)));
            createTreeRecursive(expression, (OperatorNode) node.getRightChild());
        }
        return node;
    }

    /** A method that calculates expression */
    public int calculate() {
        return root.calculate();
    }

    /** A method that prints tree */
    public void print(PrintStream stream) {
        root.print(stream);
    }
}
