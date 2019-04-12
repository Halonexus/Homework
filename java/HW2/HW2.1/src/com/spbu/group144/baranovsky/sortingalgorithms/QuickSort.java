package com.spbu.group144.baranovsky.sortingalgorithms;

/** A class of objects that can sort an integer array using quick sort.*/
public class QuickSort implements SortingAlgorithm {

    private void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    /**
     * Sorts the input array.
     *
     * @param input The array that will be sorted.
     */
    public void sort(int[] input) {
        sort(input, 0, input.length - 1);
    }

    private void sort(int[] input, int startIndex, int endIndex) {
        int inputSize = endIndex - startIndex + 1;
        if (inputSize < 2) {
            return;
        }
        int anchor = startIndex;
        for (int i = 0; i < inputSize - 1; i++) {
            if (input[startIndex + i] < input[endIndex]) {
                swap(input, startIndex + i, anchor);
                anchor++;
            }
        }
        swap(input, anchor, endIndex);
        sort(input, startIndex, anchor - 1);
        sort(input, anchor + 1, endIndex);
    }
}
