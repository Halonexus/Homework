package ru.spbu.baranovsky.dmitry;

/** The class that implements polynomial hashing */
public class PolynomialHash implements HashFunction {
    private int mod;

    public PolynomialHash() {
        this.mod = 347;
    }

    public PolynomialHash(int mod) {
        this.mod = mod;
    }

    /** A method that gets hash */
    @Override
    public int Hash(String string) {
        int hash = 0;
        int p = 37;
        for (int i = 0; i < string.length(); ++i) {
            hash += (string.charAt(i) * p) % mod;
            p = (p * p) % mod;
            hash %= mod;
        }
        return hash;
    }
}
