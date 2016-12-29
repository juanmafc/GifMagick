#ifndef SAVE_GIF_H_INCLUDED
#define SAVE_GIF_H_INCLUDED

#include "allegro5/allegro.h"
#include "algif5src/algif.h"
#include <iostream>

using namespace std;


static void
write_palette (ALLEGRO_FILE *file, ALGIF_PALETTE *palette, int bits)
{
    int i;
    for (i = 0; i < (1 << bits); i++)
    {
        al_fputc(file, palette->colors[i].r);
        al_fputc(file, palette->colors[i].g);
        al_fputc(file, palette->colors[i].b);
    }
}



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


    /* 7 global palette
    * 456 color richness
    * 3 sorted
    * 012 palette bits
    */
    cout<<"Palette colors_count: "<<gif->palette.colors_count<<"\n";
    //TODO: CHECK THIS
    for (i = 1, j = 0; i < gif->palette.colors_count; i *= 2, j++){
        al_fputc(file, (j ? 128 : 0) + 64 + 32 + 16 + (j ? j - 1 : 0));
    }
    al_fputc(file, gif->background_index);
    al_fputc(file, 0);        /* No aspect ratio. */
    ////////////////////////////////////////


    if (j) {
        //WORKING
        write_palette (file, &gif->palette, j);
    }




    al_fclose(file);
    cout<<"Hello World";
}




#endif // SAVE_GIF_H_INCLUDED
