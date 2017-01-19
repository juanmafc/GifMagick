#include "RenderingModes/LoopedMode.h"

LoopedMode::LoopedMode(Screen* screen, Gif* gif): RenderingMode(screen, gif) {
    //ctor
}

LoopedMode::~LoopedMode()
{
    //dtor
}

void LoopedMode::render() {
    this->screen->displayPicture( this->gif->getFrameForAGivenTime( al_get_time() ) );
}

void LoopedMode::handleEvent(ALLEGRO_EVENT* event) {
    RenderingMode::handleEvent(event);

    if (event->type == ALLEGRO_EVENT_TIMER) {
        this->redraw = true;
    }
}

