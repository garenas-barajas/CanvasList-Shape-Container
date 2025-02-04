#include <gtest/gtest.h>

#include "canvaslist.h"
#include "shape.h"

//Test all shapes
//test shape
TEST(CanvasListTest, shapeCopyTest){
    CanvasList myCanvas;
    Shape* a = new Shape();
    //test setX and setY
    a->setX(1);
    a->setY(2);
    Shape* copyA = a->copy();
    Shape* b = new Shape(3,4);
    Shape* copyB = b->copy();

    bool resultA = (a->getX() == copyA->getX() && a->getY() == copyA->getY());
    bool resultB = (b->getX() == copyB->getX() && b->getY() == copyB->getY());

    //copy should have the same values as original
    EXPECT_EQ(true, resultA);
    EXPECT_EQ(true, resultB);
}

//test shape as_string
TEST(CanvasListTest, shapeStringTest){
    CanvasList myCanvas;
    Shape* a = new Shape();
    a->setX(1);
    a->setY(2);
    string result = a->as_string();
    string expected = "It's a Shape at x: 1, y: 2";

    //result should be "It's a Shape at x: 1, y: 2"
    EXPECT_EQ(expected, result);
}

//test 2 shapes of equal value
TEST(CanvasListTest, shapeEqualTest){
    CanvasList myCanvas;
    Shape* a = new Shape(1,2);
    Shape* b = new Shape(1,2);

    //true
    bool result = (a->getX() == b->getX() && a->getY() == b->getY());

    //a and b should be equal
    EXPECT_EQ(true, result);
}

//Test 2 shapes of unequal value
TEST(CanvasListTest, shapeNotEqualTest){
    CanvasList myCanvas;
    Shape* a = new Shape(1,2);
    Shape* b = new Shape(3,4);

    //true
    bool result = (a->getX() != b->getX() && a->getY() != b->getY());

    //a and b should not be equal
    EXPECT_EQ(true, result);
}

//test circle
TEST(CanvasListTest, circleTest){
    CanvasList myCanvas;
    Circle* a = new Circle();
    a->setX(1);
    a->setY(2);
    a->setRadius(3);
    Circle* b = new Circle(1);
    Circle* c = new Circle(1,2,3);
    Circle* copy = c->copy();

    myCanvas.push_back(a);
    myCanvas.push_back(b);
    myCanvas.push_back(copy);

    //Expect size 3 and copy to be equal to original
    EXPECT_EQ(3, myCanvas.size());

    //Test a
    EXPECT_EQ(a->getX(), 1);
    EXPECT_EQ(a->getY(), 2);
    EXPECT_EQ(a->getRadius(), 3);

    //Test b
    EXPECT_EQ(b->getX(), 0);
    EXPECT_EQ(b->getY(), 0);
    EXPECT_EQ(b->getRadius(), 1);

    //Test c
    EXPECT_EQ(c->getX(), 1);
    EXPECT_EQ(c->getY(), 2);
    EXPECT_EQ(c->getRadius(), 3);
}

//test circle with negative radius
TEST(CanvasListTest, circleNegativeRadiusTest){
    CanvasList myCanvas;
    Circle* a = new Circle(1,2,-3);

    myCanvas.push_back(a);
    
    //Expect size 3 and copy to be equal to original
    EXPECT_EQ(1, myCanvas.size());
    EXPECT_EQ(1, a->getX());
    EXPECT_EQ(2, a->getY());
    EXPECT_EQ(-3, a->getRadius());
}

//test getters for circle
TEST(CanvasListTest, circleGettersTest){
    Circle* a = new Circle();

    //x should be 1, y should be 2, and radius should be 3
    EXPECT_EQ(0, a->getX());
    EXPECT_EQ(0, a->getY());
    EXPECT_EQ(0, a->getRadius());
}

//test circle as_string
TEST(CanvasListTest, circleStringTest){
    Circle* c = new Circle(1,2,3);
    string result = c->as_string();
    string expected = "It's a Circle at x: 1, y: 2, radius: 3";

    //result should be "It's a Circle at x: 1, y: 2, radius: 3"
    EXPECT_EQ(expected, result);
}

//test 2 circles of equal value
TEST(CanvasListTest, circleEqualTest){
    Circle* a = new Circle(1,2,3);
    Circle* b = new Circle(1,2,3);

    //true
    bool result = (a->getX() == b->getX() && a->getY() == b->getY() && a->getRadius() == b->getRadius());

    //a and b should be equal
    EXPECT_EQ(true, result);
}

//Test 2 circles of unequal value
TEST(CanvasListTest, circleNotEqualTest){
    Circle* a = new Circle(1,2,3);
    Circle* b = new Circle(4,5,6);

    //true
    bool result = (a->getX() != b->getX() && a->getY() != b->getY() && a->getRadius() != b->getRadius());

    //a and b should not be equal
    EXPECT_EQ(true, result);
}

//test rectangle
TEST(CanvasListTest, rectangleTest){
    CanvasList myCanvas;
    Rect* a = new Rect();
    a->setX(1);
    a->setY(2);
    a->setWidth(3);
    a->setHeight(4);
    Rect* b = new Rect(1,2);
    Rect* c = new Rect(1,2,3,4);
    Rect* copy = c->copy();

    myCanvas.push_back(a);
    myCanvas.push_back(b);
    myCanvas.push_back(copy);

    bool result = (c->getX() == copy->getX() && c->getY() == copy->getY() && c->getWidth() == copy->getWidth() && c->getHeight() == copy->getHeight());

    //Expect size 3 and copy to be equal to original
    EXPECT_EQ(3, myCanvas.size());
    EXPECT_EQ(true, result);
}

//test getters for rectangle
TEST(CanvasListTest, rectangleGettersTest){
    Rect* a = new Rect(1,2,3,4);
    int x = a->getX();
    int y = a->getY();
    int width = a->getWidth();
    int height = a->getHeight();

    //x should be 1, y should be 2, width should be 3, and height should be 4
    EXPECT_EQ(1, x);
    EXPECT_EQ(2, y);
    EXPECT_EQ(3, width);
    EXPECT_EQ(4, height);
}

//test rectangle as_string
TEST(CanvasListTest, rectangleStringTest){
    Rect* a = new Rect(1,2,3,4);
    string result = a->as_string();
    string expected = "It's a Rectangle at x: 1, y: 2 with width: 3 and height: 4";

    //result should be "It's a Rectangle at x: 1, y: 2 width: 3 height: 4"
    EXPECT_EQ(expected, result);
}

//test 2 rectangles of equal value
TEST(CanvasListTest, rectangleEqualTest){
    Rect* a = new Rect(1,2,3,4);
    Rect* b = new Rect(1,2,3,4);

    //true
    bool result = (a->getX() == b->getX() && a->getY() == b->getY() && a->getWidth() == b->getWidth() && a->getHeight() == b->getHeight());

    //a and b should be equal
    EXPECT_EQ(true, result);
}

//Test 2 rectangles of unequal value
TEST(CanvasListTest, rectangleNotEqualTest){
    Rect* a = new Rect(1,2,3,4);
    Rect* b = new Rect(5,6,7,8);

    //true
    bool result = (a->getX() != b->getX() && a->getY() != b->getY() && a->getWidth() != b->getWidth() && a->getHeight() != b->getHeight());

    //a and b should not be equal
    EXPECT_EQ(true, result);
}

//test right triangle
TEST(CanvasListTest, rightTriangleTest){
    CanvasList myCanvas;
    RightTriangle* a = new RightTriangle();
    a->setX(1);
    a->setY(2);
    a->setBase(3);
    a->setHeight(4);
    RightTriangle* b = new RightTriangle(1,2);
    RightTriangle* c = new RightTriangle(1,2,3,4);
    RightTriangle* copy = c->copy();

    myCanvas.push_back(a);
    myCanvas.push_back(b);
    myCanvas.push_back(c);

    bool result = (c->getX() == copy->getX() && c->getY() == copy->getY() && c->getBase() == copy->getBase() && c->getHeight() == copy->getHeight());

    //Expect size 3 and copy to be equal to original
    EXPECT_EQ(3, myCanvas.size());
    EXPECT_EQ(true, result);
}

//test getters for right triangle
TEST(CanvasListTest, rightTriangleGettersTest){
    RightTriangle* a = new RightTriangle(1,2,3,4);
    int x = a->getX();
    int y = a->getY();
    int base = a->getBase();
    int height = a->getHeight();

    //x should be 1, y should be 2, base should be 3, and height should be 4
    EXPECT_EQ(1, x);
    EXPECT_EQ(2, y);
    EXPECT_EQ(3, base);
    EXPECT_EQ(4, height);
}

//test copy constructor on empty list
TEST(CanvasListTest, copyEmptyTest){
    CanvasList myCanvas;
    CanvasList myCanvasCopy(myCanvas);
    bool is_empty = myCanvasCopy.empty();

    //myCanvasCopy should be empty
    EXPECT_EQ(true, is_empty);
}

//Test the default constructor
TEST(CanvasListTest, defaultTest) {
    CanvasList myCanvas;
    bool is_empty = myCanvas.empty();

    //myCanvas should be empty
    EXPECT_EQ(true, is_empty);
}

//Test the copy constructor
TEST(CanvasListTest, copyTest){
    CanvasList myCanvas;
    Shape* a = new Shape();
    Shape* b = new Shape();
    myCanvas.push_front(a);
    myCanvas.push_front(b);
    CanvasList myCanvasCopy(myCanvas);

    //myCanvasCopy should be a deep copy of myCanvas
    EXPECT_EQ(myCanvas.size(), myCanvasCopy.size());
    EXPECT_EQ(myCanvas.shape_at(0)->getX(), myCanvasCopy.shape_at(0)->getX());
}

//Test operator= on exisitng list
TEST(CanvasListTest, operatorTest){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Shape* b = new Shape();
    myCanvas.push_front(a);
    myCanvas.push_front(b);
    CanvasList myCanvas2 = myCanvas;

    //myCanvas2 should be a deep copy of myCanvas
    EXPECT_EQ(myCanvas.size(), myCanvas2.size());
    EXPECT_EQ(myCanvas.front()->value->getX(), myCanvas2.front()->value->getX());
}

//Test operator= on empty list
TEST(CanvasListTest, operatorEmptyTest){
    CanvasList myCanvas;
    CanvasList myCanvas2 = myCanvas;
    bool is_empty = myCanvas2.empty();

    //myCanvas2 should be empty
    EXPECT_EQ(true, is_empty);
}

//Test operator= on self assignment
TEST(CanvasListTest, operatorSelfTest){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Shape* b = new Shape();
    myCanvas.push_front(a);
    myCanvas.push_front(b);
    myCanvas = myCanvas;

    //myCanvas should be a deep copy of itself
    EXPECT_EQ(myCanvas.size(), myCanvas.size());
    EXPECT_EQ(myCanvas.front()->value->getX(), myCanvas.front()->value->getX());
}

//Test operator= on list with different shapes
TEST(CanvasListTest, operatorDiffTest){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Circle* b = new Circle();
    Rect* c = new Rect(1,2,3,4);
    RightTriangle* d = new RightTriangle(4,5,6,7);
    CanvasList myCanvas2;
    myCanvas.push_front(a);
    myCanvas.push_front(b);
    myCanvas2.push_front(c);
    myCanvas2.push_front(d);
    myCanvas2 = myCanvas;

    //myCanvas should be a deep copy of myCanvas2
    EXPECT_EQ(myCanvas.size(), myCanvas2.size());
    EXPECT_EQ(myCanvas.front()->value->getX(), myCanvas2.front()->value->getX());
}

//Test clear on non-empty list
TEST(CanvasListTest, clearTestNonEmpty){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Shape* b = new Shape();
    myCanvas.push_front(a);
    myCanvas.push_front(b);
    bool isEmpty = myCanvas.empty();

    //myCanvas should be not be empty
    EXPECT_EQ(false, isEmpty);

    myCanvas.clear();
    isEmpty = myCanvas.empty();

    //myCanvas should be empty
    EXPECT_EQ(true, isEmpty);
}

//Test clear on empty list
TEST(CanvasListTest, clearTestEmpty){
    CanvasList myCanvas;
    myCanvas.clear();
    bool isEmpty = myCanvas.empty();

    //myCanvas should be empty
    EXPECT_EQ(true, isEmpty);
}

//Test clear on empty list
TEST(CanvasListTest, clearEmptyTest){
    CanvasList myCanvas;
    bool isEmpty = myCanvas.empty();

    //myCanvas should be empty
    EXPECT_EQ(true, isEmpty);
}

//Test insert_after end of list, also tests shape_at
TEST(CanvasListTest, insertAferTest){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Shape* b = new Shape();
    Shape* c = new Shape();
    myCanvas.push_front(a);
    myCanvas.push_front(b);
    myCanvas.insert_after(1, c);

    //c is expected to be at index 2
    EXPECT_EQ(c, myCanvas.shape_at(2));
}

//Test insert_after front node
TEST(CanvasListTest, insertAfterFrontTest){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Circle* b = new Circle();
    Rect* c = new Rect();
    RightTriangle* d = new RightTriangle();
    myCanvas.push_front(a);
    myCanvas.push_front(b);
    myCanvas.push_front(c);
    myCanvas.insert_after(0, d);

    //c is expected to be at index 1
    EXPECT_EQ(d, myCanvas.shape_at(1));
    EXPECT_EQ(4, myCanvas.size());
}

//Test insert_after invalid index
TEST(CanvasListTest, insertAfterInvalidTest){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Rect* b = new Rect();
    Circle* c = new Circle();
    myCanvas.push_front(a);
    myCanvas.insert_after(-1, b);
    myCanvas.insert_after(2, c);

    //list should only contain a
    EXPECT_EQ(1, myCanvas.size());
}

//Test insert_after empty list
TEST(CanvasListTest, insertAfterEmptyTest){
    CanvasList myCanvas;
    Shape* a = new Shape();
    myCanvas.insert_after(0, a);

    //list should remain empty
    EXPECT_EQ(0, myCanvas.size());
}

//Test multiple insert_after
TEST(CanvasListTest, insertAfterMultipleTest){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Shape* b = new Shape(1, 2);
    Shape* c = new Shape(3, 4);
    Shape* d = new Shape(5, 6);
    Shape* e = new Shape(7, 8);
    myCanvas.push_front(a);
    myCanvas.push_front(b);
    myCanvas.insert_after(0, c);
    myCanvas.insert_after(2, d);
    myCanvas.insert_after(1, e);

    //e is expected to be at index 2
    EXPECT_EQ(e, myCanvas.shape_at(2));
    EXPECT_EQ(myCanvas.size(), 5);

    //check value of c and shape at index 1
    EXPECT_EQ(myCanvas.shape_at(1)->getX(), 3);
    EXPECT_EQ(myCanvas.shape_at(1)->getY(), 4);
}

//Test multiple push_front
TEST(CanvasListTest, pushFrontTest){
    CanvasList  myCanvas;
    Shape* a = new Shape(0,0);
    Shape* b = new Shape();
    Shape* c = new Shape();
    Shape* d = new Shape();
    Shape* e = new Shape();
    myCanvas.push_front(a);
    myCanvas.push_front(b);
    myCanvas.push_front(c);
    myCanvas.push_front(d);
    myCanvas.push_front(e);

    //b is expected to be the front of the list
    EXPECT_EQ(e, myCanvas.front()->value);
    EXPECT_EQ(5, myCanvas.size());
}

//Test push_back
TEST(CanvasListTest, pushBackTest){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Shape* b = new Shape();
    myCanvas.push_back(a);
    myCanvas.push_back(b);

    //b is expected to be at the back of the list
    EXPECT_EQ(b, myCanvas.pop_back());
    EXPECT_EQ(1, myCanvas.size());
}

//Test remove_at
TEST(CanvasListTest, removeAtTest){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Shape* b = new Shape();
    myCanvas.push_back(a);
    myCanvas.push_back(b);
    myCanvas.remove_at(0);

    //a is expected to be removed
    EXPECT_EQ(b, myCanvas.front()->value);
}

//Test multiple remove_at
TEST(CanvasListTest, removeAtMultipleTest){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Shape* b = new Shape();
    Shape* c = new Shape();
    myCanvas.push_back(a);
    myCanvas.push_back(b);
    myCanvas.push_back(c);
    myCanvas.remove_at(0);
    myCanvas.remove_at(1);

    //a and c are expected to be removed
    EXPECT_EQ(b, myCanvas.front()->value);
}

//Test remove_every_other
TEST(CanvasListTest, removeEveryOtherTest){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Shape* b = new Shape();
    Shape* c = new Shape();
    Shape* d = new Shape();
    Shape* e = new Shape();
    myCanvas.push_back(a);
    myCanvas.push_back(b);
    myCanvas.push_back(c);
    myCanvas.push_back(d);
    myCanvas.push_back(e);
    myCanvas.remove_every_other();

    //b and d are expected to be removed
    EXPECT_EQ(a, myCanvas.shape_at(0));
    EXPECT_EQ(c, myCanvas.shape_at(1));
    EXPECT_EQ(e, myCanvas.shape_at(2));
}

//Test pop_front
TEST(CanvasListTest, popFrontTest){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Shape* b = new Shape();
    myCanvas.push_front(a);
    myCanvas.push_front(b);

    //b should be removed and a should be at the front
    EXPECT_EQ(b, myCanvas.pop_front());
    EXPECT_EQ(a, myCanvas.front()->value);
}

//Test pop_front empty list
TEST(CanvasListTest, popFrontEmptyTest){
    CanvasList myCanvas;
    myCanvas.pop_front();

    //myCanvas should be empty
    EXPECT_EQ(0, myCanvas.size());
}

//Test pop_front until list is empty
TEST(CanvasListTest, popFrontMultipleTest){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Shape* b = new Shape();
    Shape* c = new Shape();
    myCanvas.push_front(a);
    myCanvas.push_front(b);
    myCanvas.push_front(c);

    //myCanvas should be empty
    EXPECT_EQ(c, myCanvas.pop_front());
    EXPECT_EQ(b, myCanvas.pop_front());
    EXPECT_EQ(a, myCanvas.pop_front());
    EXPECT_EQ(0, myCanvas.size());
}

//Test search for node after removing it
TEST(CanvasListTest, searchAfterRemoveTest){
    CanvasList myCanvas;
    Shape* a = new Shape(2,7);

    myCanvas.push_back(a);
    myCanvas.pop_front();

    //find should return -1
    EXPECT_EQ(-1, myCanvas.find(2,7));

}

//Test pop_back
TEST(CanvasListTest, popBackTest){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Shape* b = new Shape();
    myCanvas.push_back(a);
    myCanvas.push_back(b);

    //b should be removed and a should be the only shape in the list
    EXPECT_EQ(b, myCanvas.pop_back());
    EXPECT_EQ(1, myCanvas.size());
}

//Test multiple pop_back
TEST(CanvasListTest, popBackMultipleTest){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Shape* b = new Shape();
    Shape* c = new Shape();
    myCanvas.push_back(a);
    myCanvas.push_back(b);
    myCanvas.push_back(c);
    myCanvas.pop_back();
    myCanvas.pop_back();

    //c should be removed and a should be the only shape in the list
    EXPECT_EQ(a, myCanvas.front()->value);
    EXPECT_EQ(1, myCanvas.size());
}

//Test pop_back empty list
TEST(CanvasListTest, popBackEmptyTest){
    CanvasList myCanvas;
    myCanvas.pop_back();

    //myCanvas should be empty
    EXPECT_EQ(0, myCanvas.size());
}

//Test pop_back until list is empty
TEST(CanvasListTest, popBackMultipleEmptyTest){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Shape* b = new Shape();
    Shape* c = new Shape();
    myCanvas.push_back(a);
    myCanvas.push_back(b);
    myCanvas.push_back(c);
    myCanvas.pop_back();
    myCanvas.pop_back();
    myCanvas.pop_back();

    //myCanvas should be empty
    EXPECT_EQ(0, myCanvas.size());
}

//Test search for node after removing it
TEST(CanvasListTest, searchAfterRemove2Test){
    CanvasList myCanvas;
    Shape* a = new Shape(2,7);

    myCanvas.push_back(a);
    myCanvas.pop_back();

    //find should return -1
    EXPECT_EQ(-1, myCanvas.find(2,7));
}

//Test front
TEST(CanvasListTest, frontTest){
    CanvasList myCanvas;
    Shape* a = new Shape(0,0);
    Shape* b = new Shape();
    myCanvas.push_front(a);
    myCanvas.push_front(b);

    EXPECT_EQ(b, myCanvas.front()->value);
}

//Test size
TEST(CanvasListTest, sizeTest){
    CanvasList myCanvas;
    Shape* a = new Shape();
    Shape* b = new Shape();
    Shape* c = new Shape();
    Shape* d = new Shape();
    myCanvas.push_back(a);
    myCanvas.push_back(b);
    myCanvas.push_back(c);
    myCanvas.push_back(d);

    //myCanvas size should return 4
    EXPECT_EQ(4, myCanvas.size());
}

//test find
TEST(CanvasListTest, findTest){
        CanvasList myCanvas;
    Shape* a = new Shape();
    Shape* b = new Shape();
    Shape* c = new Shape(1,2);
    Shape* d = new Shape();
    myCanvas.push_back(a);
    myCanvas.push_back(b);
    myCanvas.push_back(c);
    myCanvas.push_back(d);

    //c is expected to be at index 2
    EXPECT_EQ(2, myCanvas.find(1,2));
}

//test find cannot find shape
TEST(CanvasList, findTest2){
    CanvasList myCanvas;
    Shape* a = new Shape();
    Shape* b = new Shape();
    Shape* c = new Shape(1,2);
    Shape* d = new Shape();
    myCanvas.push_back(a);
    myCanvas.push_back(b);
    myCanvas.push_back(c);
    myCanvas.push_back(d);

    //find should return -1
    EXPECT_EQ(-1, myCanvas.find(3,4));
}

//test shape_at
TEST(CanvasList, shapeAtTest){
        CanvasList myCanvas;
    Shape* a = new Shape();
    Shape* b = new Shape();
    Shape* c = new Shape();
    Shape* d = new Shape();
    myCanvas.push_back(a);
    myCanvas.push_back(b);
    myCanvas.push_back(c);
    myCanvas.push_back(d);

    //c is expected to be at index 2
    EXPECT_EQ(c, myCanvas.shape_at(2));
}

//test shape_at invalid index
TEST(CanvasList, shapeAtTest2){
    CanvasList myCanvas;
    Shape* a = new Shape();
    Shape* b = new Shape();
    Shape* c = new Shape();
    Shape* d = new Shape();
    myCanvas.push_back(a);
    myCanvas.push_back(b);
    myCanvas.push_back(c);
    myCanvas.push_back(d);

    //shape_at should return nullptr
    EXPECT_EQ(nullptr, myCanvas.shape_at(4));
}