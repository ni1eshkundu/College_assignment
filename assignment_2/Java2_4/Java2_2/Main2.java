package Java2_2;
import java.util.*;
public class Main2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the number of students:  ");
		int ns= sc.nextInt();
		System.out.print("\nEnter the number of faculty:  ");
		int nf= sc.nextInt();
		
		Student[] stud = new Student[ns];
		
		Faculty[] facul = new Faculty[nf];
		
		for(int i=0;i<ns;i++) {
			stud[i]= new Student();
			System.out.println("Enter the record for student: "+(i+1));
			System.out.print("Enter the Roll Number: ");
			int roll=sc.nextInt();
			stud[i].setRollno(roll);
			sc.nextLine();
			System.out.print("Enter the Name: ");
			String n=sc.nextLine();
			stud[i].setName(n);
			//sc.nextLine();
			System.out.print("Enter the Phone Number: ");
			long phno=sc.nextLong();
			stud[i].setPhone_no(phno);
			sc.nextLine();
			System.out.print("Enter the Email Address: ");
			String eid=sc.nextLine();
			stud[i].setEmail(eid);
			//sc.nextLine();
			System.out.print("Enter the Course of study: ");
			String study=sc.nextLine();
			stud[i].setCourse(study);
			//sc.nextLine();
			System.out.println("Enter Address: ");
			stud[i].getAddress();
		
		}
		
		for(int i=0;i<nf;i++) {
			facul[i]= new Faculty();
			System.out.println("Enter the record for Faculty: "+(i+1));
			//sc.nextLine();
			System.out.print("Enter the Employee Id: ");
			String eid=sc.nextLine();
			facul[i].setEmp_id(eid);

			System.out.print("Enter the Name: ");
			String n=sc.nextLine();
			facul[i].setName(n);
			//sc.nextLine();
			
			System.out.print("Enter the Department: ");
			String dept=sc.nextLine();
			facul[i].setDepartment(dept);
			
			System.out.print("Enter the Specialisation: ");
			String s=sc.nextLine();
			facul[i].setSpecialisation(s);
			//sc.nextLine();
			
			System.out.print("Enter the Phone Number:");
			long phno=sc.nextLong();
			facul[i].setPhone_no(phno);
			sc.nextLine();
			
			System.out.print("Enter the Email Address: ");
			String email=sc.nextLine();
			facul[i].setEmail(email);
			
			System.out.println("Enter the Address: ");
			facul[i].getAddress();
		}
		System.out.println("\n\nDetails of the Faculty:\n\n");
		for(int i=0;i<nf;i++) {
			System.out.println("Emp_id : "+ facul[i].getEmp_id());
			System.out.println("Name : "+facul[i].getName());
			System.out.println("Email-id : "+facul[i].getEmail());
			facul[i].showAddress();
			System.out.println("Phone Number : "+facul[i].getPhone_no());
			System.out.println("Department : "+facul[i].getDepartment());
			System.out.println("Specialisation : "+facul[i].getSpecialisation());
			System.out.println();
		}
		System.out.println("\n\nDetails of the Students:\n\n");
		for(int i=0;i<nf;i++) {
			System.out.println("Roll No : "+ stud[i].getRollno());
			System.out.println("Name : "+stud[i].getName());
			System.out.println("Email-id : "+stud[i].getEmail());
			stud[i].showAddress();
			System.out.println("Phone Number : "+stud[i].getPhone_no());
			System.out.println("Department : "+stud[i].getCourse());
			System.out.println();
			
		}
		//sc.nextLine();
		System.out.println();
		do {
			System.out.print("Do you what to change the address details(0/1)");
			int chh = sc.nextInt();
			if (chh == 1) {
				System.out.print("1- change address details of the student\n");
				System.out.print("2- change address details of the faculty member");
				System.out.print("\nEnter Choice");
				sc.nextLine();
				int cho = sc.nextInt();
				switch (cho) {
					case 1 : {
						int flag = 0;
						System.out.print("Enter the roll no of the student");
						int r = sc.nextInt();
						for (int j = 0; j < ns; j++) {
							if (stud[j].rollno == r) {
								stud[j].changeAddress();
								flag = 1;
								break;
							}
						}
						if (flag == 0)
							System.out.println("Not Found");
					}
					break;
					case 2 : {
						int flag1 = 0;

						System.out.print("Enter the emp id of the Employee:");
						sc.nextLine();
						String e = sc.nextLine();
						for (int j = 0; j < nf; j++) {
							if (facul[j].emp_id.equals(e)) {
								{
									facul[j].changeAddress();
									flag1 = 1;
									break;
								}
							}
						}
						if (flag1 == 0)
							System.out.println("Not Found!");
					}
					break;
					default : System.out.println("Wrong Choice!");
				}
			}
			else break;
		}while (true);
		System.out.println("\n\nDetails of the Faculty:\n\n");
		for(int i=0;i<nf;i++) {
			System.out.println("Emp_id : "+ facul[i].getEmp_id());
			System.out.println("Name : "+facul[i].getName());
			System.out.println("Email-id : "+facul[i].getEmail());
			facul[i].showAddress();
			System.out.println("Phone Number : "+facul[i].getPhone_no());
			System.out.println("Department : "+facul[i].getDepartment());
			System.out.println("Specialisation : "+facul[i].getSpecialisation());
			
		}
		System.out.println("\n\nDetails of the Students:\n\n");
		for(int i=0;i<nf;i++) {
			System.out.println("Roll No : "+ stud[i].getRollno());
			System.out.println("Name : "+stud[i].getName());
			System.out.println("Email-id : "+stud[i].getEmail());
			stud[i].showAddress();
			System.out.println("Phone Number : "+stud[i].getPhone_no());
			System.out.println("Department : "+stud[i].getCourse());
		}
		sc.close();
	}

}
