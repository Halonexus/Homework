package ru.spbu.baranovsky.dmitry;

public class Calculator {
    private double buffer;

    private OPERATIONS operator;

    private OPERATIONS firstPriorityOperator;

    private double firstPriorityValue;

    private boolean isEmpty;

    public enum OPERATIONS {PLUS, MINUS, MULTIPLICATION, DIVIDE}

    public Calculator() {
        isEmpty = true;
    }

    /**
     * Sets first priority operator
     * @param operator that is set
     */
    public void setOperator(OPERATIONS operator) {
        firstPriorityOperator = operator;
    }

    /**
     * Initializing of the calculator
     * @param newOperator sets new operator
     * @param value current value
     */
    public void initialize(OPERATIONS newOperator, double value) {
        firstPriorityValue = value;
        operator = OPERATIONS.PLUS;
        firstPriorityOperator = newOperator;
        buffer = 0;
        isEmpty = false;
    }

    /**
     * Calculation of the value
     * @param operator between two values
     * @param value
     */
    public void calculate(OPERATIONS operator, double value) {
        switch (firstPriorityOperator) {
            case PLUS:
            case MINUS:
                if (operator.equals(OPERATIONS.PLUS)) {
                    buffer += firstPriorityValue;
                } else {
                    buffer -= firstPriorityValue;
                }
                firstPriorityValue = value;
                this.operator = firstPriorityOperator;
                break;
            case DIVIDE:
                firstPriorityValue /= value;
                break;
            case MULTIPLICATION:
                firstPriorityValue *= value;
                break;
        }
        firstPriorityOperator = operator;
    }

    /** Returns current value of the calculator
     * @return current value
     */
    public double getValue() {
        switch (operator) {
            case PLUS:
                return buffer + firstPriorityValue;
            case MINUS:
                return buffer - firstPriorityValue;
        }
        return 0;
    }

    /**
     * Checks if the calculator is empty
     * @return true if it's empty calculator, false otherwise
     */
    public boolean isEmpty() {
        return isEmpty;
    }

    /** Sets calculator's fields' values by default */
    public void setEmpty() {
        buffer = 0;
        operator = null;
        firstPriorityOperator = null;
        firstPriorityValue = 0;
        isEmpty = true;
    }
}