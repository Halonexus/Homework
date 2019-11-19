package ru.spbu.baranovsky.dmitry;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class UniqueListTest {
    @Test
    public void addingTest() throws ElementAlreadyInTheListException {
        UniqueList<Integer> uniqueList = new UniqueList<>();
        uniqueList.add(23);
        assertEquals(0, uniqueList.find(23));
    }

    @Test
    public void addingEqualElementTest() throws ElementAlreadyInTheListException {
        UniqueList<Integer> uniqueList = new UniqueList<>();
        uniqueList.add(23);
        ElementAlreadyInTheListException exception =
                assertThrows(ElementAlreadyInTheListException.class, () -> uniqueList.add(23));
        assertEquals("You're trying to add element that's already in the list", exception.getMessage());
    }

    @Test
    public void removingTest() throws IndexOutOfBoundsException, ElementIsNotInTheListException,
            ElementAlreadyInTheListException
    {
        UniqueList<Integer> uniqueList = new UniqueList<>();
        uniqueList.add(23);
        uniqueList.remove(23);
        assertEquals(-1, uniqueList.find(23));
    }

    @Test
    public void removingInvalidElementTest() throws ElementAlreadyInTheListException {
        UniqueList<Integer> uniqueList = new UniqueList<>();
        uniqueList.add(23);
        ElementIsNotInTheListException exception =
                assertThrows(ElementIsNotInTheListException.class, () -> uniqueList.remove(42));
        assertEquals("You're trying to remove element that's not in the list", exception.getMessage());
    }

    @Test
    public void addingValidElementWithCorrectIndex() throws IndexOutOfBoundsException,
            ElementAlreadyInTheListException
    {
        UniqueList<Integer> uniqueList = new UniqueList<>();
        uniqueList.add(23);
        uniqueList.add(42, 1);
        assertEquals(1, uniqueList.find(42));
    }

    @Test
    public void addingInvalidElementWithCorrectIndex() throws IndexOutOfBoundsException,
            ElementAlreadyInTheListException
    {
        UniqueList<Integer> uniqueList = new UniqueList<>();
        uniqueList.add(23);
        ElementAlreadyInTheListException exception =
                assertThrows(ElementAlreadyInTheListException.class, () -> uniqueList.add(23, 1));
        assertEquals("You're trying to add element that's already in the list", exception.getMessage());
    }

    @Test
    public void addingValidElementWithIncorrectIndex() throws ElementAlreadyInTheListException {
        UniqueList<Integer> uniqueList = new UniqueList<>();
        uniqueList.add(23);
        IndexOutOfBoundsException exception =
                assertThrows(IndexOutOfBoundsException.class, () -> uniqueList.add(23, -1));
        assertEquals("You entered invalid index", exception.getMessage());
    }
}