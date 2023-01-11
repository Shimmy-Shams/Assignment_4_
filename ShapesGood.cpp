//
//      Created by Shams Sajid on 2022-11-27.
//      Assignment 4: Structural Implementation
//      Course: CMPE 320
//


#include <iostream>
#include <string>
#include "ShapesGood.h"

using namespace std;


// -------- Accessor Methods ----------

int Shape :: getLength() const {
    return length;
}

int Shape :: getWidth() const{
    return width;
}

string Shape :: getColour() const {
    return colour;
}


// Destructor Methods
Shape :: ~ Shape() {}
Fillable :: ~ Fillable() {}
Text :: ~ Text () {}
Square :: ~ Square() {}
Circle :: ~ Circle() {}
Arc :: ~ Arc() {}
FilledSquare :: ~ FilledSquare() {}
FilledCircle :: ~ FilledCircle() {}
FilledTextSquare :: ~ FilledTextSquare() {}


// ---------------- Constructors ------------------

// For Shapes
Shape :: Shape(const int length, const int width, const string colour) : length(length), width(width), colour(colour) { }

// Copy Constructor
Shape :: Shape (const Shape& shape){
    this -> length = shape.getLength();
    this -> width = shape.getWidth();
    this -> colour = shape.getColour();
}


// For Fillable Shapes
Fillable :: Fillable (const string colour) {
    this -> fillableColour = colour;
}

// Accessor method for the fillable class
string Fillable :: getFillableColour() const {
    return fillableColour;
}

// Drawing the Fill colour
void Fillable :: fill() {
    cout << "With " << getFillableColour() << " fill.";
}



// For Texts
Text :: Text (const string text) {
    this -> text = text;
}

// Accessor
string Text :: getText() const {
    return text;
}

// Displaying the Text
void Text :: drawText() {
    cout << " Containing the Text: \"" << getText() << "\".";
}


// Constructor for the Square Shape
Square :: Square (const int length, const int width, const string colour) : Shape (length, width, colour) { }
//Drawing the square
void Square :: drawOutline () const {
    cout << "\n Drawing a " + getColour () + " square.";
}
void Square :: draw() {
    drawOutline();
}


// Constructor for the Circle Shape
Circle :: Circle (const int length, const int width, const string colour) : Shape (length, width, colour) { }
//Drawing the Circle
void Circle :: drawOutline() const {
    cout << "\n Drawing a " + getColour () + " circle.";
}
void Circle :: draw() {
    drawOutline();
}


// Constructor for the Arc Shape
Arc :: Arc (const int length, const int width, const string colour) : Shape (length, width, colour) { }
//Drawing the Arc
void Arc :: draw() {
    cout << "\n Drawing an " + getColour () + " arc.";
}


// Constructor for Filling the Square Shape
FilledSquare :: FilledSquare (const int length, const int width, const string colour,
                                  const string fillableColour) : Square (length, width, colour), Fillable(fillableColour) { }
// Method to fill the square
void FilledSquare :: fill() {
    cout << " With " + getFillableColour() + " fill.";
}

// Calling other methods to reduce the code
void FilledSquare :: draw() {
    drawOutline();
    fill();
}


// Constructor for Filling the Circle Shape
FilledCircle :: FilledCircle (const int length, const int width, const string colour,
                                  const string fillableColour) : Circle (length, width, colour), Fillable(fillableColour) { }
// Method to fill the Circle
void FilledCircle :: fill() {
    cout << " With " + getFillableColour() + " fill.";
}

// Calling other methods to reduce the code
void FilledCircle :: draw() {
    drawOutline();
    fill();
}


// Constructor for the Filled Text Square
// Constructor for Filling the Square Shape
FilledTextSquare :: FilledTextSquare (const int length, const int width, const string colour,
                                          const string fillableColour, const string text) : Square (length, width, colour), Fillable(fillableColour), Text (text) { }
// Method to write text in the square
void FilledTextSquare :: drawText() {
    cout << " Containing the text \"" << getText() << "\". ";
}

// Calling other methods to reduce the code
void FilledTextSquare :: draw() {
    drawOutline();
    drawText();
    fill();
}

