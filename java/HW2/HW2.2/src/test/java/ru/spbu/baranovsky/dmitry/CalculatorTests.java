package ru.spbu.baranovsky.dmitry;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class CalculatorTests {
    private static Calculator calculator = new Calculator();

    @Test
    public void additionTest(){
        assertEquals(5,calculator.calculate("3+2"));
    }

    @Test
    public void subtractionTest(){
        assertEquals(5,calculator.calculate("7-2"));
    }

    @Test
    public void multiplicationTest(){
        assertEquals(6,calculator.calculate("3*2"));
    }

    @Test
    public void divisionTest(){
        assertEquals(3,calculator.calculate("11/3"));
    }

    @Test
    public void illegalArgumentExceptionTest(){
        assertThrows(IllegalArgumentException.class, () -> calculator.calculate("a+4"));
    }

    @Test
    public void expressionFormatExceptionTestBrackets(){
        assertThrows(ExpressionFormatException.class, () -> calculator.calculate("5+((4-2)"));
    }

    @Test
    public void expressionFormatExceptionTestOperations(){
        assertThrows(ExpressionFormatException.class, () -> calculator.calculate("5-+4"));
    }
}
