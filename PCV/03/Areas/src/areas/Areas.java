/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package areas;

import java.util.InputMismatchException;
import java.util.Scanner;

/**
 *
 * @author student
 */
public class Areas {
    Scanner sc = new Scanner(System.in, "UTF-8");
    enum Options{
        S, R, T, C, X;
    }
    
    
    float readNumber(String text){
        float input = -1;
        do{
            try{
                System.out.print(text + ": ");
                input = sc.nextFloat();
                if(input < 0){
                    System.out.println("Číslo nesmi být záporné");
                }
            }catch (InputMismatchException e){
                 System.out.println("NEsprávně zadané číslo! ");
            }
            sc.nextLine();
    }while (input < 0);
    return input;
    }
    
    double getSquareArea(float a){
        return Math.pow(a, 2);
    }
    
    void menu() {
        String optChar = "";
        do{
            System.out.println("Výpočet plochy geometrických útvarů");
            System.out.println("S = čtverec, R = obdelník, T = trojuhelnik, C = kruh");
            System.out.println("Zadej volbu: ");
            optChar = sc.nextLine();
            try{
                Options option = Options.valueOf(optChar.toUpperCase());
                switch (option){
                    case S: System.out.printf("Plocha čtverce o straně" + "%.2f je %.3f", a, this.getSquareArea(a));
                            System.out.println();
                            break;
                    case R: System.out.println("Obdelník");
                            break;
                    case T:System.out.println("Trojúhelník");
                            break;
                    case C: System.out.println("Kruh");
                            break;
                }
            }cath (Exception e){
            System.out.println("Chybná volba");
            }
        }while (!optChar.equalsIgnoreCase("X"));
    }
    
    public static void main(String[] args) {
        
        // TODO code application logic here
    }
    
}
