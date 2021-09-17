#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Rect {
	float minX;
	float minY;
	float maxX;
	float maxY;
};

float DistanceToRect(float x, float y, Rect& rect)
{
	// function returns the distance from a 2D point to the nearest edge of a rectangle
	// returns 0 if the point is inside of the rectangle
	
	if (x >= rect.minX && x <= rect.maxX) {
		if (y <= rect.minY) { return abs(y); } 			// Above
		else if (y >= rect.maxY) { return (y - rect.maxY); } 	// Below
	}

	if (y >= rect.minY && y <= rect.maxY) {
		if (x <= rect.minX) { return abs(x); } 			// Left
		else if (x >= rect.maxX) { return (x - rect.maxX); } 	// Right
	}

	if ((x < rect.minX && y < rect.minY)				// Top Left
	    || (x > rect.maxX && y < rect.minY)				// Top Right
	    || (x < rect.minX && y > rect.maxY)				// Bottom Left
	    || (x > rect.maxX && y > rect.maxY)				// Bottom Right
	   ) {
		return (sqrt(pow(abs(x), 2) + pow(abs(y), 2)));
	}

	// Inside
	return 0;
}

int main(void)
{
	struct Rect r;
	r.minX = 0;
	r.minY = 0;
	r.maxX = 5;
	r.maxY = 5;

	// TEST CODE
	printf("Above: \t\t%s\n", DistanceToRect(2, -2, r) == float(2) ? "Passed" : "Failed");
	printf("Below: \t\t%s\n", DistanceToRect(2, 7, r) == float(2) ? "Passed" : "Failed");
	printf("Left: \t\t%s\n", DistanceToRect(-2, 1, r) == float(2) ? "Passed" : "Failed");
	printf("Right: \t\t%s\n", DistanceToRect(7, 2, r) == float(2) ? "Passed" : "Failed");
	printf("Top Left: \t%s\n", DistanceToRect(-6, -8, r) == float(10) ? "Passed" : "Failed");
	printf("Top Right: \t%s\n", DistanceToRect(6, -8, r) == float(10) ? "Passed" : "Failed");
	printf("Bottom Left: \t%s\n", DistanceToRect(-6, 8, r) == float(10) ? "Passed" : "Failed");
	printf("Bottom Right: \t%s\n", DistanceToRect(6, 8, r) == float(10) ? "Passed" : "Failed");
	printf("Inside Rect: \t%s\n", DistanceToRect(1, 2, r) == float(0) ? "Passed" : "Failed");
}
