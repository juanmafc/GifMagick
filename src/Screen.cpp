#include "Screen.h"

Screen::Screen(int columns, int rows){

    this->display = NULL;

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
    //this->display = al_create_display(800,600);
    this->display = al_create_display(columns, rows);
    this->columns = columns;
    this->rows = rows;

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




void Screen::displayPicture(Picture* picture, int x, int y){
    this->copyPixelsToScreenBuffer(picture, x, y);
    this->updateScreen();
    //al_rest(2);
}


void Screen::copyPixelsToScreenBuffer(Picture* picture, int x, int y) {
    /*
    ALLEGRO_BITMAP* displayedBitmap = al_get_backbuffer(this->display);

    //TODO: TAL VEZ HAYA QUE SETEAR A MANO EL TARGET
    for (int row = 0; row < this->rows; row++){
        for (int column = 0; column < this->columns; column++){
            float red = picture->getRedAt(row, column);
            float green = picture->getGreenAt(row, column);
            float blue = picture->getBlueAt(row, column);
            al_put_pixel(column, row, al_map_rgb_f(red, green, blue));
        }
    }
    */
    ALLEGRO_BITMAP* displayedBitmap = picture->getRenderedImage();
    al_set_target_backbuffer(this->display);
    al_draw_bitmap(displayedBitmap, x, y, 0);
}

void Screen::updateScreen() {
    al_flip_display();
}


void Screen::registerIn(ALLEGRO_EVENT_QUEUE* event_queue) {
    al_register_event_source(event_queue, al_get_display_event_source( this->display ));
}









