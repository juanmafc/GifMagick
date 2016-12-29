#ifndef SAVE_GIF_H_INCLUDED
#define SAVE_GIF_H_INCLUDED

#include "allegro5/allegro.h"
#include "algif5src/algif.h"
#include <iostream>

using namespace std;

void saveGif(const char* filename, ALGIF_ANIMATION* gif) {
    int frame;
    int i, j;

    ALLEGRO_FILE* file = al_fopen(filename, "w");

    if (!file) {
        return;
    }

    al_fwrite(file, "GIF89a", 6);
    al_fwrite16le(file, gif->width);
    al_fwrite16le(file, gif->height);



    al_fclose(file);
    cout<<"Hello World";
}




#endif // SAVE_GIF_H_INCLUDED
