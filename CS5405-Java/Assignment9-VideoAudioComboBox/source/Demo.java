//Author: Jimmy Lin
//Assignment: Homework 9
//Class: CS 5405 Java
//Due Date: November 27, 2018

package code; //places compiled code into code directory

import java.util.ArrayList; //ArrayList
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
import javafx.scene.image.Image; //Image
import javafx.scene.image.ImageView; //ImageView
import javafx.scene.control.Label; //Label

import java.io.File; //File
import javafx.scene.control.ComboBox; //ComboBox
import javafx.scene.media.Media; //Media
import javafx.scene.media.MediaPlayer; //MediaPlayer
import javafx.scene.media.MediaView; //MediaView
import javafx.util.Duration; //Duration
import javafx.scene.media.AudioClip; //AudioClip

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
	Button button_videoDemo;
	Button button_audioDemo;
	
	//creating text
	Text text_author;
	Text text_description;
	Text text_problems;
	
	//image objects for buttons
	ImageView descriptionImage = new ImageView(new Image("images/description.png", 10, 10, false, false));
	ImageView referenceImage = new ImageView(new Image("images/reference.png", 10, 10, false, false));
	ImageView videoImage = new ImageView(new Image("images/demo.png", 10, 10, false, false));
	ImageView audioImage = new ImageView(new Image("images/demo.png", 10, 10, false, false));
	ImageView authorImage = new ImageView(new Image("images/author.jpg", 10, 10, false, false));
	ImageView authorImage2 = new ImageView(new Image("images/author.jpg", 50, 50, false, false));
	
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
		
		authorImage2.setTranslateX(200);
		authorImage2.setTranslateY(200);
		
		//initially add pane_author to text_hold
		pane_hold.getChildren().addAll(text_author, authorImage2);
		
		//adding buttons and pane to root
		root.getChildren().addAll(button_author, button_description, button_reference, button_videoDemo, button_audioDemo, pane_hold);
		//placing root onto scene with dimensions of 500x500 background color = GRAY
		scene = new Scene(root, 500, 500, Color.GRAY);
		//placing the scene onto the stage
		stage.setScene(scene);
		//setting title for the stage
		stage.setTitle("Homework 9");
		//showing the stage
		stage.show();
	}
	
	//initilaze buttons and set their location
	public void initializeButton() {
		//initilize buttons
		button_author = new Button("Author", authorImage);
		button_description = new Button("Description", descriptionImage);
		button_reference = new Button("Reference", referenceImage);
		button_videoDemo = new Button("Video Demo", videoImage);
		button_audioDemo = new Button("Audio Demo", audioImage);
		
		//repositioning button_author
		button_author.setTranslateX(5);
		button_author.setTranslateY(10);
		//repositioning button_description
		button_description.setTranslateX(90);
		button_description.setTranslateY(10);
		//repositioning button_problems
		button_reference.setTranslateX(200);
		button_reference.setTranslateY(10);
		//repositioning button_videoDemo
		button_videoDemo.setTranslateX(300);
		button_videoDemo.setTranslateY(10);
		//repositioning button_audioDemo
		button_audioDemo.setTranslateX(400);
		button_audioDemo.setTranslateY(10);
		
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
		button_videoDemo.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				//clears pane_hold
				pane_hold.getChildren().clear();
				//clears pane_demo
				pane_demo.getChildren().clear();
				//add Circles demo from homework 3 to pane_hold
				pane_hold.getChildren().add(pane_demo);
				//calls video demo
				videoDemo();
			}
		});
		button_audioDemo.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent e) {
				//clears pane_hold
				pane_hold.getChildren().clear();
				//clears pane_demo
				pane_demo.getChildren().clear();
				//add Circles demo from homework 3 to pane_hold
				pane_hold.getChildren().add(pane_demo);
				//calls video demo
				audioDemo();
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
		text_author.setText("Jimmy Lin.\nComputer Science\nHomework 9\nEmail: jl79f@mst.edu\nCode belongs to Jimmy Lin");
		text_author.setTranslateX(120);
		text_author.setTextAlignment(TextAlignment.CENTER);
		text_author.setFill(Color.RED);
		text_author.setFont(new Font(20));
		//set the text of text_description
		text_description.setText("Create a stage with several buttons.\nWhen the buttons are clicked they will show: \n\tAuthor, \n\tDescription of problem, \n\treference used, \ndemo \n\tdemo will let user play one of five video or audio clips from a menu. the user can also replace the menu options with their own list");
		//set the text of text_problems
		text_problems.setText("References used:Lectures and demos \nImages from https://pngtree.com/ \nVideos and audios from https://www.videvo.net/stock-video-footage/seconds/");
	}
	
	//creates layout for video demo
	public void videoDemo() {
		//new combobox
		ComboBox selection = new ComboBox();
		
		//obtain directory
		File directory = new File("videos");
		//obtain list of all files in directory
		File[] fList = directory.listFiles();
		
		//loop through fList and add its elements to combobox
		for(File file : fList) {
			selection.getItems().add(file);
		}
		
		//reposition combobox
		selection.setTranslateY(300);
		
		//add action when a selection is made in combobox
		selection.getSelectionModel().selectedItemProperty().addListener((v, oldvalue, newValue) -> {
			//new file object with value of selected from combobox
			File file = new File(selection.getValue().toString());
			//create a new media object with the value that is selected in combobox
			Media media = new Media(file.toURI().toString());
			//initialize MediaPlayer and MediaView
			MediaPlayer mediaPlayer = new MediaPlayer(media);
			MediaView mediaView = new MediaView(mediaPlayer);
			mediaView.setFitWidth(300);
			mediaView.setFitHeight(300);
			//buttons to control MediaPlayer
			Button play = new Button(">");
			play.setOnAction(e -> {
				if(play.getText().equals(">")) {
					mediaPlayer.play();
					play.setText("||");
				}
				else {
					mediaPlayer.pause();
					play.setText(">");
				}
			});
			//reposition play button
			play.setTranslateY(200);
			
			//add MediaView and play button to pane
			pane_demo.getChildren().addAll(mediaView, play);
		});
		
		//add elements to pane_demo
		pane_demo.getChildren().add(selection);
	}
	
	//creates layout for audio demo
	public void audioDemo() {
		//new combobox
		ComboBox selection = new ComboBox();
		
		//obtain directory
		File directory = new File("audios");
		//obtain list of all files in directory
		File[] fList = directory.listFiles();
		
		//loop through fList and add its elements to combobox
		for(File file : fList) {
			selection.getItems().add(file);
		}
		
		//reposition combobox
		selection.setTranslateY(300);
		
		//add action when a selection is made in combobox
		selection.getSelectionModel().selectedItemProperty().addListener((v, oldvalue, newValue) -> {
			//new file object with value of selected from combobox
			File file = new File(selection.getValue().toString());
			//create a new audio object with the value that is selected in combobox
			AudioClip audioClip = new AudioClip(file.toURI().toString());
			//buttons to control audio
			Button play = new Button(">");
			play.setOnAction(e -> {
				if(play.getText().equals(">")) {
					audioClip.play();
					play.setText("||");
				}
				else {
					audioClip.stop();
					play.setText(">");
				}
			});
			
			//position play button
			play.setTranslateY(200);
			
			//add play button to pane
			pane_demo.getChildren().add(play);
		});
		
		//add elements to pane_demo
		pane_demo.getChildren().add(selection);
	}
}