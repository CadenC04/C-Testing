#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

void solveSides(double& a, double& b, double& c, double A, double B, double C) {
	double AA = (A * (M_PI/180));
	double BB = (B * (M_PI/180));
	double CC = (C * (M_PI/180));
	if (a != 0) {
		b = (a*sin(BB)/sin(AA));
		c = (a*sin(CC)/sin(AA));
	} else if (b != 0) {
		a = (b*sin(AA)/sin(BB));
		c = (b*sin(CC)/sin(BB));
	} else {
		a = (c*sin(AA)/sin(CC));
		b = (c*sin(BB)/sin(CC));
	}
	cout << "\n" << "Angle A, B, C: " << A << ", " << B << ", " << C;
	cout << "\n" << "Side a, b, c: " << a << ", " << b << ", " << c << "\n";
}

void getAngles(double a, double b, double c, double& A, double& B, double& C) {
	if (A == 0) {
		A = (180 - B - C);
	} else if (B == 0) {
		B = (180 - A - C);
	} else {
		C = (180 - A - B);
	}
	solveSides(a, b, c, A, B, C);
}

void getAngEquation(double a, double b, double c, double A, double B, double C) {
	string type;
	if (A != 0) {
		type += "1";
	} else {
		type += "0";
	}
	if (B != 0) {
		type += "1";
	} else {
		type += "0";
	}
	if (C != 0) {
		type += "1";
	} else {
		type += "0";
	}
	int Type = stoi(type);

	switch (Type)
	{
	case 0:
		cout << "Invalid Parameters";
		break;
	case 111:
		solveSides(a, b, c, A, B, C);
		break;
	case 110:
	case 11:
	case 101:
		getAngles(a, b, c, A, B, C);
		break;
	case 1:
	case 10:
	case 100:
		cout << "Invalid Parameters";
		break;
	default:
		break;
	}
}

void solveAngles(double a, double b, double c, double& A, double& B, double& C) {
	A = (acos(((b * b) + (c * c) - (a * a)) / (2 * b * c))) * (180/M_PI);
	B = (acos(((c * c) + (a * a) - (b * b)) / (2 * c * a))) * (180/M_PI);
	C = (acos(((a * a) + (b * b) - (c * c)) / (2 * a * b))) * (180/M_PI);
	cout << "\n" << "Angle A, B, C: " << A << ", " << B << ", " << C;
	cout << "\n" << "Side a, b, c: " << a << ", " << b << ", " << c << "\n";
}

void pythagThero(double& a, double& b, double& c, double& A, double& B, double& C) {
	if (a == 0) {
		a = sqrt((c * c) - (b * b));
	} else if (b == 0) {
		b = sqrt((c * c) - (a * a));
	} else {
		c = sqrt((a * a) + (b * b));
	}
	solveAngles(a, b, c, A, B, C);
}

void getEquation(double a, double b, double c, double A, double B, double C) {
	string type;
	if (a != 0) {
		type += "1";
	} else {
		type += "0";
	}
	if (b != 0) {
		type += "1";
	} else {
		type += "0";
	}
	if (c != 0) {
		type += "1";
	} else {
		type += "0";
	}
	int Type = stoi(type);

	switch (Type)
	{
	case 0:
		cout << "Invalid Parameters";
		break;
	case 111: 
		solveAngles(a, b, c, A, B, C);
		break;
	case 110:
	case 11:
	case 101:
		pythagThero(a, b, c, A, B, C);
		break;
	case 100:
	case 10:
	case 1:
		getAngEquation(a, b, c, A, B, C);
		break;
	default:
		break;
	}
}

void getData(double& a, double& b, double& c, double& A, double& B, double& C) {
	cout << "          /|C" << "\n" << "         / |" << "\n";
	cout << "        /  |" << "\n" << "       /   |" << "\n";
	cout << "     b/    |a" << "\n" << "     /     |" << "\n";
	cout << "    /      |" << "\n" << "  A/_______|B" << "\n" << "       c"; 
	cout << "\n" << "\n";
	cout << "Enter side a: ";
	cin >> a;
	cout << "Enter side b: ";
	cin >> b;
	cout << "Enter side c: ";
	cin >> c;
	cout << "Enter angle A: ";
	cin >> A;
	cout << "Enter angle B: ";
	cin >> B;
	cout << "Enter angle C: ";
	cin >> C;
	getEquation(a, b, c, A, B, C);
}

int main() {
	double a, b, c, A, B, C;
	cout << "This program will calculate the remaining ";
	cout << "angles and/or sides for the triangle." << "\n";
	cout << "If the data you are being asked to input is ";
	cout << "unknown then just enter 0." << "\n" << "\n";
	getData(a, b, c, A, B, C);
	return 0;
}