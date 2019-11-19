package ru.spbu.baranovsky.dmitry;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CalculatorTest {
    @Test
    public void calculatorAdditionTest() {
        Calculator calculator = new Calculator();
        calculator.initialize(Calculator.OPERATIONS.PLUS, 4);
        calculator.calculate(Calculator.OPERATIONS.PLUS, 3);
        assertEquals(7.0, calculator.getValue());
    }

    @Test
    public void calculatorSubtractionTest() {
        Calculator calculator = new Calculator();
        calculator.initialize(Calculator.OPERATIONS.MINUS, 5);
        calculator.calculate(Calculator.OPERATIONS.PLUS, 2);
        assertEquals(3, calculator.getValue());
    }

    @Test
    public void calculatorMultiplicationTest() {
        Calculator calculator = new Calculator();
        calculator.initialize(Calculator.OPERATIONS.MULTIPLICATION, 5);
        calculator.calculate(Calculator.OPERATIONS.MULTIPLICATION, 2);
        assertEquals(10, calculator.getValue());
    }

    @Test
    public void calculatorDivisionTest() {
        Calculator calculator = new Calculator();
        calculator.initialize(Calculator.OPERATIONS.DIVIDE, 10);
        calculator.calculate(Calculator.OPERATIONS.DIVIDE, 4);
        assertEquals(2.5, calculator.getValue());
    }

    @Test
    public void simpleExpressionTest() {
        // 1 + 2 / 4
        Calculator calculator = new Calculator();
        calculator.initialize(Calculator.OPERATIONS.PLUS, 1);
        calculator.calculate(Calculator.OPERATIONS.PLUS, 2);
        calculator.calculate(Calculator.OPERATIONS.DIVIDE, 4);
        assertEquals(3, calculator.getValue());
    }

    @Test
    public void longExpressionTest() {
        // 1 - 2 + 2 - 1
        Calculator calculator = new Calculator();
        calculator.initialize(Calculator.OPERATIONS.MINUS, 1);
        calculator.calculate(Calculator.OPERATIONS.PLUS, 2);
        calculator.calculate(Calculator.OPERATIONS.MINUS, 2);
        calculator.calculate(Calculator.OPERATIONS.PLUS, 1);
        assertEquals(0, calculator.getValue());
    }
}