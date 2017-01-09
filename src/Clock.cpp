#include "Clock.h"

Clock::Clock(double time) {
    this->timer = al_create_timer(1 / 60.0);
}

Clock::~Clock() {
    //dtor
    al_destroy_timer(this->timer);
}

void Clock::registerIn(ALLEGRO_EVENT_QUEUE* event_queue) {
    al_register_event_source(event_queue, al_get_timer_event_source(this->timer));
}
void Clock::start(){
    al_start_timer(this->timer);
}


