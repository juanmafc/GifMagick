#include "InterpolationMode.h"

using namespace std;

InterpolationMode::InterpolationMode(Screen* screen, Gif* gif): RenderingMode(screen, gif) {
    this->currentFrame = 0;
}

InterpolationMode::~InterpolationMode()
{
    //dtor
}


void InterpolationMode::render() {
    this->screen->displayPicture( this->gif->getFrame( this->currentFrame ) );
}



void InterpolationMode::handleEvent(ALLEGRO_EVENT* event) {
    RenderingMode::handleEvent(event);

    if(event->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        if (clickedPoints.find(this->currentFrame) == clickedPoints.end()) {
            clickedPoints.insert( pair<int, Point>( this->currentFrame, Point(event->mouse.x, event->mouse.y) ) );
        }
        else {
            clickedPoints.at(this->currentFrame).setX(event->mouse.x);
            clickedPoints.at(this->currentFrame).setY(event->mouse.y);
        }
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
                //TODO: cambiarle el nombre
                this->interpolateGif();
                break;
        }
    }
}

void InterpolationMode::interpolateGif() {
    //Picture pic("rojo.bmp");
    Picture pic("mordekaiser.bmp");


    //TODO: esto se puede ir
    vector<Point> originalPoints;
    vector<Point> interpolatedPoints;
    int firstFrame = -1;
    int secondFrame = -1;
    for (map<int, Point>::iterator it = clickedPoints.begin(); it != clickedPoints.end(); ++it ) {
        originalPoints.push_back(it->second);
        //TODO: esto es horrible....
        if (firstFrame == -1 ) {
            firstFrame = it->first;
        }
        else if ( secondFrame == -1 ) {
            secondFrame= it->first;
        }
    }

    LinearInterpolation interpol;
    interpol.interpolate(originalPoints, (secondFrame - firstFrame) + 1, interpolatedPoints);

    for (int i = 0; i < interpolatedPoints.size(); i++ ) {
        Frame* currentFrame = gif->getFrame(firstFrame);
        currentFrame->drawPicture(&pic, interpolatedPoints[i].getX(), interpolatedPoints[i].getY() );
        firstFrame++;
    }

    gif->save("achieved.gif");
}

