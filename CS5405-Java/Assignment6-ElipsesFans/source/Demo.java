//Author: Jimmy Lin
//Assignment: Homework 6
//Class: CS 5405 Java
//Due Date: October 23, 2018

package code; //places compiled code into code directory

import javafx.stage.Stage; //Stage
import javafx.scene.Scene; //Scene
import javafx.scene.layout.Pane; //Panes
import javafx.application.Application; //Abstract class Application
import javafx.scene.paint.Color; //Color
import javafx.event.ActionEvent; //ActionEvent
import javafx.event.EventHandler; //EventHandler
import javafx.scene.shape.Circle; //Circle
import javafx.scene.control.Button; //Button
import javafx.scene.text.Text; //Text
import javafx.scene.text.Font; //Font
import javafx.scene.text.TextAlignment; //TextAlignment
import javafx.scene.shape.Arc; //Arc
import javafx.scene.shape.ArcType; //ArcType

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
		
		//initially add pane_author to text_hold
		pane_hold.getChildren().add(text_author);
		
		//adding buttons and pane to root
		root.getChildren().addAll(button_author, button_description, button_reference, button_demo, pane_hold);
		//placing root onto scene with dimensions of 500x500 background color = GRAY
		scene = new Scene(root, 500, 500, Color.GRAY);
		//placing the scene onto the stage
		stage.setScene(scene);
		//setting title for the stage
		stage.setTitle("Homework 6");
		//showing the stage
		stage.show();
		
		//calls method createFan to creat the fans
		createFan(stage);
	}

	public static void main() {
		
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
				//clears pane_demo
				pane_demo.getChildren().clear();
				//add text_author to pane_hold
				pane_hold.getChildren().add(text_author);
			}
		});
		button_description.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				//clears pane_hold
				pane_hold.getChildren().clear();
				//clears pane_demo
				pane_demo.getChildren().clear();
				//add text_description to pane_description
				pane_hold.getChildren().add(text_description);
			}
		});
		button_reference.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				//clears pane_hold
				pane_hold.getChildren().clear();
				//clears pane_demo
				pane_demo.getChildren().clear();
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
				createFan(stage);
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
		text_author.setText("Jimmy Lin.\nComputer Science\nHomework 6\nEmail: jl79f@mst.edu\nCode belongs to Jimmy Lin");
		text_author.setTranslateX(120);
		text_author.setTextAlignment(TextAlignment.CENTER);
		text_author.setFill(Color.RED);
		text_author.setFont(new Font(20));
		//set the text of text_description
		text_description.setText("Create a stage with several buttons.\nWhen the buttons are clicked they will show: \n\tAuthor, \n\tDescription of problem, \n\treference used, \n\tand generating a fan that can be called n times");
		//set the text of text_problems
		text_problems.setText("References used: Past homeworks that used curcles\nand Lectures");
	}
	
	//creates fan
	public void createFan(Stage stage) {
		double x = stage.getWidth() / 2;
		double y = stage.getHeight() / 4;
		double radius = 100;
		
		//create outer circle
		Circle outerCircle = createCircle(x, y, radius, Color.PURPLE, 0, 0, 0, 0);
		
		//create middle circle
		Circle middleCircle = createCircle(x, y, radius/2, Color.BLUE, 20, 100, 0, .4);
		
		//create inner circle
		Circle innerCircle = createCircle(x, y, radius/4, Color.RED, 0, 0, 255, 1);
		
		//creates arcs
		Arc arc1 = createArc(x, y, 80, 80, 50, 35);
		Arc arc2 = createArc(x, y, 80, 80, 140, 35);
		Arc arc3 = createArc(x, y, 80, 80, 230, 35);
		Arc arc4 = createArc(x, y, 80, 80, 320, 35);
		
		//create arcs/fan blades?
		
		//add all the elements that create a fan onto pane_demo
		pane_demo.getChildren().addAll(outerCircle, middleCircle, innerCircle, arc1, arc2, arc3, arc4);
	}
	
	//creates circle with given parameters
	//double x, y, radius to determine size and location of circle
	//Color color to determine the color of the outline of the circle
	//int r g b to determine color of circle
	//double opacity to determine opacity of circle
	public Circle createCircle(double x, double y, double radius, Color color, int r, int g, int b, double opacity) {
		//creates new circle object
		Circle circle = new Circle();
		//places circle on X axis
		circle.setCenterX(x);
		//places circle on Y axis
		circle.setCenterY(y);
		//determine radius of circle
		circle.setRadius(radius);
		//set the color of the outline of circle
		circle.setStroke(color);
		//set color of the circle
		circle.setFill(Color.rgb(r, g, b, opacity));
		
		return circle;
	}
	
	//creates arcs
	//double x, y, radiusx, radiusy to determine size and location of arc
	//double angle to determine the starting angle of the arc
	//double length to determine length of arc
	public Arc createArc(double x, double y, double radiusx, double radiusy, double angle, double length) {
		//creates new object arc
		Arc arc = new Arc();
		
		//x center of arc
		arc.setCenterX(x);
		//y center of arc
		arc.setCenterY(y);
		//x radius of arc
		arc.setRadiusX(radiusx);
		//y radius of arc
		arc.setRadiusY(radiusy);
		//starting angle of arc
		arc.setStartAngle(angle);
		//length of arc
		arc.setLength(length);
		//type of arc
		arc.setType(ArcType.ROUND);
		//fill color of arc
		arc.setFill(Color.RED);
		
		return arc;
	}
}