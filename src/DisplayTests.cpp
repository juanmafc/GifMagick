#include "DisplayTests.h"

DisplayTests::DisplayTests() {
    //ctor
}

DisplayTests::~DisplayTests() {
    //dtor
}

void DisplayTests::displayASingleImage() {
    al_init();
    Picture picture("janna.png");
    //Picture picture("hue.bmp");
    //Picture picture("francella.gif[0]");
    Screen screen(picture.getColumns(), picture.getRows());
    screen.displayPicture(&picture);
}

void DisplayTests::displayTwoImages() {
    al_init();
    Picture f0("francella.gif[0]");
    Picture f1("francella.gif[1]");

    Screen screen(f0.getColumns(), f0.getRows());

    screen.displayPicture(&f0);
    cout<<"Se mostro la primera\n";
    screen.displayPicture(&f1);
}



void DisplayTests::displayATwoFramesGifOneTime() {
    al_init();
    Gif twoFramesGif("twoFrames.gif");
    //Gif twoFramesGif("buckleupTeddy.gif");
    //TODO: ver las columnas y rows del gif son las mismas del primer frame o si necesita algo mas
    Screen screen(twoFramesGif.getColumns(), twoFramesGif.getRows());



    screen.displayPicture(twoFramesGif.getFrame(0));
    screen.displayPicture(twoFramesGif.getFrame(1));
}


