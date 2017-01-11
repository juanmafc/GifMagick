#include "MainController.h"

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

    while (!quit) {
        if (loopMode) {
            if (redraw) {
                //TODO: cambiar el "loopMode" a "pause" o algo asi...
                //TODO: cuando se unpausea debe volver al mismo frame: al_time - unpauseTime + pauseTime
                screen.displayPicture( gif.getFrameForAGivenTime( al_get_time() ) );
                redraw = false;
            }
        }
        else {
            screen.displayPicture( gif.getFrame(currentFrame));
        }

        while (!al_is_event_queue_empty(event_queue)) {
            ALLEGRO_EVENT event;
            al_wait_for_event(event_queue, &event);

            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                quit = true;
            }
            else if (event.type == ALLEGRO_EVENT_TIMER) {
                redraw = true;
            }
            else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                //TODO: esto debe hacerse SOLO si esta en el estado pausado... so ...State????
                cout<<"X:"<<event.mouse.x<<"  Y:"<<event.mouse.y<<"\n";
                //TODO: lista de cosas pra hacer con el mouse
                //Saco las coordenadas del 1er pto y el frame en que se clickea
                //saco las coordenadas del 2do pto y el frame en que se clickea
                //interpolo usando la interpolacion lineal, necesito (frame2 - frame1) + 1 puntos interpolados
                //Necesito dibujar la imagen a interpolar en los frames indicados
                //...Y ademas necesito poder setear la imagen a dibujar
            }
            else if (event.type == ALLEGRO_EVENT_KEY_DOWN ) {
                //TODO: refactorizar con una clase "Keyboard" maybe...., un chainner para esto? teclaHandler
                switch(event.keyboard.keycode) {
                    case ALLEGRO_KEY_SPACE:
                        loopMode = !loopMode;
                        break;
                    case ALLEGRO_KEY_LEFT:
                        if (currentFrame > 0) {
                            currentFrame--;
                        }
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        if (currentFrame < gif.getFramesCount() - 1) {
                            currentFrame++;
                        }
                        break;
                }
            }
        }
    }
    al_destroy_event_queue(event_queue);
}
