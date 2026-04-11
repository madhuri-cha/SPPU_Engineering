package oop1;
import java.util.*;

class Publication {
	String Title;
	float Price;
	int Copies;

	void getPublicationDetails() {
        System.out.println("Publication Available-------------------"+'\n'+"1.Techneo----price=300 Rs"+'\n'+"2.Technical-----price=400 Rs");
		Scanner sc = new Scanner(System.in);
		System.out.println("enter the Publication name:");
		Title = sc.nextLine();
		
		if(Title.contains("techneo")||Title.contains("technical")) { 
			
		}
		else { 
			System.out.println("Publication Not Available"+'\n');
			System.out.println("Please Order from Available Publication:");
			Title = sc.nextLine();
		}
		
	}

	void publicationDetails() {
		System.out.println("Name of publication:" + Title);
		System.out.println("Price of Book:" + Price);
	}

	void saleCopy() {  @override
		Scanner sc = new Scanner(System.in);
		int availableCopies=30;
		System.out.println("enter the price:");
		Price = sc.nextInt();
		System.out.println("enter number of copies you want:");
		Copies = sc.nextInt();
		if (Copies<= availableCopies) {
			System.out.println("copies Available");
		} 
		else {
			 
			System.out.println("Copies are not available"+'\n'+"Please Order from available copies:"+availableCopies);
			System.out.println("enter updated count:");
			Copies = sc.nextInt();
		   }
		publicationDetails();
		System.out.println("total sale:" + Price * Copies);
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		int choice;
		do {
			System.out.println(
					"1.Publication Sale" + '\n' + "2.Books Sale" + '\n' + "3.Magazine Sales" + '\n' + "4.exit");
			System.out.println("enter your choice:");
			choice = sc.nextInt();
			switch (choice) {
			case 1:
				System.out.println("Publication");
				Publication pb = new Publication();
				pb.getPublicationDetails();
				pb.saleCopy();
				System.out.println("---------------------------------------------------");
				break;
			case 2:
				System.out.println("Books");
				Book bk = new Book();
				bk.getBookDetails();
				bk.orderCopies();
				bk.bookDetails();
				bk.saleCopy();
				System.out.println("---------------------------------------------------");
				break;
			case 3:
				System.out.println("Magazine");
				Magazine mg = new Magazine();
				mg.getMagazineDetails();
				mg.orderQuantity();
				mg.magazineDetails();
				mg.saleCopy();
				mg.receiveIssue();
				mg.currentIssue();
				System.out.println("---------------------------------------------------");
				break;
			case 4:
				System.out.println("Successfully exited");
				break;
			default:
				System.out.println("Invalid choice" + '\n' + "Try Again!!!");
			}
		} while (choice != 4);

	}
}

class Book {
	String Title, Author;
	int Price;
	int Copies;

	void getBookDetails() {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("enter the book title:");
		Title = sc.nextLine();
		System.out.println("Enter the author name:");
		Author = sc.nextLine();
		System.out.println("enter the price:");
		Price = sc.nextInt();
	}

	void bookDetails() {
//		Title="Atomic Habits";
//		Author="James Clear";
//		Price=400.0;
		System.out.println("Name of Book:" + Title);
		System.out.println("Author Name:" + Author);
		System.out.println("Price of Book:" + Price);
	}

	void orderCopies() 
	{
		int availableCopies=80;
		Scanner sc = new Scanner(System.in);
		System.out.println("enter number of copies you want:");
		Copies = sc.nextInt();
		if (Copies <= availableCopies) {
			System.out.println("copies Available");
		} 
		else {
			System.out.println("Copies are not available"+'\n'+"Please Order from Available copies:"+availableCopies);
			System.out.println("enter updated count:");
			Copies = sc.nextInt();
			
		}

	}

	void saleCopy() //override{
		System.out.println("total sale:" + Price * Copies);
	}

}

class Magazine {
	
	String Title;
	float Price;
	int Copies;
	int purchasemonth = 11;

	void getMagazineDetails() {

		Scanner sc = new Scanner(System.in);
		System.out.println("enter the book title:");
		Title = sc.nextLine();
		System.out.println("enter the price:");
		Price = sc.nextInt();
	}

	void magazineDetails() {
//		Title="DailyChats";
//		Price=300.0f;
		System.out.println("Name of Book:" + Title);
		System.out.println("Price of Book:" + Price);
	}

	void orderQuantity() {
		int availableCopies = 50;
		Scanner sc = new Scanner(System.in);
		System.out.println("enter number of copies you want:");
		Copies = sc.nextInt();
		if (Copies <= availableCopies) {
			System.out.println("copies Available");
		} 
		else {
			System.out.println("Copies are not available"+'\n'+"Please Order from Available copies:"+availableCopies);
			System.out.println("enter updated count:");
			Copies = sc.nextInt();
		}
	}

	void saleCopy() //override{
		System.out.println("total sale" + Price * Copies);
	}

	public void receiveIssue() {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the issue present in your magazine");
		System.out.println("!!! make sure to enter month");
		String current_issue = sc.nextLine(); // enter the month

	}

	public void currentIssue() {
		System.out.println("Enter the month of your issue"); // | issue month must be more than issue month present in														// magazine
		Scanner sc = new Scanner(System.in);
		System.out.println("!!!! make sure your issue month is more than issue month in magazine");
		int month = sc.nextInt();
		if (month == purchasemonth)
			System.out.println("Your magazine is updated" + month);
		else
			System.out.println("Updated issue month is : " + month);
	}

}