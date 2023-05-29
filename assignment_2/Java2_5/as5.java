import java.util.*;

class MyException extends Exception{
    public String toString(){
        return "Score is non-negative and cannot exceed 100";
    }
}

class Student{
    private int roll;
    private String name;
    private double score;
    
    public void setRoll(int roll){
        this.roll=roll;
    }
    
    public void setName(String name){
        this.name=name;
    }
   
    public void setScore(double score) throws MyException{
        if(score<0||score>100){
            throw new MyException();
        }  
        this.score=score;
    }
    
    public int getRoll(){
        return this.roll;
    }
    
    public String getName(){
        return this.name;
    }
    
    public double getScore(){
        return this.score;
    }
};
class as5{
    public static void main(String args[]){
        Student s1=new Student();
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter student roll: ");
        int roll=sc.nextInt();
        s1.setRoll(roll);
        System.out.print("Enter student name: ");
        sc.nextLine();
        String name=sc.nextLine();
        s1.setName(name);
        System.out.print("Enter student's score: ");
        double score=sc.nextDouble();
        try{
            s1.setScore(score);
            System.out.println("Student Roll : "+s1.getRoll()+"\nStudent Name : "+s1.getName()+"\nStudent Score : "+s1.getScore());
        }
        catch(MyException e){
            System.out.println("Exception : "+e);
        }
    }
}