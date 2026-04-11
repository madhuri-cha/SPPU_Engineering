package assigment6;

import java.util.*;

public class assignment6
{
	public static void main(String []args) {
		
		Scanner sc = new Scanner(System.in);
		int arr[] = {12, 34 , 45 ,67 };//array
 try {
	try
	{
		
		System.out.println("Enter Index Value you want to access element ");
		int index = sc.nextInt();
		System.out.println("Index is " +index+ " of the element "+ arr[index]);
		
	}
       
	catch(ArrayIndexOutOfBoundsException e)
	{    
		System.out.println("You are trying to Invalid index \n Try valid Index");
		System.out.println("Please enter valid index :");
		int index = sc.nextInt();
		System.out.println("Index is " +index+ " of the element "+ arr[index]);
		
	}
    try
    {
      	
     int n1,n2;
     int Division;
     System.out.println("Enter two elements ");
     n1  = sc.nextInt();
     n2 = sc.nextInt();
     Division = n1 / n2;
     System.out.println("Division is"+Division);
    	
    }
     catch(ArithmeticException e)
    {   
    	 int n1,n2;
         int Division;
    	 System.out.println("Please make sure that num should be not zero");
    	 n1  = sc.nextInt();
         n2 = sc.nextInt();
         Division = n1 / n2;
         System.out.println("Division is"+Division);
        	
    }
    catch(NumberFormatException e )
    {
    	System.out.println("Make sure the number should be interger");
    }
 }
 catch(Exception e)
 {
	 System.out.println("Try one more time");
 }
 }  

}