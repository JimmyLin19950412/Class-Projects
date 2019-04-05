//Author: Jimmy Lin
//Assignment: Homework 4
//Class: CS 5405 Java
//Due Date: October 04, 2018

//places compiled code into code directory
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

//allows the use of stage
import javafx.stage.Stage;
//allows the use of scene
import javafx.scene.Scene;
//allows the use of panes
import javafx.scene.layout.Pane;
//allows the use of abstract class Application
import javafx.application.Application;
//allows the use of colors
import javafx.scene.paint.Color;
//allows the use of Font
import javafx.scene.text.Font;
//allows the use of FontWeight
import javafx.scene.text.FontWeight;
//allows the use of FontPosture
import javafx.scene.text.FontPosture;
//allows the use of TextAlignment
import javafx.scene.text.TextAlignment;
//allows the use of ActionEvent
import javafx.event.ActionEvent;
//allows the use of EventHandler
import javafx.event.EventHandler;
//allows the use of Label
import javafx.scene.control.Label;
//allows the use of circles
import javafx.scene.shape.Circle;
//allows the use of colors
//allows the use of Buttons
import javafx.scene.control.Button;
//allows the use of Text
import javafx.scene.text.Text;



public class Demo extends Application {
	//initilizes Scanner
	Scanner scanner;
	//initilzaes String object
	String str;
	
	//creating the panes
	//creating object pane to hold the root/all other panes and objects
	Pane root = new Pane();
	//creating object pane for demo
	Pane pane_demo = new Pane();
	//creating object pane to hold other panes
	Pane pane_hold = new Pane();
	//intializes scene
	Scene scene;
	//intializes stage
	Stage stage;
	
	//creating buttons
	Button button_author;
	Button button_description;
	Button button_problems;
	Button button_demo;
	
	//creating text
	Text text_author;
	Text text_description;
	Text text_problems;
	
	//creating label
	Label label;
	
	//overrides the start method in Application class
	//executes method at start of program
	@Override
	public void start(Stage stage)	{
		//calls method to initilze text
		initializeText();
		
		//calls method to initilaze buttons
		initializeButton();
		
		//repositioning and resizing pane_hold
		pane_hold.setPrefSize(490,400);
		pane_hold.setTranslateX(10);
		pane_hold.setTranslateY(100);
		
		//calls read method for demo
		read();
		
		//initially add pane_author to text_hold
		pane_hold.getChildren().add(text_author);
		
		//adding buttons and pane to root
		root.getChildren().addAll(button_author, button_description, button_problems, button_demo, pane_hold);
		//placing root onto scene with dimensions of 1000x1000 background color = GRAY
		scene = new Scene(root, 500, 500, Color.GRAY);
		//placing the scene onto the stage
		stage.setScene(scene);
		//setting title for the stage
		stage.setTitle("Homework 4");
		//showing the stage
		stage.show();
	}
	
	//initilaze buttons and set their location
	public void initializeButton() {
		//initilize buttons
		button_author = new Button("Author");
		button_description = new Button("Description");
		button_problems = new Button("Problems");
		button_demo = new Button("Demo");
		
		//repositioning button_author
		button_author.setTranslateX(75);
		button_author.setTranslateY(10);
		//repositioning button_description
		button_description.setTranslateX(175);
		button_description.setTranslateY(10);
		//repositioning button_problems
		button_problems.setTranslateX(300);
		button_problems.setTranslateY(10);
		//repositioning button_demo
		button_demo.setTranslateX(400);
		button_demo.setTranslateY(10);
		
		//adding fuction to buttons
		//creating a new EventHandler that takes an ActionEvent (click) and ovverride the handle method
		button_author.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				//clears pane_hold
				pane_hold.getChildren().clear();
				//add text_author to pane_hold
				pane_hold.getChildren().add(text_author);
			}
		});
		button_description.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				//clears pane_hold
				pane_hold.getChildren().clear();
				//add text_description to pane_description
				pane_hold.getChildren().add(text_description);
			}
		});
		button_problems.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				//clears pane_hold
				pane_hold.getChildren().clear();
				//add text_problems to pane_hold
				pane_hold.getChildren().add(text_problems);
			}
		});
		button_demo.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				//clears pane_hold
				pane_hold.getChildren().clear();
				//add Circles demo from homework 3 to pane_hold
				pane_hold.getChildren().add(pane_demo);
			}
		});
	}
	
	//initilaze text and set their location
	public void initializeText() {
		//initilaze text
		text_author = new Text();
		text_description = new Text();
		text_problems = new Text();
		
		//set the text of text_author
		text_author.setText("Jimmy Lin.\nComputer Science\nHomework 4");
		text_author.setTranslateX(160);
		text_author.setTextAlignment(TextAlignment.CENTER);
		text_author.setFill(Color.RED);
		text_author.setFont(new Font(20));
		//set the text of text_description
		text_description.setText("Create a stage with several buttons.\nWhen the buttons are clicked they will show: \n\tAuthor, \n\tDescription of problem, \n\tProblems encountered, \n\tand Demo from homework 3");
		//set the text of text_problems
		text_problems.setText("Problems I ran into was creating action events for buttons");
	}
	
	//---------Start of Circles demo from Homework 3-------
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
		
		createCircle(x1, y1, r1, 0, 0, 255);
		createCircle(x2, y2, r2, 255, 0, 0);
		
		//determine what type of circle/intersection is formed
		//perform math functions on variables
		math = sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
			
		//determine if circles touch/overlap
		if(math == 0 && r1 == r2) {
			str = "Identical";
		}
		else if(math > (r1+r2)) {
			str = "Disjoint";
		}
		else if(math == (r1+r2)) {
			str = "Touch externally";
		}
		else if(math == abs(r1-r2)) {
			str = "Touch Internally";
		}
		else if(math < abs(r1-r2)) {
			str = "One is inside the other";
		}
		else if(math < (r1+r2)) {
			str = "Properly overlap";
		}
		
		//set label to show results
		label = new Label(str);
		//add label to pane
		pane_demo.getChildren().addAll(label);
	}
	
	//create circles
	public void createCircle(double x, double y, double radius, int r, int g, int b) {
		//create circle object
		Circle circle = new Circle();
		//determines where the circle is placed on X axis
		circle.setCenterX(x);
		//determines where the circle is placed on Y axis
		circle.setCenterY(y);
		//deermines radius of circles
		circle.setRadius(radius);
		//set the color of the outline of circle
		circle.setStroke(Color.BLACK);
		//set color of circle
		circle.setFill(Color.rgb(r, g, b, .4));
		//adds circle to pane
		pane_demo.getChildren().add(circle);
		
	}
	//------------End of Circles demo from Homework 3-----------
}
