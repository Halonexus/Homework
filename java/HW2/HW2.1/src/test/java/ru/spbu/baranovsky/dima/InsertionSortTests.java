package ru.spbu.baranovsky.dima;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

class InsertionSortTests {
    @Test
    void reverseOrder() {
        int[] unsortedArray = {9, 7, 6, 4, 3, 1};
        int[] sortedArray = {1, 3, 4, 6, 7, 9};
        InsertionSort sorter = new InsertionSort();
        sorter.sort(unsortedArray);
        assertArrayEquals(sortedArray, unsortedArray);
    }

    @Test
    void correctOrder() {
        int[] unsortedArray = {1, 3, 4, 6, 7, 9};
        int[] sortedArray = {1, 3, 4, 6, 7, 9};
        InsertionSort sorter = new InsertionSort();
        sorter.sort(unsortedArray);
        assertArrayEquals(sortedArray, unsortedArray);
    }

    @Test
    void randomOrder() {
        int[] unsortedArray = {4, 1, 9, 7, 3, 6};
        int[] sortedArray = {1, 3, 4, 6, 7, 9};
        InsertionSort sorter = new InsertionSort();
        sorter.sort(unsortedArray);
        assertArrayEquals(sortedArray, unsortedArray);
    }
}
