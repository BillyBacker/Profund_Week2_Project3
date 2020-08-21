#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

double exp(char prefix) {
	if (prefix == '*') {
		return 1;
	}
	else if (prefix == 'K') {
		return pow(10, 3);
	}
	else if (prefix == 'M') {
		return pow(10, 6);
	}
	else if (prefix == 'G') {
		return pow(10, 9);
	}
	else if (prefix == 'T') {
		return pow(10, 12);
	}
	else if (prefix == 'P') {
		return pow(10, 15);
	}
}

double pure(double In, char prefix) {
	return In * exp(prefix);
}

int main() {
	double In, Full;
	char prefix;
	printf("Enter number with prefix (use * if no prefix) : ");
	scanf("%lf%c", &In, &prefix);
	Full = pure(In, prefix);
	if (Full < 0.5 * exp('K')) {
		printf("%.2f", Full);
	}
	else if (Full * 1.0 >= 0.5 * exp('K') && Full < 0.5 * exp('M')) {
		printf("%.2lf%c", Full *1.0 / exp('K'), 'K');
	}
	else if (Full * 1.0 >= 0.5 * exp('M') && Full < 0.5 * exp('G')) {
		printf("%.2lf%c", Full *1.0/ exp('M'), 'M');
	}
	else if (Full * 1.0 >= 0.5 * exp('G') && Full < 0.5 * exp('T')) {
		printf("%.2lf%c", Full * 1.0 / exp('G'), 'G');
	}
	else if (Full * 1.0 >= 0.5 * exp('T') && Full < 0.5 * exp('P')) {
		printf("%.2lf%c", Full * 1.0 / exp('T'), 'T');
	}
}