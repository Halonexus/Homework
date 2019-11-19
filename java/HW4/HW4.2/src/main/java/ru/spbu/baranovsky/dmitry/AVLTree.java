package ru.spbu.baranovsky.dmitry;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

/** The class that implements AVL tree */
public class AVLTree<T extends Comparable<T>> implements Collection<T> {
    private MainNode root = new MainNode();
    private int size;

    /** Returns the number of elements in this collection */
    @Override
    public int size() {
        return size;
    }

    /** Returns true if this collection contains no elements */
    @Override
    public boolean isEmpty() {
        return root == null;
    }

    /** Returns true if this collection contains the specified element */
    @Override
    public boolean contains(Object o) {
        return root.find((T) o);
    }

    /** Returns an iterator over the elements in this collection */
    @Override
    public Iterator<T> iterator() {
        return new AVLTreeIterator();
    }

    /** AVLTree iterator */
    private class AVLTreeIterator implements  Iterator<T> {
        private ArrayList<T> elements;
        private AVLTreeIterator() {
            elements = new ArrayList<>();
            root.takeAll(elements);
        }

        /** Returns true if there are elements in the array list */
        @Override
        public boolean hasNext() {
            return !elements.isEmpty();
        }

        /** Returns current element */
        @Override
        public T next() {
            if (!isEmpty()) {
                return null;
            }
            return elements.remove(0);
        }

    }

    /** Returns an array containing all of the elements in this collection */
    @Override
    public Object[] toArray() {
        ArrayList<T> result = new ArrayList<>();
        root.takeAll(result);
        return result.toArray();
    }

    /** Returns an array containing all of the elements in this collection */
    @Override
    public <T1> T1[] toArray(T1[] a) {
        ArrayList<T1> result = new ArrayList<>();
        ArrayList<T> temporary = new ArrayList<>();
        root.takeAll(temporary);
        for (T value : temporary)
            result.add((T1) value);
        return result.toArray(a);
    }

    /**
     * Ensures that this collection contains the specified element (optional
     * operation).  Returns true if this collection changed as a
     * result of the call.  (Returns false if this collection does
     * not permit duplicates and already contains the specified element.)
     */
    @Override
    public boolean add(T t) {
        if (contains(t)) {
            return false;
        }
        root.add(t);
        size++;
        return true;
    }

    /**
     * Removes a single instance of the specified element from this
     * collection, if it is present */
    @Override
    public boolean remove(Object o) {
        if (root.remove((T) o)) {
            size--;
            return true;
        }
        return false;
    }

    /**
     * Returns true if this collection contains all of the elements
     * in the specified collection */
    @Override
    public boolean containsAll(Collection<?> c) {
        boolean result = true;
        for (Object element : c) {
            result &= contains(element);
        }
        return result;
    }

    /** Adds all of the elements in the specified collection to this collection */
    @Override
    public boolean addAll(Collection<? extends T> c) {
        boolean result = true;
        for (Object element : c) {
            result &= add((T) element);
        }
        return result;
    }

    /**
     * Removes all of this collection's elements that are also contained in the
     * specified collection (optional operation).  After this call returns,
     * this collection will contain no elements in common with the specified
     * collection */
    @Override
    public boolean removeAll(Collection<?> c) {
        boolean result = true;
        for (Object element : c) {
            result &= remove((T) element);
        }
        return result;
    }

    /**
     * Retains only the elements in this collection that are contained in the
     * specified collection  */
    @Override
    public boolean retainAll(Collection<?> c) {
        boolean result = false;
        for (Object element : c) {
            if (contains(element)) {
                remove(element);
                result = true;
            }
        }
        return result;
    }

    /** Removes all of the elements from this collection */
    @Override
    public void clear() {
        root = null;
        size = 0;
    }

    /** Puts tree in the string */
    public String toString() {
        if (isEmpty()) {
            return "null";
        }
        return root.printTree();
    }
    private class MainNode {
        private Node node;

        private void add(T value) {
            if (node == null) {
                node = new Node(value);
                return;
            }
            if (find(value)) {
                return;
            }
            if (node.value.compareTo(value) > 0) {
                node.leftChild.add(value);
            } else {
                node.rightChild.add(value);
            }
            balance();
        }

        private boolean find(T value) {
            if (node == null) {
                return false;
            }
            if (node.value.equals(value)) {
                return true;
            }
            if (node.value.compareTo(value) > 0) {
                return node.leftChild.find(value);
            } else {
                return node.rightChild.find(value);
            }
        }

        private MainNode max() {
            if (node.rightChild.node == null) {
                return this;
            }
            return node.rightChild.max();
        }

        private void rotateLeft() {
            MainNode temporary = node.rightChild;
            MainNode newRightNode = new MainNode();
            newRightNode.node = node;
            newRightNode.node.rightChild = temporary.node.leftChild;
            temporary.node.leftChild = newRightNode;
            newRightNode.node.heightUpdate();
            temporary.node.heightUpdate();
            node = temporary.node;
        }

        private void rotateRight() {
            MainNode temporary = node.leftChild;
            MainNode newLeftNode = new MainNode();
            newLeftNode.node = node;
            newLeftNode.node.leftChild = temporary.node.rightChild;
            temporary.node.rightChild = newLeftNode;
            newLeftNode.node.heightUpdate();
            temporary.node.heightUpdate();
            node = temporary.node;
        }

        private void balance() {
            node.heightUpdate();
            if (node.balanceFactor() == 2) {
                if (node.leftChild.node != null && node.leftChild.node.balanceFactor() < 0) {
                    node.leftChild.rotateLeft();
                }
                rotateRight();
            } else if (node.balanceFactor() == -2) {
                if (node.rightChild.node != null && node.rightChild.node.balanceFactor() > 0) {
                    node.rightChild.rotateRight();
                }
                rotateLeft();
            }
        }

        private boolean remove(T value) {
            if (node == null) {
                return false;
            }
            if (node.value.equals(value)) {
                if (node.rightChild.node == null && node.leftChild.node == null) {
                    node = null;
                } else if (node.leftChild.node == null) {
                    node = node.rightChild.node;
                } else if (node.rightChild.node == null) {
                    node = node.leftChild.node;
                } else {
                    MainNode temporary = node.leftChild.max();
                    T maxValue = temporary.node.value;
                    while (node.leftChild.find(maxValue)) {
                        node.leftChild.remove(maxValue);
                    }
                    node.value = maxValue;
                    balance();
                }

                return true;
            }
            boolean result;
            if (node.value.compareTo(value) > 0) {
                result = node.leftChild.remove(value);
            } else {
                result = node.rightChild.remove(value);
            }

            balance();
            return result;
        }

        private String printTree() {
            StringBuilder result = new StringBuilder();
            result.append("(").append(node.value.toString()).append(" ");
            result.append(node.leftChild.node == null ? "null" : node.leftChild.printTree()).append(" ");
            result.append(node.rightChild.node == null ? "null" : node.rightChild.printTree()).append(")");
            return result.toString();
        }

        private void takeAll(ArrayList<T> list) {
            if (node == null) {
                return;
            }
            if (node.leftChild != null) {
                node.leftChild.takeAll(list);
            }
            list.add(node.value);
            if (node.rightChild != null) {
                node.rightChild.takeAll(list);
            }
        }
    }

    private class Node {
        private T value;
        private int height;
        private MainNode leftChild;
        private MainNode rightChild;

        private Node(T value) {
            this.value = value;
            this.height = 1;
            this.leftChild = new MainNode();
            this.rightChild = new MainNode();
        }

        private int balanceFactor() {
            return (leftChild.node == null? 0 : leftChild.node.height)
                    - (rightChild.node == null? 0 : rightChild.node.height);
        }

        private void heightUpdate() {
            height = Integer.max((leftChild.node == null? 0 : leftChild.node.height),
                    (rightChild.node == null? 0 : rightChild.node.height)) + 1;
        }
    }
}