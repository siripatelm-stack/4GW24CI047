interface Resizable{
	void resizeWidth(int width);
	void resizeHeight(int height);
}
class Rectangle implements Resizable{
	int width;
	int height;
	Rectangle(int w,int h){
		width=w;
		height=h;
	}
	void display() {
		System.out.println("Width: "+width+" ,Height: "+height);
	}
	public void resizeWidth(int newWidth) {
		width=newWidth;
	}
	public void resizeHeight(int newHeight) {
		height=newHeight;
	}
}
public class ResizeTest {
	public static void main(String[] args) {
		Rectangle rect=new Rectangle(10,20);
		System.out.println("Original Size:");
		rect.display();
		rect.resizeWidth(30);
		rect.resizeHeight(40);
		System.out.println("Resized Size:");
		rect.display();
	}
}
