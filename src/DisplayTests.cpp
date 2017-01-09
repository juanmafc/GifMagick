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
    //Gif twoFramesGif("francella.gif");
    //TODO: ver las columnas y rows del gif son las mismas del primer frame o si necesita algo mas
    Screen screen(twoFramesGif.getColumns(), twoFramesGif.getRows());



    screen.displayPicture(twoFramesGif.getFrame(0));
    screen.displayPicture(twoFramesGif.getFrame(1));
}













Picture* getFrameEnBaseELTIempo(Gif* gif, double seconds) {
    int n = gif->getFramesCount();
    seconds = fmod(seconds, gif->getTotalDuration());/// 100.0);
    double d = 0;
    int i;
    for (i = 0; i < n; i++) {
        d += gif->getFrame(i)->getDuration();/// 100.0;
        if (seconds < d)
            return gif->getFrame(i);
    }
    return gif->getFrame(0);
}







void gif_render() {
    //al_draw_bitmap(algif_get_bitmap(game->skeleton[game->dir], al_get_time()), game->player_x, game->player_y, 0);
}









void DisplayTests::displayATwoFramesLoopedGif() {
    al_init();
    //Gif twoFramesGif("twoFrames.gif");
    Gif twoFramesGif("buckleupTeddy.gif");
    //Gif twoFramesGif("disposeGOAL.gif");
    //Gif twoFramesGif("skeleton_left.gif");
    //Gif twoFramesGif("francella.gif[0-20]");
    Screen screen(twoFramesGif.getColumns(), twoFramesGif.getRows());

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    ALLEGRO_TIMER *timer = al_create_timer(1 / 60.0);

    //TODO: refactorizar esto, no me gusta tener que tener el metodo getDisplay:
    al_register_event_source(event_queue, al_get_display_event_source( screen.getDisplay() ));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    bool quit = false;
    bool redraw = true;
    al_start_timer(timer);
    while (!quit) {
        if (redraw) {
            screen.displayPicture( getFrameEnBaseELTIempo(&twoFramesGif, al_get_time()) );
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
}



