package ru.spbu.baranovsky.dmitry;


/** The class that implements sum hash */
public class SumHash implements HashFunction{
    private int mod;

    public SumHash() {
        this.mod = 347;
    }

    public SumHash(int mod) {
        this.mod = mod;
    }

    /** A method that gets hash */
    @Override
    public int Hash(String string) {
        int hash = 0;
        for (int i = 0; i < string.length(); ++i) {
            hash += string.charAt(i);
            hash %= mod;
        }
        return hash;
    }
}
