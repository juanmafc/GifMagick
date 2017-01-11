#include "MainController.h"

MainController::MainController() {
    al_init();
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


    bool quit = false;
    bool redraw = true;

    timer.start();

    while (!quit) {
        if (redraw) {
            screen.displayPicture( gif.getFrameForAGivenTime( al_get_time() ) );
            redraw = false;
        }

        while (!al_is_event_queue_empty(event_queue)) {
            ALLEGRO_EVENT event;
            al_wait_for_event(event_queue, &event);

            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                quit = true;
            }

            if (event.type == ALLEGRO_EVENT_TIMER) {
                redraw = true;
            }
        }
    }
    al_destroy_event_queue(event_queue);
}
