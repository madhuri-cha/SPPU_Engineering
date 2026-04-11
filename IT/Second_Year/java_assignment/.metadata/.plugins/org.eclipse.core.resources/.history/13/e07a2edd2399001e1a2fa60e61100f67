import java.util.*;
interface paymentmethod///////////////
{
   public void pay(int amount);	
}
class creditcard implements paymentmethod/////
{
	private String name;
	private double cardno;
	private String expdate;
	Scanner sc = new Scanner(System.in);
	
	public creditcard()
	{
		super();
		System.out.println("name ");
		this.name = sc.next();
		System.out.println(" card no ");
		this.cardno = sc.nextInt();
		System.out.println("expiry date ");
		this.expdate = sc.next();
		
	}
	public void pay(int amount)
	{
		System.out.println("Credit card through payment");
		System.out.println(" Amount " +amount);
		
	}
}
 class paypal implements paymentmethod
 {
	 
	 public
	 
	 paypal()
	 {
		 super();
		 System.out.println("network loading for payment");	
	 }
	 public void pay(int amount)
	 {
		    System.out.println("Paypal through payment");
			System.out.println(" Amount " +amount);
			
	 }
 }
class bitcoin implements paymentmethod
{
	public 
	String ads;
	Scanner sc = new Scanner(System.in);
	bitcoin()
	{
		super();//cons intialize
		System.out.println(" Input Address ");
		ads = sc.next();
	}
	 public void pay(int amount)
	 {
		    System.out.println("bitcoin  through payment");
			System.out.println(" Amount " +amount);
			
	 }
}
class order 
{
	
	private final paymentmethod pymethod;/// object
	private final int amount;
	public 
	
    order(int amount , paymentmethod pymethod)
   {
	this.amount = amount;
	this.pymethod = pymethod;
	
   }
   public void process()
   {
    pymethod.pay(amount);
   }
 
}

public class Strategypattern {

	public static void main(String agrs[])
	{
		int amt , choice = 0;
        Scanner sc = new Scanner(System.in);

		while(true)
        {
            System.out.println("choice :");
            choice = sc.nextInt();
            System.out.println(" amount transection ");
            amt = sc.nextInt();
            switch(choice)
            {
                case 1 :
                System.out.println("credit");
                order ob = new order(amt , new creditcard());
                ob.process();
                break;
                case 2 :
                System.out.println("Paypal");
                order o = new order(amt , new paypal());
                o.process();
                break;
                case 3:
                System.out.println("bitcoin");
                o = new order(amt , new bitcoin());
                o.process();
                break;
                case 4:
                System.out.println("------------shopping done !!!!!!!-----------------");
                break;
                default :
                System.out.println(" invalid choice ");
            }      
        }
		
	}
}
