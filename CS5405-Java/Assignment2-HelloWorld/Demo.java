//Name: Jimmy Lin
//Assignment: Homework 2
//Class: CS 5405 Java GUI & Visualization
//Due: 09/27/18

/** Compiling and Running Steps
1) javac -d . Demo.javac
2) jar -cfm Demo.jar Demo.txt *
3) java -jar Demo.jar
*/

//places code in code directory
package code;

import javafx.scene.control.Label; //allow the uses of labels
import javafx.scene.Scene; //allow the uses of scene
import javafx.stage.Stage; //allow the uses of stage
import javafx.application.Application; //allow the uses of abstract Application class

public class Demo extends Application {
	//override the start methhod of the Application class
	@Override
	public void start(Stage stage) {
		//create a label object
		Label label = new Label("Jimmy Lin");
		//create scene object with label object in it and dimensions of 300, 300
		Scene scene = new Scene(label, 300, 300);
		//place scene in the stage
		stage.setScene(scene);
		//set the title of the window (stage)
		stage.setTitle("Homework 2");
		//display the stage
		stage.show();
	}
}