//Author: Jimmy Lin
//Assignment: Homework 7
//Class: CS 5405 Java
//Due Date: October 30, 2018

package code; //places compiled code into code directory

import javafx.stage.Stage; //Stage
import javafx.scene.Scene; //Scene
import javafx.scene.layout.Pane; //Panes
import javafx.application.Application; //Abstract class Application
import javafx.scene.paint.Color; //Color
import javafx.event.ActionEvent; //ActionEvent
import javafx.event.EventHandler; //EventHandler
import javafx.scene.control.Button; //Button
import javafx.scene.text.Text; //Text
import javafx.scene.text.Font; //Font
import javafx.scene.text.TextAlignment; //TextAlignment
//--
import javafx.scene.shape.Polyline; //Polyline
import javafx.scene.shape.Line; //Line
import javafx.scene.input.MouseEvent; //MouseEvent

public class Demo extends Application {
	//creating the panes
	//creating object pane to hold the root/all other panes and objects
	Pane root = new Pane();
	//creating object pane for demo
	Pane pane_demo = new Pane();
	//creating object pane to hold other panes
	Pane pane_hold = new Pane();
	//intializes scene
	Scene scene;
	
	//creating buttons
	Button button_author;
	Button button_description;
	Button button_reference;
	Button button_demo;
	
	//creating text
	Text text_author;
	Text text_description;
	Text text_problems;
	
	//determine which polyline is being drawn
	//initialized to 1 since user will always start at 1 polylie being drawn
	int polylineNumber = 1;

	//determine if first line has been drawn yet or not
	boolean first = true;
	
	//creates first line
	Line lineOne = new Line();
	//creates second line
	Line lineTwo = new Line();
	//creates first polyline
	Polyline polylineOne = new Polyline();
	//creates second polyline
	Polyline polylineTwo = new Polyline();
	
	//holds the position of lines
	double startX;
	double startY;
	double endX;
	double endY;
		
	//overrides the start method in Application class
	//executes method at start of program
	@Override
	public void start(Stage stage)	{	
		//calls method to initilze text
		initializeText();
		
		//calls method to initilaze buttons
		initializeButton(stage);
		
		//repositioning and resizing pane_hold
		pane_hold.setPrefSize(490,400);
		pane_hold.setTranslateX(10);
		pane_hold.setTranslateY(100);
		pane_demo.setPrefSize(450,400);
		
		//initially add pane_author to text_hold
		pane_hold.getChildren().add(text_author);
		
		//adding buttons and pane to root
		root.getChildren().addAll(button_author, button_description, button_reference, button_demo, pane_hold);
		//placing root onto scene with dimensions of 500x500 background color = GRAY
		scene = new Scene(root, 500, 500, Color.GRAY);
		//placing the scene onto the stage
		stage.setScene(scene);
		//setting title for the stage
		stage.setTitle("Homework 7");
		//showing the stage
		stage.show();
	}
	
	//initilaze buttons and set their location
	public void initializeButton(Stage stage) {
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
				//clear pane_demo
				pane_demo.getChildren().clear();
				//resets variables
				polylineNumber = 1;
				first = true;
				lineOne = new Line();
				lineTwo = new Line();
				polylineOne = new Polyline();
				polylineTwo = new Polyline();
				//initialize creation of polylines
				createPolyline();
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
		text_author.setText("Jimmy Lin.\nComputer Science\nHomework 7\nEmail: jl79f@mst.edu\nCode belongs to Jimmy Lin");
		text_author.setTranslateX(120);
		text_author.setTextAlignment(TextAlignment.CENTER);
		text_author.setFill(Color.RED);
		text_author.setFont(new Font(20));
		//set the text of text_description
		text_description.setText("Draw two free polylines. One click to start polyline. Doubleclick to end current polyline\nDemo button clears drawing area");
		//set the text of text_problems
		text_problems.setText("References used: Past homeworks that used curcles\nand Lectures");
	}
	
	//creates polylines
	public void createPolyline() {
		//changing the properties of polylines and lines
		polylineOne.setStrokeWidth(3);
		polylineTwo.setStrokeWidth(3);
		polylineOne.setStroke(Color.BLUE);
		polylineTwo.setStroke(Color.RED);
		lineOne.setStroke(Color.PURPLE);
		lineTwo.setStroke(Color.PURPLE);
		
		//when mouse is moved
		pane_demo.setOnMouseMoved(e -> {
			//if number of polylines is less than 2 = not done drawing
			if(polylineNumber <= 2) {
				//not first line being drawn
				if(first == false) {
					//get end position of line from mouse position
					endX = e.getX();
					endY = e.getY();
					//if drawing line for first polyline
					if(polylineNumber == 1) {
						//set start position of line
						lineOne.setStartX(startX);
						lineOne.setStartY(startY);
						//set end position of line;
						lineOne.setEndX(endX);
						lineOne.setEndY(endY);
					}
					//if drawing line for second polyline
					else if(polylineNumber == 2) {
						//set start position of line
						lineTwo.setStartX(startX);
						lineTwo.setStartY(startY);
						//set end position of line;
						lineTwo.setEndX(endX);
						lineTwo.setEndY(endY);
					}
				}
			}
		});
		
		//when mouse is clicked
		pane_demo.setOnMouseClicked(e -> {
			//gets current mouse position
			double x = e.getX();
			double y = e.getY();
			
			//one click draw
			//if number of polylines is less than 2 = not done drawing
			if(polylineNumber <= 2){
				//first line being drawn
				if(first == true) {
					//set first to false since not fist line being drawn anymore
					first = false;
					startX = x;
					startY = y;
					//if on first polyline
					if(polylineNumber == 1) {
						//set start positions of the line
						lineOne.setStartX(startX);
						lineOne.setStartY(startY);
						//set end position of the line
						lineOne.setEndX(x);
						lineOne.setEndY(y);
						//add coordinates to polyline
						polylineOne.getPoints().addAll(x, y);
						//add polyline and line to pane_demo
						pane_demo.getChildren().addAll(polylineOne, lineOne);
					}
					else if(polylineNumber == 2) {
						//set start positions of the line
						lineTwo.setStartX(startX);
						lineTwo.setStartY(startY);
						//set end position of the line
						lineTwo.setEndX(x);
						lineTwo.setEndY(y);
						//add coordinates to polyline
						polylineTwo.getPoints().addAll(x, y);
						//add polyline and line to pane_demo
						pane_demo.getChildren().addAll(polylineTwo, lineTwo);
					}
				}
				//not first line being drawn
				else {
					//set end position
					endX = x;
					endY = y;
					//drawing first polyline
					if(polylineNumber == 1) {
						//adding points to polyline
						polylineOne.getPoints().addAll(x, y);
					}
					//drawing second polyline
					else if (polylineNumber == 2) {
						//adding points to polyline
						polylineTwo.getPoints().addAll(x, y);
					}
					//set start position
					startX = x;
					startY = y;
				}
			}
			//two+ clicks, stop drawing
			if(e.getClickCount() > 1) {
				//get end positions from mouse position
				endX = e.getX();
				endY = e.getY();
				//stop drawing current line
				//add one to polylineNumber to signal a new line is being drawn
				polylineNumber++;
				//reset first line variable
				first = true;
			}
		});
		
	}
}