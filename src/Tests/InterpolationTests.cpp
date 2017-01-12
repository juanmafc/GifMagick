#include "Tests/InterpolationTests.h"

using namespace std;

InterpolationTests::InterpolationTests()
{
    //ctor
}

InterpolationTests::~InterpolationTests()
{
    //dtor
}

void InterpolationTests::getMouseCoordinatesOnClick() {
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;

    al_init();
    if(!al_install_mouse()) {
        fprintf(stderr, "failed to initialize the mouse!\n");
        return;
    }
    display = al_create_display(800, 400);

    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    while(1)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            cout<<"X:"<<ev.mouse.x<<"  Y:"<<ev.mouse.y<<"\n";
        }
    }
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
}




void InterpolationTests::linearInterpolationTest() {
    InterpolationMethod* interpol = new LinearInterpolation();
    vector<Point> originalPoints, interpolatedPoints;

    originalPoints.push_back(Point(1,10));
    originalPoints.push_back(Point(10,1));


    int interpolatedPointsCount = 10;
    interpol->interpolate(originalPoints, interpolatedPointsCount, interpolatedPoints);

    for (int i = 0; i < interpolatedPointsCount; i++) {
        cout<<"Xinter:"<<interpolatedPoints[i].getX()<<"  Yinter:"<<interpolatedPoints[i].getY()<<"\n";
    }
    cout<<"interpolatedPointsSize: "<<interpolatedPoints.size()<"\n";
    delete interpol;
}
