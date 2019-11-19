package ru.spbu.baranovsky.dmitry;

/** Calculator that used in the app */
public class Calculator {

    /** Enum that represents operations */
    public enum OPERATIONS {PLUS, MINUS, MULTIPLICATION, DIVISION}

    /**
     * Calculates value
     * @param operator addition, subtraction, multiplication or division
     * @param firstOperand first value
     * @param secondOperand second value
     * @return calculated value
     */
    public double calculate(OPERATIONS operator, int firstOperand, int secondOperand) {
        double result = 0;
        switch (operator) {
            case PLUS:
                result = firstOperand + secondOperand;
                break;
            case MINUS:
                result = firstOperand - secondOperand;
                break;
            case MULTIPLICATION:
                result = firstOperand * secondOperand;
                break;
            case DIVISION:
                if (secondOperand == 0) {
                    throw new IllegalArgumentException("Division by zero");
                } else {
                    result = (double) firstOperand / secondOperand;
                }
        }
        return result;
    }
}