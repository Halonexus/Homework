package ru.spbu.baranovsky.dmitry;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class CalculatorTest {
    private Calculator calculator = new Calculator();

    @Test
    public void additionTest() {
        assertEquals(5, calculator.calculate(Calculator.OPERATIONS.PLUS, 2, 3));
    }

    @Test
    public void subtractionTest() {
        assertEquals(8, calculator.calculate(Calculator.OPERATIONS.MINUS, 3, -5));
    }

    @Test
    public void multiplicationTest() {
        assertEquals(-20,
                calculator.calculate(Calculator.OPERATIONS.MULTIPLICATION, -4, 5));
    }

    @Test
    public void divisionTest() {
        assertEquals(0.2,
                calculator.calculate(Calculator.OPERATIONS.DIVISION, 2, 10));
    }

    @Test
    public void divisionByZeroTest() {
        IllegalArgumentException exception = assertThrows(IllegalArgumentException.class,
                () -> calculator.calculate(Calculator.OPERATIONS.DIVISION, 5, 0));
        assertEquals("Division by zero", exception.getMessage());
    }
}