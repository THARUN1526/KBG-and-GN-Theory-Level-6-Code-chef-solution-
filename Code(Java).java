import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0){
		    int n=sc.nextInt();
		    int q=sc.nextInt();
		    for(int i=0;i<q;i++){
		        int u=sc.nextInt();
		        int v=sc.nextInt();
		        if(v<u){
		            int tem=v;
		            v=u;
		            u=tem;
		        }
		        int div=gcd(v,u);
		        //v=v/div;
		        //u=u/div;
		        long ans=(long)solve(v/div)+solve(u/div);
		        //System.out.println((findPath(v)+findPath(u)));
		        System.out.println(ans);
		    }
		}
		
	}
	static int gcd(int x,int y){
        int dividend=x;
        int divisor=y;
        while(divisor!=0){
            int rem=dividend%divisor;
            dividend=divisor;
            divisor=rem;
        }
        return dividend;
    }
	
	static int solve(int n){
        int ans=0;
        if((n&1)==0){
            while((n&1)==0){
                ans=ans+2;
                n=n/2;
            }
        }
        for(int i=3;i*i<=n;i=i+2){
            while((n%i)==0){
                ans=ans+i;
                n=n/i;
            }
        }
        if(n>1)
            ans=ans+n;
        return ans;
    }
	
}
