// Importing statements
import java.util.*;

public class MatrixMultiplication{
	public static void main(String []args){
		// Taking size of Matrix as Input
		System.out.println("Enter the size or dimension of square matrix");
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();

		int matrixA[][] = new int[size][size];
		int matrixB[][] = new int[size][size];
		int result[][] = new int [size][size];

		System.out.println("Enter the first Matrix");
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				matrixA[i][j] = sc.nextInt();
			}
		}

		System.out.println("Enter the second Matrix");
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				matrixB[i][j] = sc.nextInt();
			}
		}

		if(checkIsMatrixCartesian(matrixA) && checkIsMatrixCartesian(matrixB)){
			for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
					int sum =0;
					for(int k=0;k<size;k++){
						sum += matrixA[i][k]*matrixB[k][j];
					}
					result[i][j] = sum;
				}
			}
			System.out.println("After Multiplication of these Cartesian Matrix.. Result is : ");
			for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
					System.out.print(result[i][j] + "  ");
				}
				System.out.println(" ");
			}
		}
		else{
			System.out.println("Please Enter Cartesian Matrix ....");
		}
	}

	// Checking for Matrix to be Cartesian Matrix
	static boolean checkIsMatrixCartesian(int matrix[][]){
		for(int i=0;i<matrix.length;i++){
			if(matrix[i][i] != 2){
				System.out.println("Matrix is not Cartesian Matrix");
				return false;
			}
		}
		for(int i=0;i<matrix.length;i++){
			for(int j=0;j<matrix[i].length;j++){
				if(i==j){
					continue;
				}
				else{
					if((matrix[i][j] >2 || matrix[i][j]<-3) && matrix[i][j]==1){
						System.out.println("Matrix is not Cartesian Matrix");
						return false;
					}
					if(matrix[i][j] ==0 && matrix[j][i]!=0){
						System.out.println("Matrix is not Cartesian Matrix");
						return false;
					}
				}
			}
		}
		return true;
	}
}


