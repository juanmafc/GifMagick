#ifndef EVENTSOURCE_H
#define EVENTSOURCE_H

#include "allegro5/allegro.h"


class EventSource
{
    public:
        virtual void  registerIn(ALLEGRO_EVENT_QUEUE* event_queue) = 0;

    protected:

    private:
};

#endif // EVENTSOURCE_H
