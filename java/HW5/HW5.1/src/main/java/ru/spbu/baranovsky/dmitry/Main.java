package ru.spbu.baranovsky.dmitry;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        Parent root = FXMLLoader.load(getClass().getResource("Main.fxml"));
        stage.setTitle("Slider");
        stage.setScene(new Scene(root, 500, 250));
        stage.centerOnScreen();
        stage.setMinWidth(500);
        stage.setMinHeight(250);
        stage.show();
    }
}