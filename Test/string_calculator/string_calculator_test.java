package string_calculator;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;


class StringCalculatorTest {

    private StringCalculatorImpl StringCalculator;

    @BeforeEach
    void setUp() {
    	StringCalculator = new StringCalculatorImpl();
    }

   
   
    
    @Test
    void testEmptyString() {
        assertEquals(0, StringCalculator.add(""));
    }

    @Test
    void testSingleIntegerInput() {
        assertEquals(3, StringCalculator.add("3"));
    }

    @Test
    void testTwoNumbers() {
        assertEquals(6, StringCalculator.add("1,5"));
    }

    @Test
    void testMultipleNumbers() {
        assertEquals(15, StringCalculator.add("1,2,3,4,5"));
    }

    @Test
    void testAllowNewlineOperator() {
        assertEquals(101, StringCalculator.add("100\n1"));
    }

    @Test
    void testCustomDelimiterIsAllowed() {
        assertEquals(16, StringCalculator.add("//;\n7\n1;8"));
    }

    @Test
    void testCustomDelimiterIsAllowed2() {
        assertEquals(30, StringCalculator.add("//;\n18;10;2"));
    }

    @Test
    void testCustomDelimiterSingleNumber() {
        assertEquals(42, StringCalculator.add("//?\n42"));
    }

    @Test
    void testCustomDelimiterEmptyAfterNewline() {
        assertEquals(0, StringCalculator.add("//+\n"));
    }

    @Test
    void testSingleNegativeNumber() {
        IllegalArgumentException thrown = assertThrows(IllegalArgumentException.class, () -> {
            StringCalculator.add("-1");
        });
        assertEquals("negative numbers not allowed -1", thrown.getMessage());
    }

    @Test
    void testMultipleNegativeNumbers() {
        IllegalArgumentException thrown = assertThrows(IllegalArgumentException.class, () -> {
            StringCalculator.add("-1,2,-3,4,-5");
        });
        assertEquals("negative numbers not allowed -1,-3,-5", thrown.getMessage());
    }

    @Test
    void testMultipleNegativeNumbers2() {
        IllegalArgumentException thrown = assertThrows(IllegalArgumentException.class, () -> {
            StringCalculator.add("//[*][%]\n1*-2%3");
        });
        assertEquals("negative numbers not allowed -2", thrown.getMessage());
    }

    @Test
    void testHandlesCustomDelimiterWithMultipleCharacters() {
        assertEquals(6, StringCalculator.add("//[***]\n1***2***3"));
    }

    @Test
    void testHandlesMultipleDelimiters() {
        assertEquals(6, StringCalculator.add("//[*][%]\n1*2%3"));
    }

    @Test
    void testHandlesMultipleDelimitersWithLengthLongerThanOneChar() {
        assertEquals(10, StringCalculator.add("//[***][%%%]\n1***2%%%3***4"));
    }


  
}
