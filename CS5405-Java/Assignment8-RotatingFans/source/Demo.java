//Author: Jimmy Lin
//Assignment: Homework 8
//Class: CS 5405 Java
//Due Date: November 15, 2018

package code; //places compiled code into code directory

import java.util.ArrayList; //ArrayList
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
import javafx.scene.control.Slider; //Slider
import javafx.scene.image.Image; //Image
import javafx.scene.image.ImageView; //ImageView
import javafx.scene.control.Label; //Label
import javafx.util.Duration; //Duration
import javafx.animation.Timeline; //Timeline
import javafx.animation.RotateTransition; //RotateTransition
import javafx.animation.Interpolator; //Interpolator

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
	
	//image objects for buttons
	ImageView descriptionImage = new ImageView(new Image("images/description.png", 10, 10, false, false));
	ImageView referenceImage = new ImageView(new Image("images/reference.png", 10, 10, false, false));
	ImageView demoImage = new ImageView(new Image("images/demo.png", 10, 10, false, false));
	ImageView authorImage = new ImageView(new Image("images/author.jpg", 10, 10, false, false));
	ImageView authorImage2 = new ImageView(new Image("images/author.jpg", 50, 50, false, false));
		
	//----- ROTATING FAN VARIABLES ---
	
	//new pane object to hold fan
	Pane pane_fan = new Pane();
	Pane pane_fan2 = new Pane();
	
	//variables to determine if startPause button is on start or on pause
	boolean start = true;
	
	//variables to determine if direction button is on clockwise or counterclockwise
	boolean clockwise = true;
	
	//RotateTransition object for animating fan
	RotateTransition fanRotate = new RotateTransition(Duration.millis(1000), pane_fan);
	
	//circles objects that are part of the fan
	Circle outerCircle;
	Circle middleCircle;
	Circle innerCircle;
	
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
		
		pane_fan.setMaxHeight(0);
		pane_fan.setMaxWidth(0);
		pane_fan.setTranslateX(250);
		pane_fan.setTranslateY(150);
		
		authorImage2.setTranslateX(200);
		authorImage2.setTranslateY(200);
		
		//initially add pane_author to text_hold
		pane_hold.getChildren().addAll(text_author, authorImage2);
		
		//adding buttons and pane to root
		root.getChildren().addAll(button_author, button_description, button_reference, button_demo, pane_hold);
		//placing root onto scene with dimensions of 500x500 background color = GRAY
		scene = new Scene(root, 500, 500, Color.GRAY);
		//placing the scene onto the stage
		stage.setScene(scene);
		//setting title for the stage
		stage.setTitle("Homework 8");
		//showing the stage
		stage.show();
	}
	
	//initilaze buttons and set their location
	public void initializeButton() {
		//initilize buttons
		button_author = new Button("Author", authorImage);
		button_description = new Button("Description", descriptionImage);
		button_reference = new Button("Reference", referenceImage);
		button_demo = new Button("Demo", demoImage);
		
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
				pane_fan2.getChildren().clear();
				//add text_author to pane_hold
				pane_hold.getChildren().addAll(text_author, authorImage2);
			}
		});
		button_description.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				//clears pane_hold
				pane_hold.getChildren().clear();
				//clears pane_demo
				pane_demo.getChildren().clear();
				pane_fan2.getChildren().clear();
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
				pane_fan2.getChildren().clear();
				//add text_problems to pane_hold
				pane_hold.getChildren().add(text_problems);
			}
		});
		button_demo.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				//clears pane_hold
				pane_hold.getChildren().clear();
				//clears pane_demo
				pane_demo.getChildren().clear();
				//add Circles demo from homework 3 to pane_hold
				pane_hold.getChildren().add(pane_demo);
				pane_demo.getChildren().addAll(pane_fan, pane_fan2);
				//create outer circle
				outerCircle = createCircle(250, 150, 100, Color.PURPLE, 0, 0, 0, 0);
				//create middle circle
				middleCircle = createCircle(250, 150, 50, Color.BLUE, 20, 100, 0, .4);
				//create inner circle
				innerCircle = createCircle(250, 150, 20, Color.RED, 0, 0, 255, 1);
				pane_fan2.getChildren().addAll(outerCircle, middleCircle, innerCircle);
				createPaneDemoLayout();
				fanRotate.stop();
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
		text_description.setText("Create a stage with several buttons.\nWhen the buttons are clicked they will show: \n\tAuthor, \n\tDescription of problem, \n\treference used, \n\tand generating a fan that can be called n times. The fans can also rotate.\nButton to stop, start, and pause fan.\nButton to change direction of fan\nSlider to change the amount of blades and speed of blades\nWhen you click on Demos, it shows the pane for Fan (HW06), now along with control buttons for animation start/resume, stop, slider to control the number of blades and speed. Recall Timeline class You may keep text along with icons.");
		//set the text of text_problems
		text_problems.setText("References used: Past homeworks that used curcles\nand Lectures\nImages from https://pngtree.com/\n RotateTransition: https://docs.oracle.com/javafx/2/api/javafx/animation/RotateTransition.html");
	}
	
	//creates layout for pane_demo
	public void createPaneDemoLayout() {
		fanRotate.setRate(1);
		//image object for start
		ImageView startImage = new ImageView(new Image("images/start.png", 75, 75, false, false));
		//image object for pause
		ImageView pauseImage = new ImageView(new Image("images/pause.png", 75, 75, false, false));
		//image object for stop
		ImageView stopImage = new ImageView(new Image("images/stop.png", 75, 75, false, false));
		//image object for clockwise
		ImageView clockwiseImage = new ImageView(new Image("images/clockwise.png", 75, 75, false, false));
		//image object for counterclockwise
		ImageView counterclockwiseImage = new ImageView(new Image("images/counterclockwise.png", 75, 75, false, false));
		//button object for starting and puasing fan
		Button startPause = new Button("", startImage);
		//button object for resetting fan
		Button direction = new Button("", clockwiseImage);
		//button object for stopping fan
		Button stop = new Button("", stopImage);
		//slider object to determine fan blades
		//minBlades, maxBlades, startingBlades
		Slider fanBlades = new Slider(0, 15, 4);
		//slider object to determine fan speed
		//minSpped, maxSpeed, startingSpeed
		Slider fanSpeed = new Slider(0, 15, 1);
		//Labels for Sliders
		Label fanBladesLabel = new Label("Fan Blades");
		Label fanSpeedLabel = new Label("Fan Speed");
		
		//changing properties of Sliders
		fanBlades.setShowTickLabels(true);
		fanSpeed.setShowTickLabels(true);
		fanBlades.setShowTickMarks(true);
		fanSpeed.setShowTickMarks(true);
		fanBlades.setMajorTickUnit(5);
		fanSpeed.setMajorTickUnit(5);
		fanBlades.setMinorTickCount(1);
		fanSpeed.setMinorTickCount(1);
		
		//change position of buttons sliders and labels
		startPause.setTranslateX(0);
		startPause.setTranslateY(0);
		stop.setTranslateX(0);
		stop.setTranslateY(80);
		direction.setTranslateX(0);
		direction.setTranslateY(160);
		fanBlades.setTranslateX(200);
		fanBlades.setTranslateY(0);
		fanSpeed.setTranslateX(200);
		fanSpeed.setTranslateY(300);
		fanBladesLabel.setTranslateX(148);
		fanBladesLabel.setTranslateY(0);
		fanSpeedLabel.setTranslateX(140);
		fanSpeedLabel.setTranslateY(300);
		
		
		//add nodes to pane_demo
		pane_demo.getChildren().addAll(startPause, stop, direction, fanBlades, fanSpeed, fanBladesLabel, fanSpeedLabel);
		
		//call method to create fan
		//passes the stage and the value from slider fanBlades
		createFan(fanBlades.getValue());
		
		//creates a listener for fanBlades slider. add or remove fan blades based off of value of slider
		fanBlades.valueProperty().addListener(oldValue -> createFan( fanBlades.getValue()));
		
		//creates listener for fanSpeed slider. increase or decrease fan speed based off of value of slider
		fanSpeed.valueProperty().addListener(oldValue -> {
			//creates a new fan with given values
			fanRotate.setDuration(Duration.millis(1000/fanSpeed.getValue()));
			fanRotate.stop();
			fanRotate.play();
		});
		
		//add functionality to startPause button
		startPause.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				//determine if button is set to show start of pause
				//if button is showing start
				if(start == true) {
					//set start to false cause now button is showing pause
					start = false;
					//change image to pause
					startPause.setGraphic(pauseImage);
					//start fan animation
					fanRotate.play();
				}
				//if button is showing pause
				else if(start == false) {
					//set start to true cause not button is showing start
					start = true;
					//change image to start
					startPause.setGraphic(startImage);
					//pause fan animation
					fanRotate.pause();
				}
			}
		});
		
		//adds functionality to stop button
		stop.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				//stops fan
				fanRotate.stop();
			}
		});
		
		//add functinality to direction button clockwise or counterclockwise button
		direction.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				//determine if button is set to show clockwise or counterclockwise
				//if button is showing clockwise
				if(clockwise == true) {
					//set clockwise to false cause now button is showing counterclockwise
					clockwise = false;
					//change image to counterclockwise
					direction.setGraphic(counterclockwiseImage);
					fanRotate.setRate(1);
				}
				//if button is showing counterclockwise
				else if (clockwise == false) {
					//set clockwise to true cause now button is showing clockwise
					clockwise = true;
					//change image to clockwise
					direction.setGraphic(clockwiseImage);
					fanRotate.setRate(-1);
				}
			}
		});
	}
	
	//creates fan
	public void createFan(double fanBlades) {
		//variables that determine the parameters of arc, fanBlades
		double n = 360/fanBlades;
		
		//reset pane_fan
		pane_fan.getChildren().clear();
		
		//determine speed of pathtransition
		//creates arcs based off of the number of fan blades
		for(double i = 0; i < fanBlades; i++) {
			//create a new arc based off of the given parameters
			Arc arc = createArc(0, 0, 80, 80, n, 20);
			//increase n, a parameter for creating arc, by 40
			n = n + 25;
			//add arc to pane_demo
			pane_fan.getChildren().add(arc);
		}
		
		//starting angle of fanRotate
		fanRotate.setFromAngle(0);
		//ending angle of fanRotate
		fanRotate.setByAngle(360);
		//how many times to spin
		fanRotate.setCycleCount(Timeline.INDEFINITE);
		fanRotate.setInterpolator(Interpolator.LINEAR);
		//ensures fanRotate does not auto reverse
		fanRotate.setAutoReverse(false);
	}
	
	//creates circle with given parametrers
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