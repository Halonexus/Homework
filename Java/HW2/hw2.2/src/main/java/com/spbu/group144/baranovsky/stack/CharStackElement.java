package com.spbu.group144.baranovsky.stack;

/** An element of a CharStack that contains a char.*/
public class CharStackElement extends StackElement {
    protected char character;

    public char getCharacter() {
        return character;
    }

    public CharStackElement(char character, StackElement next) {
        super(next);
        this.character = character;
    }
}