import java.util.*;

public class SubMatrix{

	public static void main(String []args){
		int row,col;
		System.out.println("Enter the number of rows and columns of original Matrix");
		Scanner sc = new Scanner(System.in);
		row = sc.nextInt();
		col = sc.nextInt();
		int originalMatrix[][] = new int[row][col];
		System.out.println("Enter the matrix with given row and col ");
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				originalMatrix[i][j] = sc.nextInt();
			}
		}
		int newrow, newcol;
		System.out.println("Enter the row and col of submatrix in which you want to print the submatrix");
		newrow = sc.nextInt();
		newcol = sc.nextInt();

		if(row%newrow == 0 && col%newcol == 0){
			System.out.println("");
			printSubmatrix(originalMatrix,newrow,newcol);
			System.out.println("");
		}
		else{
			System.out.println("Non overlapping submatrix of this matrix not be made...");
			System.out.println("Please Enter accordingly");
		}
	}

	static void printSubmatrix(int matrix[][],int newrow,int newcol){
		int row = matrix.length;
		int col = matrix[0].length;
		
		int numrow = row/newrow;
		int numcol = col/newcol;

		for(int a=0;a<numrow;a++){
			for(int b=0;b<numcol;b++){
				System.out.println("SubMatrix: "+(a+b+1));
				for(int i=0;i<newrow;i++){
					for(int j=0;j<newcol;j++){
						System.out.print(matrix[i+a*newrow][j+b*newcol]+ "  ");
					}
					System.out.println("");
				}
				System.out.println("");
			}
		}
	}
}