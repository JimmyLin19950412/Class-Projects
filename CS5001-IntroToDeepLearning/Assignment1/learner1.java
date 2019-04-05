//Author: Jimmy Lin
//Homework: Homework 1
//Class: CS 5001 Intro to Deep Learning
//Due Date: October 08, 2018

//BufferedReader
import java.io.BufferedReader;
//FileReader
import java.io.FileReader;
//IOExceptiom
import java.io.IOException;
//File
import java.io.File;
//FileNotFoundException
import java.io.FileNotFoundException;

//Scanner
import java.util.Scanner;
//Random
import java.util.Random;
//InputMismatchException
import java.util.InputMismatchException;



public class learner1 {
	public static void main(String[] args) {
		//String to hold training data
		String trainingFile = "trashdata.txt";
		
		//String to hold testing data
		String testingFile = "moretrashdata.txt";
		
		//holds seed used to generate random number
		int seed = 1234567890;
		
		//holds sum-of-squares error (SSE)
		Double SSE = 0.0;
		
		//eta or learning rate
		Double eta = 0.000000000000001;	
			
		//object to generate random numbers
		Random rand = new Random();
		
		//array to holw weights
		//weights, initially randomized
		Double[] weight = new Double[2];
		for(int i = 0; i < weight.length; i++) {
			//random number fromm 0-100
			//rand,nextDouble() * (max - min) + min
			weight[i] = rand.nextDouble() * (100-0) + 0;
		}

		//calls determineLines method to count number of lines in file
		//2d array to hold training data
		Double[][] trainingData = new Double[determineLines(trainingFile)][2];
		
		//calls determineLines methd to count number of lines in file
		//2d array to hold testing data
		Double[][] testingData = new Double[determineLines(testingFile)][2];
		
		//populate trainingData array
		read(trainingData, trainingFile);
		
		//populat testingData array
		read(testingData, testingFile);
		
		//perform incremental linear learner
		incrementalLinearLearner(trainingData, eta, weight, trainingFile);
		
		//measure error with sum-of-squares error
		SSE = measureError(testingData, testingFile, SSE, weight);
		
		//prints output
		output(seed, eta,weight, SSE);
	}
	
	//determine number of lines in a file
	public static int determineLines(String file) {
		//holds the number of lines in a file
		int lines = 0;
		
		//Determining the number of lines in file
		try {
			BufferedReader reader = new BufferedReader(new FileReader(file));
			//reads each line in a file, if not at end of file lines++
			while(reader.readLine() != null) {
				lines++;
			}
			reader.close();
		
			return lines;
		}
		catch(IOException e) {
			System.out.println(e.getMessage());
		}
		return lines;
	}
	
	//reads in from file and populates array with data from file
	public static void read(Double[][] array, String file) {
		//try to read from file with scanner, if file is not found throw a hissy fit catch
		try {
			//scanner object that reads from file
			Scanner scanner = new Scanner(new File(file));
			
			//try to read numbers from file, if number is not what the scanner likes throw a hissy fit catch
			//BUZZ LIGHTYEAR TO WOODY
			//"TRY CATCH STATEMENTS"
			//"TRY CATCH STATEMENTS EVERYWHERE"
			try {
				//populates array
				//NOTE: 2D ARRAYS IN JAVA ARE STUPID. C++ FTW
				for(int i = 0; i < determineLines(file); i++) {
					for(int j = 0; j < 2; j++) {
						array[i][j] = scanner.nextDouble();
					}
				}
			}
			catch(InputMismatchException e) {		
				System.out.println(e.getMessage());
			}
			
		}
		catch(FileNotFoundException e) {
			System.out.println(e.getMessage());
		}
		
	}
	
	//performs incremental linear learner with given parameters:
	//array that contains training data
	//eta
	//array that contains weights
	//file that contains training data
	public static void incrementalLinearLearner(Double[][] array, Double eta, Double[] weight, String file) {
		//for loop to go through training data 5000 times
		for(int i = 0; i < 5000; i++) {
			//go through each line in training data
			for(int k = 0; k < determineLines(file); k++) {
				//computing yCap
				Double yCap = (weight[0]*1) + (weight[1]*array[k][0]);
				//computing delta
				Double delta = array[k][1] - yCap;
				//updating weights
				weight[0] = weight[0] + eta * delta * 1;
				weight[1] = weight[1] + eta * delta * array[k][0];
			}
		}
	}
	
	//measure error with sum-of-squares error with given parameters:
	//array that contains testing data
	//file that contains testing data
	//Initial SSE value
	//aray that holds the weights
	public static double measureError(Double[][] array, String file, Double SSE, Double[] weight) {
		//perform sum-of-squares error (SSE)
		for(int i = 0; i < determineLines(file); i++) {
			//computing yCap for SSE
			Double yCap = (weight[0]*1) + (weight[1]*array[i][0]);
			//computing SSE
			SSE = SSE + (array[i][1] - yCap)*(array[i][1] - yCap);
		}
		
		return SSE;
	}
	
	//prints output with given parameters:
	//seed used to generate random
	//eta, w0, w1
	//sum-of-squares error
	public static void output(int seed, Double eta, Double[] weight, Double SSE) {
		System.out.println("CS-5001: HW#1");
		System.out.println("Programmer: Jimmy Lin");
		System.out.println("\nTraining");
		System.out.println("Using random seed = " + seed);
		System.out.println("Using learning rate eta = " + eta);
		System.out.println("After 5000 iterations:");
		System.out.println("Weights:");
		System.out.println("w0 = " + weight[0]);
		System.out.println("w1 = " + weight[1]);
		System.out.println("\nValidation");
		System.out.println("Sum-of-Squares Error = " + SSE);
	}
}