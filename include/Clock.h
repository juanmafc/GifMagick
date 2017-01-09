#ifndef CLOCK_H
#define CLOCK_H

#include <EventSource.h>

class Clock : public EventSource
{
    public:
        Clock(double time);
        virtual ~Clock();

        void start();

        void registerIn(ALLEGRO_EVENT_QUEUE* event_queue);

    protected:

    private:
        ALLEGRO_TIMER* timer;
};


#endif // CLOCK_H
