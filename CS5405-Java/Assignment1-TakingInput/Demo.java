/*
Author: Jimmy Lin
Due Date: 09/03/18
Class: CS 5405 Java GUI & Visualization
Section: 1A
*/

//creates a code directory and places compiled code into it
package code;

//import library to use Scanner
import java.util.Scanner;

public class Demo
{  public static void main(String[] args)
    {   
		//variable to hold name
		String name;
		//variable to hold phone number
		String phoneNumber;
		//variable to hold address
		String address;
		
		//creates scanner object to read input
		Scanner scanner = new Scanner(System.in);
		
		//asks user for name
		System.out.println("What is your name?");
		//takes input and places it into string variable name
		name = scanner.nextLine();
		
		//asks user for phone number
		System.out.println("What is your phone number?");
		//takes input and places it into string variable phoneNumber
		phoneNumber = scanner.nextLine();
		
		//asks user for address
		System.out.println("What is your address?");
		//takes input and places it into string variable address
		address = scanner.nextLine();
		
		//prints out input
		System.out.println("\nName: " + name + "\nPhone: " + phoneNumber + "\nAddress: " + address);
    }
}
