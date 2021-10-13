import java.util.*;

public class RiceBags{
	public static void main(String []args){
		Scanner sc = new Scanner(System.in);
		int smallBags=0,bigBags=0,goal=0;
		System.out.print("\nEnter the number of small bags:  ");
		smallBags = sc.nextInt();
		System.out.print("\nEnter the number of big bags:  ");
		bigBags = sc.nextInt();
		System.out.print("\nEnter the goal which you want to reach:  ");
		goal = sc.nextInt();
		int result = findBags(smallBags,bigBags,goal);
		System.out.println("\nMinimum number of small bags needed to pack goal kilos of rice is "+ result);
	}

	public static int findBags(int smallBags,int bigBags,int goal){
		int result = -1;
		if(bigBags*5 >= goal){
		    if(smallBags >= goal%5){
		        result = goal%5;
		    }
		} 
		else{
		    if(smallBags >= goal-bigBags*5){
		        result = goal-bigBags* 5;
		    }
		}
		return result;
	}
}
