#include "shape.h"

#include <string>

using namespace std;

//default constructor
Shape::Shape() {
    this->x = 0;
    this->y = 0;
}

//constructor with 2 parameters
Shape::Shape(int x, int y) {
    this->x = x;
    this->y = y;
}

//destructor
Shape::~Shape() {
}

//create a copy of the shape with the same values
Shape* Shape::copy() {
    Shape* s = new Shape(this->x, this->y);

    return s;
}

int Shape::getX() const {
    return this->x;
}

int Shape::getY() const {
    return this->y;
}

void Shape::setX(int x) {
    this->x = x;
}

void Shape::setY(int y) {
    this->y = y;
}

string Shape::as_string() const {
    return "It's a Shape at x: " + to_string(this->x) + ", y: " + to_string(this->y);
}

//default constructor for Circle
Circle::Circle() : Shape() {
    this->radius = 0;
}

//constructor with 1 parameter for Circle
Circle::Circle(int r) : Shape() {
    this->radius = r;
}

//constructor with 3 parameters for Circle
Circle::Circle(int x, int y, int r) : Shape(x, y){
    this->radius = r;
}

//destructor for Circle
Circle::~Circle(){   
}

//create a copy of the circle with the same values
Circle* Circle::copy(){
    Circle* c = new Circle(this->x, this->y, this->radius);

    return c;
}

//return the radius of the circle
int Circle::getRadius() const{
    return this->radius;
}

//set radius of circle
void Circle::setRadius(int r){
    this->radius = r;
}

//return a string representation of the circle
string Circle::as_string() const{
    return "It's a Circle at x: " + to_string(this->x) + ", y: " + to_string(this->y) + ", radius: " + to_string(this->radius);
}

//default constructor for Rectangle
Rect::Rect() : Shape() {
    this->width = 0;
    this->height = 0;
}

//constructor with 2 parameters for Rectangle
Rect::Rect(int w, int h) : Shape() {
    this->width = w;
    this->height = h;
}

//constructor with 4 parameters for Rectangle
Rect::Rect(int x, int y, int w, int h) : Shape(x, y) {
    this->width = w;
    this->height = h;
}

//destructor for Rectangle
Rect::~Rect(){
}

//create a copy of the rectangle with the same values
Rect* Rect::copy(){
    Rect* r = new Rect(this->x, this->y, this->width, this->height);

    return r;
}

//return the width of the rectangle
int Rect::getWidth() const{
    return this->width;
}

//return the height of the rectangle
int Rect::getHeight() const{
    return this->height;
}

//set the width of the rectangle
void Rect::setWidth(int w){
    this->width = w;
}

//set the height of the rectangle
void Rect::setHeight(int h){
    this->height = h;
}

//return a string representation of the rectangle
string Rect::as_string() const{
    return "It's a Rectangle at x: " + to_string(this->x) + ", y: " + to_string(this->y) + " with width: " + to_string(this->width) + " and height: " + to_string(this->height);
}

//default constructor for right triangle
RightTriangle::RightTriangle() : Shape() {
    this->base = 0;
    this->height = 0;
}

//constructor with 2 parameters for right triangle
RightTriangle::RightTriangle(int b, int h) : Shape() {
    this->base = b;
    this->height = h;
}

//constructor with 4 parameters for right triangle
RightTriangle::RightTriangle(int x, int y, int b, int h) : Shape(x,y) {
    this->base = b;
    this->height = h;
}

//destructor for right triangle
RightTriangle::~RightTriangle(){
}

//create a copy of the right triangle with the same values
RightTriangle* RightTriangle::copy(){
    RightTriangle* rt = new RightTriangle(this->x, this->y, this->base, this->height);

    return rt;
}

//return the base of the right triangle
int RightTriangle::getBase() const{
    return this->base;
}

//return the height of the right triangle
int RightTriangle::getHeight() const{
    return this->height;
}

//set the base of the right triangle
void RightTriangle::setBase(int b){
    this->base = b;
}

//set the height of the right triangle
void RightTriangle::setHeight(int h){
    this->height = h;
}

//return a string representation of the right triangle
string RightTriangle::as_string() const{
    return "It's a Right Triangle at x: " + to_string(this->x) + ", y: " + to_string(this->y) + " with base: " + to_string(this->base) + " and height: " + to_string(this->height);
}