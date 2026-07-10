import java.util.Scanner;

public class BaskinRobbins {
    public static int Combi(int n){
        if(n<=1){
            return 0;
        }else{
            return n*(n-1);
        }
    }
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        System.out.println(Combi(n));
        scan.close();
    }
}
