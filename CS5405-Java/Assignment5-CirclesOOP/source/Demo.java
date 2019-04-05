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
//TextField
import javafx.scene.control.TextField;
//KeyEvent
import javafx.scene.input.KeyEvent;
//KeyCode
import javafx.scene.input.KeyCode;
//SimpleDoubleProperty
import javafx.beans.property.SimpleDoubleProperty;
import javafx.beans.property.DoubleProperty;


public class Demo extends Application {
	//initilizes Scanner
	Scanner readFile;
	Scanner readTextField;
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
	Button button_reference;
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
		root.getChildren().addAll(button_author, button_description, button_reference, button_demo, pane_hold);
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
		button_reference = new Button("Reference");
		button_demo = new Button("Demo");
		
		//repositioning button_author
		button_author.setTranslateX(75);
		button_author.setTranslateY(10);
		//repositioning button_description
		button_description.setTranslateX(175);
		button_description.setTranslateY(10);
		//repositioning button_problems
		button_reference.setTranslateX(300);
		button_reference.setTranslateY(10);
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
		button_reference.setOnAction(new EventHandler<ActionEvent>() {
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
		text_description.setText("Create a stage with several buttons.\nWhen the buttons are clicked they will show: \n\tAuthor, \n\tDescription of problem, \n\tProblems encountered, \n\tand Demo from homework 3. Demo will read from file and place into TextField. Circle parameters will read from TextField");
		//set the text of text_problems
		text_problems.setText("References used: Useful hints from homework 5");
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
		
		//try to read from file
		try {
			//read from file
			readFile = new Scanner(new File("data/inFile.txt"));
	
			//create TextField object
			TextField input = new TextField();
			//reloacte TextField input
			input.relocate(230, 0);
			//set width of TextField input
			input.setPrefWidth(220);
			
			//read next line in file and places it into textfield
			input.setText(readFile.nextLine());
			
			//create new scanner to read from TextField input
			readTextField = new Scanner(input.getText());
			
			x1 = readTextField.nextDouble();
			y1 = readTextField.nextDouble();
			r1 = readTextField.nextDouble();
			x2 = readTextField.nextDouble();
			y2 = readTextField.nextDouble();
			r2 = readTextField.nextDouble();
			
			//set label to show results
			label = new Label(determineCircle(x1, y1, r1, x2, y2, r2));
			//reloacte TextField input
			label.relocate(200, 30);
			//add label to pane
			pane_demo.getChildren().addAll(label, input);
			
			//creates circles
			Circle circle1 = createCircle(x1, y1, r1, 0, 0, 255);
			Circle circle2 = createCircle(x2, y2, r2, 255, 0, 0);
			
			//adds circle to pane
			pane_demo.getChildren().add(circle1);
			pane_demo.getChildren().add(circle2);
			
			//when enter key is pressed, textfield changes
			input.setOnKeyPressed(new EventHandler<KeyEvent>() {
				@Override
				public void handle(KeyEvent keyEvent) {
					//on enter key
					if(keyEvent.getCode() == KeyCode.ENTER) {
						//read next line in file and place in textfield
						input.setText(readFile.nextLine());
						//new scanner to read from textfield
						readTextField = new Scanner(input.getText());	
						//first value is x1
						DoubleProperty x1 = new SimpleDoubleProperty(readTextField.nextDouble());
						//second value is y1
						DoubleProperty y1 = new SimpleDoubleProperty(readTextField.nextDouble());
						//third value is r1
						DoubleProperty r1 = new SimpleDoubleProperty(readTextField.nextDouble());
						//fourth value is x2
						DoubleProperty x2 = new SimpleDoubleProperty(readTextField.nextDouble());
						//fifth value is y2
						DoubleProperty y2 = new SimpleDoubleProperty(readTextField.nextDouble());
						//sixth value is r2
						DoubleProperty r2 = new SimpleDoubleProperty(readTextField.nextDouble());
						//binds the property of circles so when a variable changes so does the dimension of the circle
						circle1.centerXProperty().bind(x1);
						circle1.centerYProperty().bind(y1);
						circle1.radiusProperty().bind(r1);
						circle2.centerXProperty().bind(x2);
						circle2.centerYProperty().bind(y2);
						circle2.radiusProperty().bind(r2);
						//create new scanner to read from textfield
						readTextField = new Scanner(input.getText());
						//update label
						label.setText(determineCircle(readTextField.nextDouble(), readTextField.nextDouble(), readTextField.nextDouble(), readTextField.nextDouble(), readTextField.nextDouble(), readTextField.nextDouble()));
					}
				}				
			});
		}
		//fail to read from file
		catch(Exception e) {
			//error message
			System.out.println("Unable to read file");
		}
	}
	
	//create circles
	public Circle createCircle(double x, double y, double radius, int r, int g, int b) {
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
		
		return circle;
	}
	
	//determines type of circle
	public String determineCircle(Double x1, Double y1, Double r1, Double x2, Double y2, Double r2) {
		//determine what type of circle/intersection is formed
		//perform math functions on variables
		double math = sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
			
		//determine if circles touch/overlap
		if(math == 0 && r1 == r2) { 
			return "Identical"; //1
		}
		else if(math >= (r1+r2)) {
			if(math > (r1+r2)) {
				return "Outside each other. Disjoint"; //2
			}
			else if(math == (r1+r2)) {
				return "Outside each other. Touch exernally"; //3
			}
		}
		else if(math <= (r2-r1)) {
			if(math < (r2-r1)) {
				return "Circle1 is inside circle2 and does not touch circle2"; //4
			}
			else if(math == (r2-r1)) {
				return "Circle1 touches circle2 from inside"; //5
			}
		}
		else if(math <= (r1-r2)) {
			if(math < (r1-r2)) {
				return "Circle2 is inside circle1 and does not touch circle1"; //6
			}
			else if(math == (r1-r2)) {
				return "Circle2 touches circle1 from inside"; //7
			}
		}
		else {
			return "Circle1 and circle2 have proper overlap"; //8
		}
		return "";
	}
	//------------End of Circles demo from Homework 3-----------
}
