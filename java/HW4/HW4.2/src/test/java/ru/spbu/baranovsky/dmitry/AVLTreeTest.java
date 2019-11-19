package ru.spbu.baranovsky.dmitry;

import org.junit.jupiter.api.Test;

import java.util.LinkedList;

import static org.junit.jupiter.api.Assertions.*;

class AVLTreeTest {
    @Test
    public void addingTest() {
        AVLTree<Integer> avlTree = new AVLTree<>();
        avlTree.add(5);
        avlTree.add(2);
        assertEquals(2, avlTree.size());
    }

    @Test
    public void removingTest() {
        AVLTree<Integer> avlTree = new AVLTree<>();
        avlTree.add(5);
        avlTree.add(2);
        avlTree.remove(2);
        assertEquals(1, avlTree.size());
    }

    @Test
    public void addingSameElementsTest() {
        AVLTree<Integer> avlTree = new AVLTree<>();
        avlTree.add(5);
        avlTree.add(5);
        assertEquals(1, avlTree.size());
    }

    @Test
    public void findingElementTest() {
        AVLTree<Integer> avlTree = new AVLTree<>();
        avlTree.add(5);
        assertTrue(avlTree.contains(5));
    }

    @Test
    public void toStringTest() {
        AVLTree<Integer> avlTree = new AVLTree<>();
        avlTree.add(5);
        avlTree.add(2);
        avlTree.add(261);
        avlTree.add(52);
        avlTree.add(2512);
        avlTree.add(9012);
        avlTree.add(72);
        assertEquals("(261 (5 (2 null null) (52 null (72 null null))) (2512 null (9012 null null)))",
                avlTree.toString());
    }

    @Test
    public void clearTest() {
        AVLTree<Integer> avlTree = new AVLTree<>();
        avlTree.add(5);
        avlTree.add(2);
        avlTree.add(261);
        avlTree.add(52);
        avlTree.add(2512);
        avlTree.add(9012);
        avlTree.add(72);
        avlTree.clear();
        assertEquals("null", avlTree.toString());
    }

    @Test
    public void retainAllTest() {
        AVLTree<Integer> avlTree = new AVLTree<>();
        avlTree.add(5);
        avlTree.add(2);
        avlTree.add(261);
        avlTree.add(52);
        avlTree.add(2512);
        avlTree.add(9012);
        avlTree.add(72);
        LinkedList<Integer> list = new LinkedList<>();
        list.add(5);
        list.add(2);
        list.add(261);
        avlTree.retainAll(list);
        assertEquals("(72 (52 null null) (2512 null (9012 null null)))", avlTree.toString());
    }

    @Test
    public void removeAllTest() {
        AVLTree<Integer> avlTree = new AVLTree<>();
        avlTree.add(5);
        avlTree.add(2);
        avlTree.add(261);
        avlTree.add(52);
        avlTree.add(2512);
        avlTree.add(9012);
        avlTree.add(72);
        LinkedList<Integer> list = new LinkedList<>();
        list.add(5);
        list.add(2);
        list.add(261);
        avlTree.removeAll(list);
        assertEquals("(72 (52 null null) (2512 null (9012 null null)))", avlTree.toString());
    }
}