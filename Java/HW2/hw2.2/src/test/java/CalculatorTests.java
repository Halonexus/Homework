import com.spbu.group144.baranovsky.calculator.Calculator;
import org.junit.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class CalculatorTests {
    @Test
    public void simpleAddition() {
        Calculator test = new Calculator();
        assertEquals(13, test.calculate("5 + 8"), "5+8=13");
    }

    @Test
    public void simpleSubtraction() {
        Calculator test = new Calculator();
        assertEquals(8, test.calculate("11 - 3"), "11-3=8");
    }

    @Test
    public void simpleMultiplication() {
        Calculator test = new Calculator();
        assertEquals(40, test.calculate("5 * 8"), "5*8=40");
    }

    @Test
    public void simpleDivision() {
        Calculator test = new Calculator();
        assertEquals(3, test.calculate("15 / 4"), "15 / 4 =3");
    }

    @Test
    public void complexOperation() {
        Calculator test = new Calculator();
        assertEquals(6, test.calculate("5+4*5-2-1+4*(-4)"), "5+4*5-2-1+4*(-4)=6");
    }
}
