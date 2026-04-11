package ass;
import java.util.*;
public class Complex
 {
    int real,img;
	public
	Complex(int real,int img) 
	{
		this.real=real;//class having same attributes
		this.img=img;  
	}
		
	void add() 
	{ 
		System.out.println("Addtion Of Complex Number");
	   Scanner sc=new Scanner(System.in);
	  System.out.println("enter first number");
      Complex A=new Complex(sc.nextInt(),sc.nextInt());
      System.out.println("n1="  +A.real+ "+i" + A.img);
      System.out.println("enter second number");
      Complex B=new Complex(sc.snextInt(),sc.nextInt());
      System.out.println("n2="  +B.real+ "+i" + B.img);
      Complex C=new Complex(A.real+B.real,A.img+B.img); 
      System.out.println("Addition = " +C.real+ "+i" + C.img);
	}
	
	void subtract()
	{
		System.out.println("Subtraction Of Complex Number");
	  Scanner sc=new Scanner(System.in);
	  System.out.println("enter first number");
	  Complex A=new Complex(sc.nextInt(),sc.nextInt());
	  System.out.println("n1="  +A.real+ "+i" + A.img);
	  System.out.println("enter second number");
	  Complex B=new Complex(sc.nextInt(),sc.nextInt());
	  System.out.println("n2="  +B.real+ "+i" + B.img);
	  Complex C=new Complex(A.real-B.real,A.img-B.img); 
	  System.out.println("subtraction = " +C.real+ "" + C.img "i");
    }
	
	void multi()
	{
		System.out.println("Multiplication Of Complex Number :");
	   Scanner sc = new Scanner(System.in);
	   System.out.println("enter first number");
       Complex A=new Complex(sc.nextInt(),sc.nextInt());
       System.out.println("n1="  +A.real+ "+i" + A.img);
       System.out.println("enter second number : ");
      Complex B=new Complex(sc.nextInt(),sc.nextInt());
       System.out.println("n2="  +B.real+ "+i" + B.img);
      Complex c =new Complex((A.real*B.real + (-1)*A.img*B.img), (A.real*B.img + A.img*B.real)); 
      //[(ac - bd) + i(ad+bc)] 
       System.out.println(" multiplication = " +c.real+ "+i" + c.img);
	}
	
	void division()
	{
		System.out.println("Division Of Complex Number");
	    Scanner sc = new Scanner(System.in);
	    System.out.println("enter first number  : ");
        Complex A=new Complex(sc.nextInt(),sc.nextInt());
        System.out.println("n1="  +A.real+ "+i" + A.img);

        System.out.println("enter second number :");
        Complex B=new Complex(sc.nextInt(),sc.nextInt());
        if((B.img + B.real)!=0)
        	
        {
        System.out.println("n2"+ "="  +B.real+ "+i" + B.img);
        int den=(B.real*B.real) +(B.img*B.img);
        int r=((A.real*B.real)+(A.img*B.img))/den;
        int i=((A.img*B.real)-(A.real*B.img))/den;
        Complex  c =new Complex(r,i); 
        System.out.println(" division(quotient) = " +c.real+ "+i" + c.img);
        }
         // ( (ac + bd)/c^2 + d^2 ) + ((bc - ad)/ c^2 + d^2)
        
        else
        {
        	System.out.println("Infinite Arithmatic operation");
        }
	}
	
	public static void main(String[] args)
	{
		Complex X = new Complex(0,0);
		Complex Y = new Complex(0,0);
		System.out.println("----------------------------------------------");
		System.out.println("Menu");
		System.out.println("1: addition");
		System.out.println("2: subtraction");
		System.out.println("3: multiplication");
		System.out.println("4: division");
		System.out.println("5: exit");
		System.out.println("----------------------------------------------");
		System.out.println("ENTER CHOICE = ");
		Scanner obj = new Scanner(System.in);
		int choice=0;
		choice=obj.nextInt();
		switch(choice)
		{
		case 1:
			X.add();
			break;
		case 2:
			X.subtract();
			break;
		case 3: 
			X.multi();
			break;
		case 4:
			X.division();
			break;
		case 5 :
			int E = 0;
			System.out.println("Successufully Executed"+E);
		default :
			break;
		}
}
}

