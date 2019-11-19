package ru.spbu.baranovsky.dima;

public class QuickSort implements IntegerArraySorting {
    public void sort(int[] array) {
        quickSort(array, 0, array.length - 1);
    }

    private void quickSort(int[] array, int beginIndex, int endIndex) {
        int arraySize = endIndex - beginIndex + 1;
        if (arraySize < 2) {
            return;
        }
        int k = beginIndex;
        for (int i = k; i < endIndex; i++) {
            if (array[i] < array[endIndex]) {
                swap(array, i, k++);
            }
        }
        swap(array, endIndex, k);
        quickSort(array, beginIndex, k-1);
        quickSort(array, k+1, endIndex);
    }

    private void swap(int[] array, int index1, int index2) {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }
}