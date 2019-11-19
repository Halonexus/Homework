package ru.spbu.baranovsky.dmitry;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

/** The class that implements a hashtable */
public class Hashtable {
    private LinkedList<String>[] hashArray;
    private HashFunction hashFunction;
    private int size;

    /** Default constructor */
    public Hashtable() {
        this.hashFunction = new PolynomialHash();
        this.size = 347;
        initialize();
    }

    /** Constructor with given hash function and size of the hash table */
    public Hashtable(HashFunction hashFunction, int size) {
        this.hashFunction = hashFunction;
        this.size = size;
        initialize();
    }

    /** Initializing hash table */
    private void initialize() {
        this.hashArray = new LinkedList[this.size];
        for (int i = 0; i < this.size; ++i) {
            this.hashArray[i] = new LinkedList<>();
        }
    }

    /** A method that adds new string to the hash table */
    public void add(String string) {
        if (isInTable(string)) {
            return;
        }
        int hash = hashFunction.Hash(string);
        hashArray[hash].add(string);
    }

    /** A method that finds the string in hash table and returns index of the row */
    public int find(String string) {
        int hash = hashFunction.Hash(string);
        return hashArray[hash].find(string) != -1 ? hash : -1;
    }

    /** A method that removes the string from the hash table and returns false if string isn't it the hash table */
    public boolean remove(String string) {
        int hash = hashFunction.Hash(string);
        return hashArray[hash].remove(string);
    }

    /** A method that checks if string is already in hash table */
    public boolean isInTable(String string) {
        return find(string) != -1;
    }

    /** A method that counts elements in the hash table */
    public int countElements() {
        int result = 0;
        for (LinkedList<String> row : hashArray) {
            result += row.getLength();
        }
        return result;
    }

    /** A method that returns load factor of the hash table */
    public double getLoadFactor() {
        return (double) countElements() / size;
    }

    /** A method that returns quantity of empty rows */
    public int countEmptyRows() {
        int result = 0;
        for (LinkedList<String> row : hashArray) {
            result += row.isEmpty() ? 1 : 0;
        }
        return result;
    }

    /** A method that returns number of conflicts */
    public int countConflicts() {
        int result = 0;
        for (LinkedList<String> row : hashArray) {
            result += row.getLength() > 1 ? row.getLength() : 0;
        }
        return result;
    }

    /** A method that returns the maximal collision */
    public int getMaxCollision() {
        int result = 0;
        for (LinkedList<String> row : hashArray) {
            result = row.getLength() > result ? row.getLength() : result;
        }
        return result;
    }

    /** A method that prints statistic of the hash table */
    public void printStatistic() {
        System.out.println("The quantity of elements: " + size);
        System.out.println("The load factor = " + getLoadFactor());
        System.out.println("The quantity of conflicts = " + countConflicts());
        System.out.println("The maximal collision = " + getMaxCollision());
        System.out.println("The quantity of empty rows = " + countEmptyRows());

    }

    /** A method that fills hash table with the data from the file */
    public void fillTable(String fileName) {
        try {
            FileInputStream file = new FileInputStream(fileName);
            Scanner scanner = new Scanner(file);
            while (scanner.hasNext()) {
                String string = scanner.next();
                add(string);
            }
            file.close();
            scanner.close();
        }
        catch (FileNotFoundException e) {
            System.out.println("File is not found");
        } catch (IOException e) {
            System.out.println("Can't close the file");
        }
    }

    /** A method that changes the hash function */
    public void changeHashFunction(HashFunction hashFunction) {
        LinkedList<String>[] oldHashArray = hashArray;
        hashArray = new LinkedList[size];
        this.hashFunction = hashFunction;
        for (int i = 0; i < size; ++i) {
            hashArray[i] = new LinkedList<String>();
        }
        for (LinkedList<String> row : oldHashArray) {
            while (!row.isEmpty()) {
                String temporary = row.getValue();
                add(temporary);
                row.remove(temporary);
            }
        }
    }
}