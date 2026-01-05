import java.util.Scanner;
public class AddMatrix {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc =new Scanner(System.in);
		//input for matrix size N
		System.out.println("Enter the order N of the matrices: ");
		int n =sc.nextInt();
		int[][] matrix1 =new int [n][n];
		int[][] matrix2 =new int [n][n];
		int[][] result =new int [n][n];
		//input for first matrix
		System.out.println("Enter the elements for matrix1:");
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				System.out.print("Element ["+i+"]["+j+"]: ");
				matrix1[i][j]=sc.nextInt();			
				}
		}
		//input for second matrix
		System.out.println("Enter the elements for matrix2:");
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				System.out.print("Element ["+i+"]["+j+"]: ");
				matrix2[i][j]=sc.nextInt();			
				}
		}
		//adding the matrices
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				result[i][j]=matrix1[i][j]+matrix2[i][j];
			}
		}
		//displaying the result
		System.out.println("\nResultant Matrix after Addition:");
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				System.out.print(result[i][j]+"\t");
				}
			System.out.println();
		}
		sc.close();
	}
}
