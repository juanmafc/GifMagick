#include "DisplayTests.h"

DisplayTests::DisplayTests() {
    //ctor
}

DisplayTests::~DisplayTests() {
    //dtor
}

void DisplayTests::displayASingleImage() {
    Picture picture("hue.bmp");
    //Picture picture("janna.png");
    Screen screen;
    screen.displayPicture(picture);
}
