//
// Created by Shams Sajid on 2022-11-27.
//

#ifndef ASSIGNMENT_4_SHAPESGOOD_H
#define ASSIGNMENT_4_SHAPESGOOD_H

#pragma once
#include <string>
#include <ostream>

using namespace std;

class Shape{
public:
    Shape (const int length, const int width, const string colour);             // Constructor for the Shape
    Shape (const Shape& shape);                                                 // Copy Constructor

    virtual void draw() = 0;                     // Drawing the Shape
    virtual ~ Shape();                          // Destructor

    int getLength() const;                      // Accessor for the length
    int getWidth() const;                       // Accessor for the width
    string getColour() const;                   // Accessor for the colour


// Attributes that are private
private:
    int length;
    int width;
    string colour;

};


class Fillable {
public:
    Fillable (const string fillableColour);             // Constructor for the fillable colour
    string getFillableColour() const;                   // Accessor for the fillable colour

    virtual void fill();                            // Displaying the fill
    virtual ~ Fillable();                               // Destructor for fillable


// Attributes that are private
private:
    string fillableColour;
};


class Text {
public:
    Text (const string text);                   // Constructor for the text
    string getText() const;                     // Accessor for the text

    virtual void drawText() = 0;                // Draws the text
    virtual ~ Text();                           // Destructor for Text

// Attributes that are private
public:
    string text;
};


// --------------- Classes Extending the Shape ---------------


// For the Square shape
class Square : public Shape {
public:
    Square (const int length, const int width, const string colour);                // Constructor

    virtual void draw();                    // Draws the Square
    virtual void drawOutline() const;       // Draws the outline of the Square
    virtual ~ Square();                     // Destructor
};


// For the Circle Shape
class Circle : public Shape {
public:
    Circle (const int length, const int width, const string colour);                // Constructor

    virtual void draw();                    // Draws the Circle
    void drawOutline() const;               // Draws the outline of the Circle
    virtual ~ Circle();                     // Destructor
};


// For the Arc Shape
class Arc : public Shape {
public:
    Arc (const int length, const int width, const string colour);                // Constructor

    virtual void draw();                    // Draws the Arc
    virtual ~ Arc();                        // Destructor
};


// --------------- Classes Extending Filling the Shape ---------------


// For the Square shape
class FilledSquare : public Square, public Fillable {
public:
    FilledSquare (const int length, const int width, const string colour, const string fillableColour);                // Constructor

    void draw();                                // Drawing the Square
    void fill();                            // Filling the Square
    virtual ~ FilledSquare();                           // Destructor
};


// For the Circle shape
class FilledCircle : public Circle, public Fillable {
public:
    FilledCircle (const int length, const int width, const string colour, const string fillableColour);                // Constructor

    void draw();                            // Drawing the circle
    void fill();                            // Filling the Circle
    virtual ~ FilledCircle();                     // Destructor
};



// --------------- Classes Extending With Texts Inside The Filled Shape ---------------


// For the Square shape
class FilledTextSquare : public Square, public Fillable, public Text {
public:
    FilledTextSquare (const int length, const int width, const string colour, const string fillableColour, const string text);                // Constructor

    void draw();                                // Drawing the Square
    void drawText();                            // Drawing the Text
    virtual ~ FilledTextSquare();                     // Destructor
};


#endif //ASSIGNMENT_4_SHAPESGOOD_H
