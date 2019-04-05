//Author: Jimmy Lin
//Homework 3
//Class: CS 5405
//Due Date: 09/25/18

//places compiled code (.class) in code directory
package code;

//allows the use of Scanner
import java.util.Scanner;
//allows the use of files
import java.io.File;
//allows reading of file
import java.io.InputStream;
//allows the use of sqrt()
import static java.lang.Math.sqrt;
//allows the use of abs()
import static java.lang.Math.abs;

//allows the use of Scene
import javafx.scene.Scene;
//allowsthe use of Stage
import javafx.stage.Stage;
//allows the use of abstract Application class
import javafx.application.Application;
//allows the use of Pane
import javafx.scene.layout.Pane;
//allows the use of Label
import javafx.scene.control.Label;
//allows the use of circles
import javafx.scene.shape.Circle;
//allows the use of colors
import javafx.scene.paint.Color;


public class Circles extends Application{
	//initialize variables to be used in all methods in class
	Scanner scanner;
	String str;
	Pane pane;
	Label label;
	
	//override start method in Application class
	@Override
	public void start(Stage stage) {
		//create pane to hold objects
		pane = new Pane();
		
		//calls read method
		read();
		
		//create new scene with pane inside
		//dimensions 400x400
		//background color = LIGHTGREY
		Scene scene = new Scene(pane, 400, 400, Color.LIGHTGREY);
		
		//places pane on stage
		stage.setScene(scene);
		
		//set title of the stage
		stage.setTitle("Homework 3");
		
		//display the stage
		stage.show();
		
		
	}
	
	//reads data from file
	public void read() {
		//initialize variables
		double x1 = 0;
		double x2 = 0;
		double y1 = 0;
		double y2 = 0;
		double r1 = 0;
		double r2 = 0;
		double math = 0;
		
		//try to read from file
		try {
			//read from file
			scanner = new Scanner(new File("inFile.txt"));
		}
		//fail to read from file
		catch(Exception e) {
			//error message
			System.out.println("Unable to read file");
		}
		
		//assign values from file to variables
		x1 = scanner.nextDouble();
		y1 = scanner.nextDouble();
		r1 = scanner.nextDouble();
		x2 = scanner.nextDouble();
		y2 = scanner.nextDouble();
		r2 = scanner.nextDouble();
		
		createCircle(x1, y1, r1, Color.RED);
		createCircle(x2, y2, r2, Color.BLUE);
		
		//determine what type of circle/intersection is formed
		//perform math functions on variables
		math = sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
		
		//determine if circles touch/overlap
		if(math > (r1+r2)) {
			str = "They are disjoint";
		}
		else if(math == (r1+r2) || math == abs(r1-r2)) {
			str = "They touch";
		}
		else if(math < abs(r1-r2)) {
			str = "One is inside the other";
		}
		else if(math < (r1+r2)) {
			str = "They properly overlap";
		}
		
		//set label to show results
		label = new Label(str);
		//add label to pane
		pane.getChildren().addAll(label);
	}
	
	//create circles
	public void createCircle(double x, double y, double r, Color color) {
		//create circle object
		Circle circle = new Circle();
		//determines where the circle is placed on X axis
		circle.setCenterX(x);
		//determines where the circle is placed on Y axis
		circle.setCenterY(y);
		//deermines radius of circles
		circle.setRadius(r);
		//set the color of the outline of circle
		circle.setStroke(Color.BLACK);
		//set color of circle
		circle.setFill(color);
		//adds circle to pane
		pane.getChildren().add(circle);
		
	}

	//Required for IDE
	public static void main(String[] args) {
        launch(args);
    }
}