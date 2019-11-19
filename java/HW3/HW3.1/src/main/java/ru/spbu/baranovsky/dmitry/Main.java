package ru.spbu.baranovsky.dmitry;

public class Main {
    public static void main(String[] args) {
        HashFunction hf = new PolynomialHash(1009);
        Hashtable h = new Hashtable(hf, 1009);//347
        h.add("asdsasd");
        h.add("lsdgj;s");
        h.add("lsdgj;1525125s");
        h.add("lsdgj;13123s");
        h.printStatistic();
    }
}
