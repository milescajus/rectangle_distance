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
	// returns 0 if the point is inside (or on the edge) of the rectangle
	// two versions are included, with the more readable/explicit code commented out
	
	// LESS READABLE
	if (x <= rect.maxX) {
		if (x < rect.minX) {
			if (y < rect.minY) {
				// Negative Diagonal
				return sqrt(pow(abs(x), 2) + pow(abs(y), 2));
			} else {
				// Left
				return abs(x);
			}
		} else if (y < rect.minY) {
				// Above
				return abs(y);
			} else if (y > rect.maxY) {
				// Below
				return (y - rect.maxY);
			} else {
				// Inside Rect
				return 0;

			}
	} else if (y <= rect.maxY) {
			// Right
			return (x - rect.maxX);
	} else {
			// Postive Diagonal
			return sqrt(pow(x, 2) + pow(y, 2));
	}

	return 0;

	/*
	// MORE READABLE
	// Below
	if (x <= rect.maxX && y > rect.maxY) {
		return (y - rect.maxY);
	}

	// Right
	if (x > rect.maxX && y <= rect.maxY) {
		return (x - rect.maxX);
	}

	// Postive Diagonal
	if (x > rect.maxX && y > rect.maxY) {
		return (sqrt(pow(x, 2) + pow(y, 2)));
	}

	// Above
	if (x >= rect.minX && y < rect.minY) {
		return abs(y);
	}

	// Left
	if (x < rect.minX && y >= rect.minY) {
		return abs(x);
	}

	// Negative Diagonal
	if (x < rect.minX && y < rect.minY) {
		return (sqrt(pow(abs(x), 2) + pow(abs(y), 2)));
	}

	return 0;
	*/
}

int main(void)
{
	struct Rect r;
	r.minX = 0;
	r.minY = 0;
	r.maxX = 5;
	r.maxY = 5;

	// TEST CODE
	printf("Below: %s\n", DistanceToRect(2, 7, r) == float(2) ? "Passed" : "Failed");
	printf("Right: %s\n", DistanceToRect(7, 2, r) == float(2) ? "Passed" : "Failed");
	printf("Postive Diagonal: %s\n", DistanceToRect(6, 8, r) == float(10) ? "Passed" : "Failed");
	printf("Above: %s\n", DistanceToRect(2, -2, r) == float(2) ? "Passed" : "Failed");
	printf("Left: %s\n", DistanceToRect(-2, 1, r) == float(2) ? "Passed" : "Failed");
	printf("Negative Diagonal: %s\n", DistanceToRect(-3, -4, r) == float(5) ? "Passed" : "Failed");
	printf("Inside Rect: %s\n", DistanceToRect(1, 2, r) == float(0) ? "Passed" : "Failed");
}
