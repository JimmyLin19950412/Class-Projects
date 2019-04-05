//Author: Jimmy Lin
//Homework: Homework 2
//Class: CS 5001 Intro to Deep Learning
//Due Date: December 14, 2018

import java.util.Scanner;
import java.text.DecimalFormat;
import java.math.RoundingMode;

public class hw2 {
    //2d array holding value of map
    //values: -1 = wall, 0 = blank spaces, 10 = cake, 3 = donut, -5 = fire, -10 = morales (no hate)
    static String map[][] = {
        {"wall", "wall", "wall", "wall", "wall", "wall", "wall", "wall", "wall", "wall"},
        {"wall", "0", "0", "0", "0", "0", "0", "0", "0", "wall"},
        {"wall", "0", "0", "0", "0", "donut", "0", "0", "0", "wall"},
        {"wall", "0", "wall", "wall", "0", "0", "0", "0", "0", "wall"},
        {"wall", "0", "fire", "0", "0", "wall", "wall", "0", "0", "wall"},
        {"wall", "0", "0", "0", "0", "wall", "0", "0", "0", "wall"},
        {"wall", "0", "0", "wall", "wall", "wall", "0", "cake", "0", "wall"},
        {"wall", "0", "0", "morales", "0", "0", "0", "0", "0", "wall"},
        {"wall", "0", "0", "0", "0", "0", "0", "0", "0", "wall"},
        {"wall", "wall", "wall", "wall", "wall", "wall", "wall", "wall", "wall", "wall"}
    };

    //z = 0 = up, z = 1 = right, z = 2 = down, z = 3 = left
    static Double Qnext[][][] = new Double[10][10][4];
    static Double Qprev[][][] = new Double[10][10][4];

    //holds discounted gamma (provided by assignment)
    static Double discountGamma = 0.8;

    public static void main(String[] args) {
        //creates DecimalFormat object that determines the number of decimal places
        DecimalFormat df = new DecimalFormat("#.###");
        //rounsd the last positional places of DecimalFormat down
        df.setRoundingMode(RoundingMode.FLOOR);
            
        //holds number of iterations to run (user provided)
        Integer numIterations;
        //holds numbe rof iterations ran so far
        Integer count = 0;

        //initialize Qprev and Qnext
        for(int y = 0; y < 10; y++) {
            for(int x = 0; x < 10; x++) {
                for (int z = 0; z < 4; z++) {
                    if(map[y][x].equals("wall")) {
                        Qprev[y][x][z] = -1.0;
                        Qnext[y][x][z] = -1.0;
                    }
                    else if(map[y][x].equals("cake")) {
                        Qprev[y][x][z] = 10.0;
                        Qnext[y][x][z] = 10.0;
                    }
                    else if(map[y][x].equals("donut")) {
                        Qprev[y][x][z] = 3.0;
                        Qnext[y][x][z] = 3.0;
                    }
                    else if(map[y][x].equals("fire")) {
                        Qprev[y][x][z] = -5.0;
                        Qnext[y][x][z] = -5.0;
                    }
                    else if(map[y][x].equals("morales")) {
                        Qprev[y][x][z] = -10.0;
                        Qnext[y][x][z] = -10.0;
                    }
                    else {
                        Qprev[y][x][z] = 0.0;
                        Qnext[y][x][z] = 0.0;
                    }
                }
            }
        }

        //scanner to detect user input
        Scanner scanner = new Scanner(System.in);

        //print basic data
        System.out.println("CS-5001: HW2:");
        System.out.println("Programmer: Jimmy Lin");
        System.out.println("Discount Gamma = " + discountGamma);

        //asks user for input, while loop until user input is less than 1
        do {
            //asks user for number of iterations
            System.out.print("Enter No of Iterations: ");
            //places user input into variable
            numIterations = scanner.nextInt();
            //call valueIterate method
            valueIterate(numIterations);
            //print count
            count = count + numIterations;
            System.out.println("Values after "+ count + " iterations:");
            //PRINT VALUE
            for(int y = 0; y < 10; y++) {
                for(int x = 0; x < 10; x++) {
                    if(map[y][x].equals("cake")) {
                        System.out.print("CAKE, ");
                    }
                    else if(map[y][x].equals("donut")) {
                        System.out.print("DONUT, ");
                    }
                    else if(map[y][x].equals("fire")) {
                        System.out.print("FIRE, ");
                    }
                    else if(map[y][x].equals("morales")) {
                        System.out.print("MORALES, ");
                    }
                    else {
                        System.out.print(df.format(value(y, x)) + ", ");
                    }
                }
                System.out.print("\n");
            }
        }while(numIterations > 0);

        //close scanner
        scanner.close();

        System.out.println("Policy: ");
        //PRINT POLICY
        for(int y = 0; y < 10; y++) {
            for(int x = 0; x < 10; x++) {
                if(map[y][x].equals("wall")) {
                    System.out.print("wall, ");
                }
                else if(map[y][x].equals("cake")) {
                    System.out.print("cake, ");
                }
                else if(map[y][x].equals("donut")) {
                    System.out.print("donut, ");
                }
                else if(map[y][x].equals("fire")) {
                    System.out.print("fire, ");
                }
                else if(map[y][x].equals("morales")) {
                    System.out.print("morales, ");
                }
                else {
                    System.out.print(getPolicy(y, x) + ", ");
                }
            }
            System.out.print("\n");
        }
    }

    public static void valueIterate(Integer numIterations) {
        //holds temporary value
        Double valTemp = 0.0;
        
        //loops numIterations time
        for(int tempNumIterations = 0; tempNumIterations < numIterations; tempNumIterations++) {
            for(int y = 0; y < 10; y++) {
                for(int x = 0; x < 10; x++) {
                    //if location is not a wall
                    if(!map[y][x].equals("wall") && !map[y][x].equals("cake") && !map[y][x].equals("donut") && !map[y][x].equals("fire") && !map[y][x].equals("morales")) {
                        //reset valtemp value
                        valTemp = 0.0;
                        for(int z = 0; z < 4; z++) {
                            //z=0=up, z=1=right, z=2=down, z=3=left
                            //cant go opposite direction of current direction
                            if(z == 0) {
                                //calculating up value
                                valTemp = valTemp + 0.82 * value(y-1, x);
                                //calculating right value
                                valTemp = valTemp + 0.09 * value(y, x+1);
                                //down value is always 0 since going up, no caluclations needed
                                //calculating left value
                                valTemp = valTemp + 0.09 * value(y, x-1);
                            }
                            else if(z == 1) {
                                //calculating up
                                valTemp = valTemp + 0.09 * value(y-1, x);
                                //calulating right
                                valTemp = valTemp + 0.82 * value(y, x+1);
                                //calculating down
                                valTemp = valTemp + 0.09 * value(y+1, x);
                                //left value is always - since going right, no calculations needed
                            }
                            else if(z == 2) {
                                //up value is always 0 since going down, no calculations needed
                                //calulating right
                                valTemp = valTemp + 0.09 * value(y, x+1);
                                //calculating down
                                valTemp = valTemp + 0.82 * value(y+1, x);
                                //calculating left value
                                valTemp = valTemp + 0.09 * value(y, x-1);
                            }
                            else if(z == 3) {
                                //calculating up
                                valTemp = valTemp + 0.09 * value(y-1, x);
                                //right value is always 0 since going left, no calculations needed
                                //calculating down
                                valTemp = valTemp + 0.09 * value(y+1, x);
                                //calculating left value
                                valTemp = valTemp + 0.82 * value(y, x-1);
                            }
                            Qnext[y][x][z] = expReward(y, x, z) + discountGamma * valTemp;
                        }
                    }
                }
            }
            //copy all contents of Qnext to Qprev
            //initialize Qprev to 0
            for(int y = 0; y < 10; y++) {
                for(int x = 0; x < 10; x++) {
                    for (int z = 0; z < 4; z++) {
                        Qprev[y][x][z] = Qnext[y][x][z];
                    }
                }
            }
        }
    }

    public static Double value(int y, int x) {
        //holds v value
        Double v = -1000000.00;

        //perform all actions, up, down, left and right to determine max value
        //up
        //up value
        v = Math.max(v, Qprev[y][x][0]);
        //right value
        v = Math.max(v, Qprev[y][x][1]);
        //down value
        v = Math.max(v, Qprev[y][x][2]);
        //left value
        v = Math.max(v, Qprev[y][x][3]);

        return v;
    }

    public static Double expReward(int y, int x, int z) {
        //holds res value
        Double res = 0.0;
            
        //cant go opposite direction of current direction
        if(z == 0) {
            //calculating up value
            res = res + 0.82 * reward(y-1, x);
            //calculating right value
            res = res + 0.09 * reward(y, x+1);
            //down value is always 0 since going up, no caluclations needed
            //calculating left value
            res = res + 0.09 * reward(y, x-1);
        }
        if(z == 1) {
            //calculating up
            res = res + 0.09 * reward(y-1, x);
            //calulating right
            res = res + 0.82 * reward(y, x+1);
            //calculating down
            res = res + 0.09 * reward(y+1, x);
            //left value is always - since going right, no calculations needed
        }
        if(z == 2) {
            //up value is always 0 since going down, no calculations needed
            //calulating right
            res = res + 0.09 * reward(y, x+1);
            //calculating down
            res = res + 0.82 * reward(y+1, x);
            //calculating left value
            res = res + 0.09 * reward(y, x-1);
        }
        if(z == 3) {
            //calculating up
            res = res + 0.09 * reward(y-1, x);
            //right value is always 0 since going left, no calculations needed
            //calculating down
            res = res + 0.09 * reward(y+1, x);
            //calculating left value
            res = res + 0.82 * reward(y, x-1);
        }

        return res;
    }

    public static Double reward(int y, int x) {
        //holds res value
        Double res = 0.0;

        switch (map[y][x]) {
            case "cake": res = 10.0; break;
            case "donut": res = 3.0; break;
            case "fire": res = -5.0; break;
            case "morales": res = -10.0; break;
            case "wall": res = -1.0; break;
            default: res = 0.0; break;
        }

        return res;
    }

    public static String getPolicy(int y, int x) {
        //holds temp policy
        String p = "";
        //holds temp value
        Double v = -1000000000.00;

        for(int z = 0; z < 4; z++) {
            if(Qprev[y][x][z] > v) {
                if(z == 0) {
                    p = "^";
                }
                else if(z == 1) {
                    p = ">";
                }
                else if(z == 2) {
                    p = "v";
                }
                else if(z == 3) {
                    p = "<";
                }
                v = Qprev[y][x][z];
            }
        }

        return p;
    }
}