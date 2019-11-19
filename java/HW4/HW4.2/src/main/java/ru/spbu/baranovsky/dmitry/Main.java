package ru.spbu.baranovsky.dmitry;

public class Main {
    public static void main(String[] args) {
        AVLTree<Integer> avlTree = new AVLTree<>();
        avlTree.add(5);
        avlTree.add(2);
        avlTree.add(1);
        System.out.println(avlTree.toString());
    }
}