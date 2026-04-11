import java.util.*;
abstract class Operation {
	
    protected float length, breath;
    protected float base, height;

    abstract void get_data(); // Changed the method name

    abstract void compute();
}

class Rectangle extends Operation {
	
    void get_data() {
    	
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter length");
        length = sc.nextFloat();
        System.out.println("Enter Breadth");
        breath = sc.nextFloat();
        
        while(length == 0 || breath ==0)
        {    
        	 System.out.println("Make sure that Lenght and breadth no be zero");
        	 System.out.println("Enter length");
             length = sc.nextFloat();
             System.out.println("Enter Breadth");
             breath = sc.nextFloat();	
        }
    }

    void compute()
    {
        float area = length * breath;
        System.out.println("Area of rectangle is " + area);
    }
}

class Triangle extends Operation 
{
        void get_data() { // Renamed the method to match Rectangle class
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Base");
        base = sc.nextFloat();
        System.out.println("Enter Height");
        height = sc.nextFloat();
        
        while(base == 0 || height ==0)
        {    
        	 System.out.println("Make sure that height  and base no be zero");
        	 System.out.println("Enter Base");
             base = sc.nextFloat();
             System.out.println("Enter Height");
             height = sc.nextFloat();
        }
    }

    void compute() {
        float area;
        area = 0.5f * base * height; // Fixed calculation of 1/2
        System.out.println("Area of Triangle " + area);
    }
}

public class  Area {
	
    public static void main(String[] args) {
        int choice = 0;
        do {
            System.out.println("-----------------------------------");
            System.out.println("Menu");
            System.out.println("1.Area of Rectangle \n2.Area of Triangle"); // Fixed formatting
            System.out.println("-----------------------------------");
            System.out.println("Enter your choice :");
            Scanner sc = new Scanner(System.in);
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    Rectangle r = new Rectangle();
                    r.get_data();
                    r.compute();
                    break;
                case 2:
                    Triangle t = new Triangle();
                    t.get_data();
                    t.compute();
                    break;
                case 3:
                    System.out.println("Exit");
                    break; // Added a break statement to exit the loop
                default:
                    System.out.println("Invalid");
            }
        } while (choice != 3);
    }
}
