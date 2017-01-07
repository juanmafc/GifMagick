#include "DisplayTests.h"

DisplayTests::DisplayTests() {
    //ctor
}

DisplayTests::~DisplayTests() {
    //dtor
}

void DisplayTests::displayASingleImage() {
    Picture picture("janna.png");
    //Picture picture("hue.bmp");
    //Picture picture("francella.gif[0]");
    Screen screen(picture.getColumns(), picture.getRows());
    screen.displayPicture(picture);
}

void DisplayTests::displayTwoImages() {
    Picture f0("francella.gif[0]");
    Picture f1("francella.gif[1]");

    Screen screen(f0.getColumns(), f0.getRows());

    screen.displayPicture(f0);
    cout<<"Se mostro la primera\n";
    screen.displayPicture(f1);
}
