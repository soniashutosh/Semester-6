import java.util.*;
import java.lang.String;

public class PigLatin{
	public static void main(String []args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the String");
		String str = sc.nextLine();
		int len = str.length();
		String temp;
		int start=0;
		for(int i=0;i<len;i++){
			if(str.charAt(i)==' '){
				temp=str.substring(start,i);
				start=i+1;
				printPigLatin(temp);
			}
		}
		temp=str.substring(start,len);
		printPigLatin(temp);
		System.out.println(" ");
	}

	public static void printPigLatin(String temp){
		if(isVowel(temp.charAt(0))){
			String finalString = temp + "way";
			System.out.print(finalString + " ");
		}
		else{
			boolean flag = false;
			for(int j=1;j<temp.length();j++){
				if(isVowel(temp.charAt(j))){
					String test1 = temp.substring(0,j);
					String test2 = temp.substring(j,temp.length());
					String finalString = test2 + test1 + "ay";
					System.out.print(finalString + " ");
					flag=true;
					break;
				}
			}
			if(!flag){
				String finalString = temp + "ay";
				System.out.print(finalString + " ");
			}
		}
	}

	public static boolean isVowel(char c){
		if(c=='A' || c=='a' || c=='E' || c=='e' || c=='I' || c=='i' || c=='O' || c=='o' || c=='U' || c=='u'){
			return true;
		}
		return false;
	}
}

