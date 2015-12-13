/************************
 * Author: Baljot Singh
 * Date created:  11/25/2014
 * Program name: cordinateGeom.cpp
 * Description: This program will get the the two points from user in x-y plane
 *              will return the length and slope of line.
 * input: 2 set of coordinates in x-y plane
 * Output:Length and slope of line segment.
 ****************************/

 #include <iostream>
 #include <cmath>
 #include <cstdlib>


 using namespace std;

 //Declaration of class Point
 class Point
 {
 private:
	double xCord;
	double yCord;

 public:
      	 //Constructor for class which assigns values to private members
	 Point(double x1, double y1)
	 {
		xCord = x1;
		yCord = y1;
	 }

	 //member function to get value of xCord
	 double getX()const
	 {
		return xCord;
	 }

	 //member function to get value of yCord
	  double getY()const
	 {
		return yCord;
	 }

     	//method to find length
	 double distanceTo( const Point &endPoint)
	 {
		return sqrt(pow((xCord - endPoint.getX()),2) + pow((yCord - endPoint.getY()),2));
	 }
 };

 //Declaration of class LineSegment which as private members of class Point
 class LineSegment
 {
 private:
	 Point p1;
	 Point p2;

 public:
    	 //Constructor which assigns values to private members
	 LineSegment(Point first, Point second)
	 :p1(first), p2(second)
	 {}

	 //method to calculate length using method distance from class Point
	 double getLength()
	 {
		return p1.distanceTo(p2);
	 }

     	 //method to get slope
	 double getSlope()
	 {
	     	return ((p1.getY() - p2.getY())/(p1.getX() - p2.getX()));
	 }

 };


 //Starting main function
 int main()
 {
	double a1,b1,a2,b2; //Declaring 4 doubles to get user input for coordinates

	char choice;  //Variable to ask user if repeat again

	do{
		//Asking user for first coordinate
		cout << "Please give first coordinates of line segment: ";
		cin >> a1 >> b1;

    		//Asking user for second coordinate
		cout << "Please give second coordinates of line segment: ";
		cin >> a2 >> b2;

		LineSegment line(Point(a1, b1), Point(a2, b2)); //LineSegment object with argument of Point

    		//Printing length of line
    		cout << "The distance between two points is: " << line.getLength() << endl;

    		//For slope if its vertical line
    		if(isinf(line.getSlope()))
    		{
        		cout << "The line segment is vertical." << endl;
    		}

     		//For slope if its a point
    		else if(isnan(line.getSlope()))
    		{
        		cout << "This is a point." << endl;
    		}

    		//Otherwise line is at angle and printing slop
    		else
    		{
        		cout << "The slope of line segment is: " << line.getSlope() << endl;
    		}

		//Asking user if repeat again
		cout << "Please enter y for yes if you want to get length and slope of other\n";
		cout << "coordinates, otherwise enter n for no if you want to exit: ";
		cin >> choice;
	
	}while(choice == 'y');

 return 0;
 }

