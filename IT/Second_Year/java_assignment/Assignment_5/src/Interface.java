
import java.util.*;
//Define the interface for common vehicle functionalities
interface Vehicle {
 void changeGear();
 void speedUp();
 void applyBrakes();
}

//Implement the Vehicle interface for Bicycle
class Bicycle implements Vehicle
{
 private int gear;
 private int speed;

 public Bicycle() 
 {
     gear = 1; // Bicycles typically have one gear by default
     speed = 0;
 }

 @Override
 public void changeGear() 
 {
	 
	 Scanner sc = new Scanner(System.in);
	 System.out.println("Gear :");
     int newGear = sc.nextInt();
     gear = newGear;
     System.out.println("Bicycle: Gear changed to " + gear);
 }

 @Override
 public void speedUp() 
 {
	 Scanner sc = new Scanner(System.in);
	 System.out.println("Speed : ");
	 int increment = sc.nextInt();
     speed += increment;
     System.out.println("Bicycle: Speed increased to " + speed + " km/h");
 }

 @Override
 public void applyBrakes() 
 {
	 Scanner sc = new Scanner(System.in);
	 System.out.println("Apply breakes then speed decrement to: ");
	 int decrement = sc.nextInt();
     speed -= decrement;
     if (speed < 0) { //validation
         speed = 0;
     }
     System.out.println("Bicycle: Speed reduced to " + speed + " km/h ");

 }
}

//Implement the Vehicle interface for Bike
class Bike implements Vehicle 
{
 private int gear;
 private int speed;

 public Bike() {
     gear = 1; // Bikes typically have one gear by default
     speed = 0;
 }

 @Override
 public void changeGear()
 {

     Scanner sc = new Scanner(System.in);
     System.out.println("Gear :");
     int newGear = sc.nextInt();
     gear = newGear;
     System.out.println("Bike: Gear changed to " + gear);
 }

 @Override
 public void speedUp() {
	 Scanner sc = new Scanner(System.in);
	 System.out.println("Speed : ");
	 int increment = sc.nextInt();
     speed += increment;
     System.out.println("Bike: Speed increased to " + speed + " km/h");
 }

 @Override
 public void applyBrakes() {
	 Scanner sc = new Scanner(System.in);
	 System.out.println("Apply breakes : \n");
	 int decrement = sc.nextInt();
     speed -= decrement;
     if (speed < 0) {
         speed = 0;
     }
     System.out.println("Bike: Speed reduced to " + speed + " km/h \n");
   
 }
}

//Implement the Vehicle interface for Car
class Car implements Vehicle {
 private int gear;
 private int speed;

 public Car() 
 {
     gear = 1; // Cars typically start in first gear
     speed = 0;
 }

 @Override
 public void changeGear() {
	 Scanner sc = new Scanner(System.in);
	 System.out.println("Gear : ");
     int newGear = sc.nextInt();
     gear = newGear;
   
     System.out.println("Car: Gear changed to " + gear);
 }

 @Override
 public void speedUp() {
	 Scanner sc = new Scanner(System.in);
	 System.out.println("Speed : ");
	 int increment = sc.nextInt();
     speed += increment;
     System.out.println("Car: Speed increased to " + speed + " km/h");
 }

 @Override
 public void applyBrakes() {
	 Scanner sc = new Scanner(System.in);
	 System.out.println("Apply breakes : ");
	 int decrement = sc.nextInt();
     speed -= decrement;
     if (speed < 0) {
         speed = 0;
     }
     System.out.println("Car: Speed reduced to " + speed + " km/h");
 }
}

public class Interface {
 public static void main(String[] args) 
 {    
	 int choice = 0;
     // Create instances of Bicycle, Bike, and Car
		 System.out.print("\n");
		 System.out.println("---------Menu---------");
		 System.out.print("1. -----for Bicycle----\n 2.------For Bike-------- \n 3.------- for Car------");
		 System.out.print("\n");
		 
	 while(choice!=4)
	 {
		 Scanner sc = new Scanner(System.in);
		 System.out.print("Enter choice :");
		 choice = sc.nextInt();
	 switch(choice)
	 {
	 case 1:
		 System.out.println(" **Bicycle** \n");	 
     Bicycle bicycle = new Bicycle(); //  // Demonstrate the common functionalities
     bicycle.changeGear();
     bicycle.speedUp();
     bicycle.applyBrakes();
     
     break;
     
	 case 2:
		 System.out.println(" **Bike** \n");
     Bike bike = new Bike();
     bike.changeGear();
     bike.speedUp();
     bike.applyBrakes();
     break;
     
	 case 3:
		 System.out.print("  **Car** \n");
     Car car = new Car();
     car.changeGear();
     car.speedUp();
     car.applyBrakes();
     break;
	 case 4:
		 int E = 0;
		 System.out.println("Exit" +E);
	 default :
		break; 
	 }

    }
 }
}


