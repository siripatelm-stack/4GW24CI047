import java.lang.Math;
abstract class Shape{
	abstract void area ();
	abstract void perimeter();
}
class circle extends Shape {
	double r;
	circle (double radius){
		r=radius;
	}
	void area() {
		System.out.println("Area of Circle: "+(3.14*r*r));
	}
	void perimeter() {
		System.out.println("Perimeter of Circle: "+(2*3.14*r));
	}
}
class triangle extends Shape {
	double a,b,c;
	triangle(double x,double y,double z){
		a=x;
		b=y;
		c=z;
	}
	void area() {
		double s =(a+b+c)/2;
		double ar =Math.sqrt(s*(s-a)*(s-b)*(s-c));
		System.out.println("Area of Triangle: "+ar);
	}
	void perimeter() {
		System.out.println("Perimeter of Triangle: "+(a+b+c));
	}
}

public class ShapeTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		circle c =new circle(5);
		c.area();
		c.perimeter();
		triangle t =new triangle(3,4,5);
		t.area();
		t.perimeter();
	}

}
