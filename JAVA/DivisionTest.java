class DivisionByZeroException extends Exception{
	DivisionByZeroException(String message){
		super(message);
	}
}
public class DivisionTest {
	public static void main(String[] args) {
		int num=10;
		int den=0;
		try {
			if(den==0) {
				throw new DivisionByZeroException("Division by zero is not allowed!");
			}
			int result=num/den;
			System.out.println("Result: "+result);
		}
		catch(DivisionByZeroException e) {
			System.out.println("Exception caught: "+e.getMessage());
		}
		finally {
			System.out.println("Finally bloch executed.");
		}
	}
}