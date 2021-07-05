#pragma once

enum Color {
    WHITE,
    BLACK,
    RED,
    GREEN,
    BLUE
};

class Point {
public:
    Color color = WHITE;
    double centerX = 0;
    double centerY = 0;
};

class Circle: public Point {
public:
    double radius = 0;
    Circle(Color  col, double x, double y, double r);
    double area();
};

class Triangle: public Point {
public:
    double edge = 0;
    Triangle(Color col, double x, double y, double e);
    double area();
};

class Square: public Point {
public:
    double edgeA = 0;
    Square(Color  col, double  x, double y, double e);
    double area();
};

class Rectangle: public Square {
public:
    double edgeB = 0;
    Rectangle(Color col, double x, double y, double a, double b);
    double area();
};