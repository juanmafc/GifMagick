#include "RenderingMode.h"

RenderingMode::RenderingMode(Screen* screen, Gif* gif) {
    this->closed = false;
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
        this->closed = true;
    }
}

bool RenderingMode::isClosed() {
    return this->closed;
}

bool RenderingMode::needsRendering() {
    return this->redraw;
}

