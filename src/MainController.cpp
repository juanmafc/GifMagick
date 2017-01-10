#include "MainController.h"

MainController::MainController() {
    al_init();
}

MainController::~MainController() {
    //dtor
}


void MainController::startMainLoop(string gifPath) {

    Gif twoFramesGif(gifPath);
    Screen screen(twoFramesGif.getColumns(), twoFramesGif.getRows());
    Clock timer(1 / 60.0);

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    screen.registerIn( event_queue );
    timer.registerIn( event_queue );


    bool quit = false;
    bool redraw = true;

    timer.start();

    while (!quit) {
        if (redraw) {
            screen.displayPicture( this->getFrameForAGivenTime(&twoFramesGif, al_get_time()) );
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




//TODO: Esto moverlo a gif
Picture* MainController::getFrameForAGivenTime(Gif* gif, double seconds) {
    int n = gif->getFramesCount();
    seconds = fmod(seconds, gif->getTotalDuration());/// 100.0);
    double d = 0;
    int i;
    //TODO: esto se podria optimizar pero no creo que aora valga la pena
    for (i = 0; i < n; i++) {
        d += gif->getFrame(i)->getDuration();/// 100.0;
        if (seconds < d)
            return gif->getFrame(i);
    }
    return gif->getFrame(0);
}
