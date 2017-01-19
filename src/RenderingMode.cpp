#include "RenderingMode.h"

RenderingMode::RenderingMode(Screen* screen, Gif* gif) {
    this->quit = false;
    this->redraw = true;

    this->screen = screen;
    this->gif = gif;
}

RenderingMode::~RenderingMode()
{
    //dtor
}


void RenderingMode::handleEvent(ALLEGRO_EVENT* event) {
    if (event->type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        this->quit = true;
    }
}

