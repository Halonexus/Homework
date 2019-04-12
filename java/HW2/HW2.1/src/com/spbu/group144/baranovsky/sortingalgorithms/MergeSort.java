package com.spbu.group144.baranovsky.sortingalgorithms;

/** A class of objects that can sort an integer array using merge sort.*/
public class MergeSort implements SortingAlgorithm {

    /**
     * Sorts the input array.
     *
     * @param input The array that will be sorted.
     */
    public void sort(int[] input) {
        int[] output = new int[input.length];
        splitSort(input, 0, input.length, output);
    }

    private void splitSort(int[] input, int begin, int end, int[] output) {
        if (end - begin < 2) {
            return;
        }
        int middle = (begin + end) / 2;
        splitSort(input, begin, middle, output);
        splitSort(input, middle, end, output);
        int unsortedBegin = begin;
        int unsortedMiddle = middle;
        for (int i = 0; i < end - begin; i++) {
            if (unsortedBegin >= middle) {
                output[begin + i] = input[unsortedMiddle++];
                continue;
            }
            if (unsortedMiddle >= end) {
                output[begin + i] = input[unsortedBegin++];
                continue;
            }
            if (input[unsortedBegin] < input[unsortedMiddle]) {
                output[begin + i] = input[unsortedBegin++];
            } else {
                output[begin + i] = input[unsortedMiddle++];
            }
        }
        System.arraycopy(output, begin, input, begin, end - begin);
    }
}
