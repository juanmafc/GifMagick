#include "RenderingModesManager.h"

RenderingModesManager::RenderingModesManager(Screen* screen, Gif* gif) {
    this->loopedMode = new LoopedMode(screen, gif);
    this->interpolMode = new InterpolationMode(screen, gif);

    this->currentMode = loopedMode;
}

RenderingModesManager::~RenderingModesManager() {
    delete this->loopedMode;
    delete this->interpolMode;
}


RenderingMode* RenderingModesManager::getCurrentMode() {
    return this->currentMode;
}

RenderingMode* RenderingModesManager::getCurrentMode(ALLEGRO_EVENT* event) {
    if (event->type == ALLEGRO_EVENT_KEY_DOWN ) {
        switch(event->keyboard.keycode) {
            case ALLEGRO_KEY_SPACE:
                this->setNextMode();
                this->currentMode->render();
                break;
        }
    }
    return this->currentMode;
}


void RenderingModesManager::setNextMode() {
    if (this->currentMode == this->loopedMode ) {
        this->currentMode = this->interpolMode;
    }
    else {
        this->currentMode = this->loopedMode;
    }
}
