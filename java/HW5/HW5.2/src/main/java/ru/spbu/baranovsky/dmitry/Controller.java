package ru.spbu.baranovsky.dmitry;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Spinner;
import javafx.scene.control.SpinnerValueFactory;
import javafx.scene.control.TextField;

/** Controller of the app */
public class Controller {
    @FXML
    private Spinner<Integer> firstValue;

    @FXML
    private Spinner<Integer> secondValue;

    @FXML
    private ChoiceBox<String> operation;

    @FXML
    private TextField answer;

    private Calculator calculator = new Calculator();

    /** Initializing FXML variables */
    public void initialize() {
        ObservableList<String> list = FXCollections.observableArrayList("+", "-", "*", "/");
        operation.setItems(list);
        operation.setValue("+");
        SpinnerValueFactory<Integer> firstValueFactory =
                new SpinnerValueFactory.IntegerSpinnerValueFactory(-9, 9, 0);
        firstValue.setValueFactory(firstValueFactory);
        SpinnerValueFactory<Integer> secondValueFactory =
                new SpinnerValueFactory.IntegerSpinnerValueFactory(-9, 9, 0);
        secondValue.setValueFactory(secondValueFactory);
        answer.textProperty().setValue("0");
        firstValue.valueProperty().addListener(((observable, oldValue, newValue) -> calculate()));
        secondValue.valueProperty().addListener(((observable, oldValue, newValue) -> calculate()));
        operation.valueProperty().addListener(observable -> calculate());
    }

    private void calculate() {
        Calculator.OPERATIONS operator = Calculator.OPERATIONS.PLUS;
        switch (operation.getValue()) {
            case "+":
                break;
            case "-":
                operator = Calculator.OPERATIONS.MINUS;
                break;
            case "*":
                operator = Calculator.OPERATIONS.MULTIPLICATION;
                break;
            case "/":
                operator = Calculator.OPERATIONS.DIVISION;
                break;
        }
        try {
            calculator.calculate(operator, firstValue.getValue(), secondValue.getValue());
        } catch (IllegalArgumentException e) {
            answer.setText(e.getMessage());
        }
        answer.setText(String.valueOf(calculator.calculate(operator, firstValue.getValue(), secondValue.getValue())));
    }
}