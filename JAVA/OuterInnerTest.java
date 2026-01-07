class Outer{
	void display() {
		System.out.println("This is the outer class display method");
	}
	class Inner{
		void display() {
			System.out.println("This is the inner class display method");
		}
	}
}
public class OuterInnerTest {
	public static void main(String[] args) {
		Outer outer=new Outer();
		outer.display();
		Outer.Inner inner = outer.new Inner();
		inner.display();
	}

}
