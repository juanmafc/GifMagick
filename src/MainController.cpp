#include "MainController.h"

using namespace std;

MainController::MainController() {
    al_init();
    al_install_keyboard();
    al_install_mouse();
}

MainController::~MainController() {
    //dtor
}


void MainController::startMainLoop(string gifPath) {

    Gif gif(gifPath);
    Screen screen(gif.getColumns(), gif.getRows());
    Clock timer(1 / 60.0);

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    screen.registerIn( event_queue );
    timer.registerIn( event_queue );

    //TODO: refactorizar keyboard y mouse???
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());


    bool quit = false;
    bool redraw = true;

    //TODO: MAYBE se podria usar un State
    bool loopMode = true;
    int currentFrame = 0;

    timer.start();

    map<int, Point> clickedPoints;

    LoopedMode loop(&screen, &gif);
    //InterpolationMode loop(&screen, &gif);

    while ( !loop.isClosed() ) {
        //TODO: esto de redraw podria moverse a cada estado, el tema es que no se como funcionaria con varios eventos tho....
        //Esto es mejor, porque, por ejemplo, el InterpolatedMode no se dibujaria hasta que se apriete RIGHT por primera vez
        if ( loop.needsRendering() ) {
            loop.render();
        }
        while (!al_is_event_queue_empty(event_queue)) {
            ALLEGRO_EVENT event;
            al_wait_for_event(event_queue, &event);
            loop.handleEvent(&event);
        }
    }
    al_destroy_event_queue(event_queue);
}
