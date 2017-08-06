#include "RenderingModes/InterpolationMode.h"

using namespace std;

InterpolationMode::InterpolationMode(Screen* screen, Gif* gif): RenderingMode(screen, gif) {
    this->currentFrame = 0;
    this->currentMouseX = 0;
    this->currentMouseY = 0;

    this->pic = new Picture("rojo.bmp");
}

InterpolationMode::~InterpolationMode()
{
    //dtor
}


void InterpolationMode::render() {
    this->screen->displayPicture( this->gif->getFrame( this->currentFrame ) );
    this->screen->displayPicture( this->pic, this->currentMouseX, this->currentMouseY );
}



void InterpolationMode::handleEvent(ALLEGRO_EVENT* event) {
    RenderingMode::handleEvent(event);

    if(event->type == ALLEGRO_EVENT_MOUSE_AXES) {
        this->currentMouseX = event->mouse.x;
        this->currentMouseY = event->mouse.y;
    }
    else if(event->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        this->registerMouseClick(event->mouse.x, event->mouse.y);
    }
    else if (event->type == ALLEGRO_EVENT_KEY_DOWN ) {
        //TODO: refactorizar con una clase "Keyboard" maybe...., un chainner para esto? teclaHandler
        switch(event->keyboard.keycode) {
            case ALLEGRO_KEY_LEFT:
                if (this->currentFrame > 0) {
                    this->currentFrame--;
                    this->redraw = true;
                }
                break;
            case ALLEGRO_KEY_RIGHT:
                if (this->currentFrame < this->gif->getFramesCount() - 1) {
                    this->currentFrame++;
                    this->redraw = true;
                }
                break;
            case ALLEGRO_KEY_F:
                this->interpolateGif();
                break;
        }
    }
}

void InterpolationMode::interpolateGif() {
    Picture pic("rojo.bmp");
    //Picture pic("mordekaiser.bmp");


    map<int, Point> interpolatedPoints;
    LinearInterpolation interpol;
    interpol.interpolate(this->clickedPoints, interpolatedPoints);


    for (map<int, Point>::iterator it = interpolatedPoints.begin(); it != interpolatedPoints.end() ; ++it ) {
        Frame* currentFrame = gif->getFrame(it->first);
        currentFrame->drawPicture(&pic, it->second.getX(), it->second.getY() );
    }

    gif->save("achieved.gif");
}







void InterpolationMode::registerMouseClick(int x, int y) {
    if (this->clickedPoints.find(this->currentFrame) == this->clickedPoints.end()) {
        this->clickedPoints.insert( pair<int, Point>( this->currentFrame, Point(x, y) ) );
    }
    else {
        this->clickedPoints.at(this->currentFrame).setX(x);
        this->clickedPoints.at(this->currentFrame).setY(y);
    }

    cout<<"Mouse X:"<<x<<"   Y:"<<y<<"   Frame:"<<currentFrame<<"\n";
}

