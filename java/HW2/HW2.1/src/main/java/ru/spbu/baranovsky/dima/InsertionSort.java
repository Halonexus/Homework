package ru.spbu.baranovsky.dima;

public class InsertionSort implements IntegerArraySorting {
    public void sort(int[] array) {
        int arraySize = array.length;
        for (int i = 1; i < arraySize; i++) {
            for (int j = i; j > 0; j--) {
                if (array[j] >= array[j - 1]) {
                    break;
                }
                swap(array, j, j - 1);
            }
        }
    }

    private void swap(int[] array, int index1, int index2) {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }
}