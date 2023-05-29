import java.util.Scanner;

class bankacc {
	private String accno;
	private String name;
	private double currloanamt;
	private String phone;
	private char acc_type;
	private double credlimit;
	public double askLoan;

	// method to set accno
	public void setAcc(String accno) {
		this.accno = accno;
	}

	// method to get accno
	public String getAcc() {
		return accno;
	}

	// method to set name
	public void setName(String name) {
		this.name = name;
	}

	// method to get name
	public String getName() {
		return name;
	}

	// method to set currloanamt
	public void setcurrloanamt(double currloanamt) {
		this.currloanamt = currloanamt;
	}

	// method to get currloanamt
	public double getcurrloanamt() {
		return currloanamt;
	}

	// method to set phone number
	public void setPhone(String phone) {
		this.phone = phone;
	}

	// method to get phone number
	public String getPhone() {
		return phone;
	}

	// method to set account type
	public void setType(char acc_type) {
		this.acc_type = acc_type;
		setcredlimit();
	}

	// method to get account type
	public char getType() {
		return acc_type;
	}

	// method to set credit limit
	public void setcredlimit() {
		if (acc_type == 'p')
			this.credlimit = 1000000;
		else if (acc_type == 'n')
			this.credlimit = 50000;
	}

	public double getcredlimit() {
		return credlimit;
	}

	// method to set asking loan amount
	public void setAskloan(double askLoan) {
		this.askLoan = askLoan;
	}

	// method to get asking loan amount
	public double getAskloan() {
		return askLoan;
	}

	// method to add two loan amount
	public double loan(double d1, double d2) {
		return d1 + d2;
	}
};

public class Java_2_1 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of customers:");
		int n = sc.nextInt();
	     sc.nextLine();
		bankacc acc[] = new bankacc[n];
		// loop to enter n customer details
		for (int i = 0; i < n; i++) {
			acc[i] = new bankacc();
			System.out.println("Enter the record for customer " + (i + 1));
			System.out.println("Enter the account number:");
			String x = sc.nextLine();
			if (x.length() != 11) {
				System.out.print("Wrong Account Number Format,");
				i--;
				continue;
			}
			acc[i].setAcc(x);
			System.out.println("Enter the name:");
			String s = sc.nextLine();
			acc[i].setName(s);
			System.out.println("Enter the current loan amount:");
			double d1 = sc.nextDouble();
			acc[i].setcurrloanamt(d1);
			sc.nextLine();
			System.out.println("Enter the phone number:");
			String l = sc.next();
			if (l.length() != 10) {
				System.out.print("Phone Number must contain 10 digits,Please reenter correct phone number:");
				l = sc.next();
			}
			acc[i].setPhone(l);
			System.out.println("Enter p for Priviledged Account\n or Enter n for Normal Account: ");
			char c = sc.next().charAt(0);
			acc[i].setType(c);
			System.out.println("Enter the amount of the loan customer is asking for:");
			double d3 = sc.nextDouble();
			acc[i].setAskloan(d3);
			sc.nextLine();
		}
		// print the customer details with proper message whether they can get the
		// current asking loan amount
		for (int i = 0; i < n; i++) {
			System.out.println("Account_number : " + acc[i].getAcc() + "\nName: " + acc[i].getName()
					+ "\nCurrent Loan Amount: " + acc[i].getcurrloanamt() + "\nPhone Number: " + acc[i].getPhone()
					+ "\nAccount Type: " + acc[i].getType());
			// checks whether a valid account or not
			if (acc[i].getType() == 'p' || acc[i].getType() == 'n')
				System.out.println("Account Credit Limit : " + acc[i].getcredlimit());
			else
				System.out.println("Invalid account type");

			if (acc[i].loan(acc[i].getAskloan(), acc[i].getcurrloanamt()) <= acc[i].getcredlimit()) {
				System.out.println("Loan can be sanctioned...");
				acc[i].setcurrloanamt(acc[i].loan(acc[i].getAskloan(), acc[i].getcurrloanamt()));
				System.out.println("Updated current loan amount : " + acc[i].getcurrloanamt());
			} else
				System.out.println("Loan sanction is not possible due to credit limit issues...");
		}
		sc.close();
	}
}
