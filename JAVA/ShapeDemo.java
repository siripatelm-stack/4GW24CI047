//Base class 
class SHAPE{
	void draw() {
		System.out.println("Drawing Shape");	
		}
	void erase() {
		System.out.println("Erasing Shape");
	}
}
//Subclass Circle
class Circle extends SHAPE{
	void draw() {
		System.out.println("Drawing Circle");
	}
	void erase() {
		System.out.println("Erasing Circle");
	}
}
class Triangle extends SHAPE{
	void draw() {
		System.out.println("Drawing Triangle");
	}
	void erase() {
		System.out.println("Erasing Triangle");
	}
}
class Square extends SHAPE{
	void draw() {
		System.out.println("Drawing Square");
	}
	void erase() {
		System.out.println("Erasing Square");
	}
}
public class ShapeDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SHAPE shape;
		shape= new Circle();
		shape.draw();
		shape.erase();
		shape=new Triangle();
		shape.draw();
		shape.erase();
		shape=new Square();
		shape.draw();
		shape.erase();
	}
}