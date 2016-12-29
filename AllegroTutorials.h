#ifndef ALLEGROTUTORIALS_H_INCLUDED
#define ALLEGROTUTORIALS_H_INCLUDED

#include <stdio.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_native_dialog.h"

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 100;//32;



int AlTutorialBasicDisplay(){

   ALLEGRO_DISPLAY *display = NULL;

   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

   display = al_create_display(640, 480);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      return -1;
   }

   al_clear_to_color(al_map_rgb(0,0,0));

   al_flip_display();

   al_rest(10.0);

   al_destroy_display(display);

   return 0;
}




int AlTutorialMaxMinResolutionDisplay(){

   ALLEGRO_DISPLAY       *display = NULL;
   ALLEGRO_DISPLAY_MODE   disp_data;

   al_init(); // I'm not checking the return value for simplicity.
   al_init_image_addon();
   al_init_primitives_addon();

   al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);

   al_set_new_display_flags(ALLEGRO_FULLSCREEN);
   display = al_create_display(disp_data.width, disp_data.height);

   al_clear_to_color(al_map_rgb(255,0,0));
   al_flip_display();

   al_rest(3);
   al_destroy_display(display);

   return 0;
}





int AlTutorialBasicEvents(){

   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;

   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

   display = al_create_display(640, 480);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      return -1;
   }

   event_queue = al_create_event_queue();
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_display(display);
      return -1;
   }

   al_register_event_source(event_queue, al_get_display_event_source(display));

   al_clear_to_color(al_map_rgb(0,0,0));

   al_flip_display();

   while(1)
   {
      ALLEGRO_EVENT ev;
      ALLEGRO_TIMEOUT timeout;
      al_init_timeout(&timeout, 0.06);

      bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);

      if(get_event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
      }

      al_clear_to_color(al_map_rgb(0,0,0));
      al_flip_display();
   }

   al_destroy_display(display);
   al_destroy_event_queue(event_queue);

   return 0;
}




int AlTutorialTimers(){

   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
   bool redraw = true;

   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

   timer = al_create_timer(1.0 / FPS);
   if(!timer) {
      fprintf(stderr, "failed to create timer!\n");
      return -1;
   }

   display = al_create_display(640, 480);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      al_destroy_timer(timer);
      return -1;
   }

   event_queue = al_create_event_queue();
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }

   al_register_event_source(event_queue, al_get_display_event_source(display));

   al_register_event_source(event_queue, al_get_timer_event_source(timer));

   al_clear_to_color(al_map_rgb(255,0,0));

   al_flip_display();

   al_start_timer(timer);

   int rojo = 255;
   int azul = 0;

   while(1)
   {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);

      if(ev.type == ALLEGRO_EVENT_TIMER) {
         redraw = true;
         rojo = 255 - rojo;
         azul = 255 - azul;
      }
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
      }

      if(redraw && al_is_event_queue_empty(event_queue)) {
         redraw = false;
         al_clear_to_color(al_map_rgb(rojo,0,azul));
         al_flip_display();
      }
   }

   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);

   return 0;
}










int AlTutorialBasicBitmap(){
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
   ALLEGRO_BITMAP *bouncer = NULL;
   float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
   float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
   float bouncer_dx = -4.0, bouncer_dy = 4.0;
   bool redraw = true;

   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

   timer = al_create_timer(1.0 / FPS);
   if(!timer) {
      fprintf(stderr, "failed to create timer!\n");
      return -1;
   }

   display = al_create_display(SCREEN_W, SCREEN_H);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      al_destroy_timer(timer);
      return -1;
   }

   bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
   if(!bouncer) {
      fprintf(stderr, "failed to create bouncer bitmap!\n");
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }


   ALLEGRO_BITMAP* innerMe = al_create_bitmap(50,50);
   al_set_target_bitmap(innerMe);
   al_clear_to_color(al_map_rgb(255, 0, 0));

   al_set_target_bitmap(bouncer);

   al_clear_to_color(al_map_rgb(255, 0, 255));
   al_draw_bitmap(innerMe, 0, 0, 0);





   al_set_target_bitmap(al_get_backbuffer(display));

   event_queue = al_create_event_queue();
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_bitmap(bouncer);
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }

   al_register_event_source(event_queue, al_get_display_event_source(display));

   al_register_event_source(event_queue, al_get_timer_event_source(timer));

   al_clear_to_color(al_map_rgb(0,0,0));

   al_flip_display();

   al_start_timer(timer);

   while(1)
   {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);

      if(ev.type == ALLEGRO_EVENT_TIMER) {
         if(bouncer_x < 0 || bouncer_x > SCREEN_W - BOUNCER_SIZE) {
            bouncer_dx = -bouncer_dx;
         }

         if(bouncer_y < 0 || bouncer_y > SCREEN_H - BOUNCER_SIZE) {
            bouncer_dy = -bouncer_dy;
         }

         bouncer_x += bouncer_dx;
         bouncer_y += bouncer_dy;

         redraw = true;
      }
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
      }

      if(redraw && al_is_event_queue_empty(event_queue)) {
         redraw = false;

         al_clear_to_color(al_map_rgb(0,0,0));

         al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);

         al_flip_display();
      }
   }

   al_destroy_bitmap(bouncer);
   al_destroy_bitmap(innerMe);
   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);

   return 0;
}




int AlTutorialImageLoading(){

   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_BITMAP  *image   = NULL;

   if(!al_init()) {
      al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 0;
   }

   if(!al_init_image_addon()) {
      al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 0;
   }

   display = al_create_display(800,600);

   if(!display) {
      al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 0;
   }

   image = al_load_bitmap("image.png");

   if(!image) {
      al_show_native_message_box(display, "Error", "Err555or", "Failed to load image!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      al_destroy_display(display);
      return 0;
   }

   al_draw_bitmap(image,0,0,0);

   al_flip_display();
   al_rest(2);

   al_destroy_display(display);
   al_destroy_bitmap(image);

   return 0;
}




#endif // ALLEGROTUTORIALS_H_INCLUDED
