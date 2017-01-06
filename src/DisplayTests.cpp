#include "DisplayTests.h"

DisplayTests::DisplayTests() {
    //ctor
}

DisplayTests::~DisplayTests() {
    //dtor
}

void DisplayTests::displayASingleImage() {
    //Picture picture("janna.png");
    //Picture picture("hue.bmp");
    Picture picture("francella.gif[0]");
    Screen screen(picture.getColumns(), picture.getRows());
    screen.displayPicture(picture);
}
