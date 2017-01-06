#include "Screen.h"

Screen::Screen(){

    this->display = NULL;

    if(!al_init()) {
      al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return;
    }

//TODO: ESTO SIRVE Y/O ES NECESARIO?
//This registers bitmap format handlers for al_load_bitmap, al_load_bitmap_f, al_save_bitmap, al_save_bitmap_f.
//Por ahora me parece que no
/*
    ALLEGRO_BITMAP  *image   = NULL;
    if(!al_init_image_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return;
    }
    image = al_load_bitmap("image.png");
    if(!image) {
        al_show_native_message_box(display, "Error", "Err555or", "Failed to load image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return;
    }
*/
////////////////////////////////////////////////////
    this->display = al_create_display(800,600);

    if(!this->display ) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return;
    }
}



Screen::~Screen(){
    //dtor
    al_destroy_display(this->display);
    //al_destroy_bitmap(image);
}




void Screen::displayPicture(Picture& picture){

    this->copyPixelsToScreenBuffer(picture);
//    this->updateScreen();

    //al_draw_bitmap(image,0,0,0);
    al_flip_display();
    al_rest(20);
    return;
}


void Screen::copyPixelsToScreenBuffer(Picture& picture) {
    ALLEGRO_BITMAP* displayedBitmap = al_get_backbuffer(this->display);

    //TODO: TAL VEZ HAYA QUE SETEAR A MANO EL TARGET

    for (int row = 0; row < 300; row++){
        for (int column = 0; column < 400; column++){
            float red = picture.getRedAt(row, column);
            float green = picture.getGreenAt(row, column);
            float blue = picture.getBlueAt(row, column);

            al_put_pixel(column, row, al_map_rgb_f(red, green, blue));
        }
    }
}

