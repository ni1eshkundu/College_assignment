import java.util.*;
class as7{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a string:");
        String str=sc.nextLine();
        System.out.println("\n1.number of times \"a\" appears");
        System.out.println("2.number of times \"and\" appears ");
        System.out.println("3.whether it starts with \"The\" or not");
        System.out.println("4.put the String into an array of characters");
        System.out.println("5.display the tokens in the String");
        int ch;
        int n=str.length();
        do{
            System.out.print("Enter your choice:");
            ch=sc.nextInt();
            switch(ch){
                case 1:
                    int count_a=0;
                    for(int i=0;i<n;i++){
                        if(str.charAt(i)=='a'){
                            count_a++;
                        }
                    }
                    System.out.println("Number of \"a\" in string is "+count_a);
                    break;
                case 2:
                    int count_and=0,index=0;
                    while(true){
                        index=str.indexOf(" and ",index);
                        if(index!=-1){
                            count_and++;
                            index+=5;
                        }
                        else{
                            break;
                        }
                    }
                    System.out.println("Number of \"and\" in string is "+count_and);
                    break;
                case 3:
                    if(str.charAt(0)=='T'&&str.charAt(1)=='h'&&str.charAt(2)=='e')
                        System.out.println("Yes!");
                    else
                        System.out.println("No!");
                    break;
                case 4:
                    char[] a=new char[n];
                    for(int i=0;i<n;i++){
                        a[i]=str.charAt(i);
                    }
                    System.out.print("The string in array is=> ");
                    for(int i=0;i<n;i++){
                        System.out.println("Element-"+i+" : " + a[i]);
                    }
                    System.out.println();
                    break;
                case 5:
                    int count=0;
                    for(int i=0;i<n;i++){
                        if(str.charAt(i)==' ' || str.charAt(i)=='@' || (i!=n-1 && str.charAt(i)=='.')){
                            count++;
                        }
                    }
                    System.out.println("Number of tokens in string is "+(count+1));
                    break;
                default:
                    System.out.println("Wrong Choice!");
            }
        }while(ch>=1&&ch<=5);
    }
}
