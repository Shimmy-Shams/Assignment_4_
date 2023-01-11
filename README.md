# Assignment_4_

For this assignment you are supplied with following files:

- ShapesBad.h
- ShapesBad.cpp
- TestBadShapes.cpp
- TestGoodShapes.cpp


The first two contain the structure of a shapes hierarchy that would supposedly be used with a drawing program. You don't need to draw anything in this assignment, but you do need to improve on the structure shown in the first file and implemented in the second. It is terrible! You can see just how bad it is when it comes time to iterate through a collection of Shape objects, as shown in the third file "TestBadShapes.cpp". Each object in the collection must be tested in a large, ugly conditional structure in order to determine what kind of object it actually is before drawing functions can be invoked. It is clear that polymorphism is not being properly used here!

Your job is to re-structure the hierarchy so that it can be used with the fourth program, TestGoodShapes.cpp, which leverages polymorphism to allow for a much simpler and more elegant drawing loop. The output from both testing programs will be the same. Read the comments in the files provided for some more information on what they contain. And, yes, the objects do not really contain all the data that would be needed to actually draw them, but that lack is not important for this assignment.

Here is a list of features that you must take into account when building your new, improved structure:

Use const wherever possible.

- No attribute can be declared more than once. 
- Possible attributes are length, width, border colour, fill colour (for objects that can be filled) and text (for objects that can contain a text label). 
- The colours and text attribute are all of type string.
- Attributes must be private. Constructors do not need to check for legal arguments.
- Instantiated objects cannot have attributes that are not initialized, nullptr, empty strings or zero.
- You can add accessors wherever you need them.
- The drawing of a shape involves three steps, carried out in this order: drawing the outline, possibly filling the outline (with a different colour), and then possibly adding a text label. All shapes can be drawn in outline, but only some shapes can be filled and only some shapes can hold a label. You will need to use multiple inheritance to enforce these design restrictions on the classes in your hierarchy. For example, only a shape that can be filled would extend a parent class perhaps called "Fillable". All Shapes can be drawn in outline and have a length, a width and an outline colour.
- While a Square object knows how to draw itself, an object of the base class type, Shape, does not. So, the functions used to actually outline, fill and place text for a specific concrete object must be defined in that particular object.
- Each class must have its own destructor, even though their implementations will be empty.
- Build your structure in a file called "ShapesGood.h". Implement your functions in "ShapesGood.cpp" so that running TestGoodShapes.cpp produces the same output as TestBadShapes.cpp produced. You cannot and do not need to alter the code in TestGoodShapes.cpp.
- Your hierarchy must be extensible. In other words you must be allowed to add more shape classes in the future without having to alter the existing hierarchy.
