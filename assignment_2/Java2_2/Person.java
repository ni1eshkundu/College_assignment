package Java2_2;

import java.util.Scanner;

public class Person {
String name;
Long phone_no;
String email;
String pno;//premises no
String street;
String city;
long pin;
String state;

public String getName() {
	return name;
}
public void setName(String name) {
	this.name = name;
}
public Long getPhone_no() {
	return phone_no;
}
public void setPhone_no(Long phone_no) {
	this.phone_no = phone_no;
}
public String getEmail() {
	return email;
}
public void setEmail(String email) {
	this.email = email;
}


public String getPno() {
	return pno;
}
public void setPno(String pno) {
	this.pno = pno;
}
public String getStreet() {
	return street;
}
public void setStreet(String street) {
	this.street = street;
}
public String getCity() {
	return city;
}
public void setCity(String city) {
	this.city = city;
}
public long getPin() {
	return pin;
}
public void setPin(long pin) {
	this.pin = pin;
}
public String getState() {
	return state;
}
public void setState(String state) {
	this.state = state;
}

void getAddress() {
	Scanner sc = new Scanner(System.in);
	System.out.print("Enter the Premises number: ");
	pno=sc.nextLine();
	
	System.out.print("Enter the Street: ");
	street=sc.nextLine();
	
	System.out.print("Enter the City: ");
	city=sc.nextLine();
	
	System.out.print("Enter the Pin: ");
	pin=sc.nextLong();
	sc.nextLine();
	System.out.print("Enter the state: ");
	state=sc.nextLine();
	sc.close();
}
void showAddress() {
	System.out.print("Address is:"+ pno+" , "+street+", "+city+", "+state+", "+pin+"\n");
	
}
void changeAddress() {
	Scanner sc = new Scanner(System.in);
	System.out.println("1- Premises no \n 2- Street \n 3- City \n 4- Pin \n 5- State");
	System.out.println("Specify what need to be changed");
	int c= sc.nextInt();
	switch (c) {
		case 1 : {
			sc.nextLine();
			System.out.print("Enter the new Premises number: ");
			pno = sc.nextLine();
		}
		case 2 : {
			sc.nextLine();
			System.out.print("Enter the new Street:");
			street = sc.nextLine();
		}
		case 3 : {
			System.out.print("Enter the  new City:");
			sc.nextLine();
			city = sc.nextLine();
		}
		case 4 : {
			sc.nextLine();
			System.out.print("Enter the new Pin:");
			pin = sc.nextLong();
		}
		case 5 : {
			sc.nextLine();
			System.out.print("Enter the new state:");
			state = sc.nextLine();
		}
		default : System.out.print("wrong input");
	}
	sc.close();
}

}

