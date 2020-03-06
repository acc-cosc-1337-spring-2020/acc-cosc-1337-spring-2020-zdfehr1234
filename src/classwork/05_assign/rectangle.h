#include <iostream>

using std::cout; using std::cin;

/*
Create the interface for a Rectangle class with one constructor that accepts two int parameters (width, height),
has one public function area that returns the area of the rectangle, and one private function calculate_area
that calculates area of the rectangle.  The class has 3 int private variables area, width, and height.
*/

class Rect
{
public:
	Rect(int w, int h) : width{ w }, height{ h } {calculate_area();};
	int get_area()const { return area; }
	friend std::ostream& operator<<(std::ostream & out, const Rect& b);

private:
	int area{ 0 };
	int width{ 0 };
	int height{ 0 };
	void calculate_area();
	

};


//write the class function code for constructor, calculate_area, and get_area functions,