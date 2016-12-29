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

    for (i = 1, j = 0; i < gif->palette.colors_count; i *= 2, j++);
    al_fputc(file, (j ? 128 : 0) + 64 + 32 + 16 + (j ? j - 1 : 0));
    al_fputc(file, gif->background_index);
    al_fputc(file, 0);        /* No aspect ratio. */


    if (j)
        write_palette (file, &gif->palette, j);

    if (gif->loop != -1){ /* Loop count extension. */
        al_fputc(file, 0x21); /* Extension Introducer. */
        al_fputc(file, 0xff); /* Application Extension. */
        al_fputc(file, 11);    /* Size. */
        al_fwrite(file, "NETSCAPE2.0", 11);
        al_fputc(file, 3); /* Size. */
        al_fputc(file, 1);
        al_fwrite16le(file, gif->loop);
        al_fputc(file, 0);
    }


    //for (frame = 0; frame < gif->frames_count; frame++) {
    for (frame = 0; frame < 1; frame++) {
        cout<<"Frame\n";
        int w = gif->frames[frame].bitmap_8_bit->w;
        int h = gif->frames[frame].bitmap_8_bit->h;

        al_fputc(file, 0x21); /* Extension Introducer. */
        al_fputc(file, 0xf9); /* Graphic Control Extension. */
        al_fputc(file, 4);    /* Size. */

        /* Disposal method, and enable transparency. */
        i = gif->frames[frame].disposal_method << 2;
        if (gif->frames[frame].transparent_index != -1)
            i |= 1;
        al_fputc(file, i);
        al_fwrite16le(file, gif->frames[frame].duration); /* In 1/100th seconds. */

        if (gif->frames[frame].transparent_index != -1)
            al_fputc(file, gif->frames[frame].transparent_index);       /* Transparent color index. */
        else
             al_fputc(file, 0);
        al_fputc(file, 0x00); /* Terminator. */

        al_fputc(file, 0x2c); /* Image Descriptor. */
        al_fwrite16le(file, gif->frames[frame].xoff);
        al_fwrite16le(file, gif->frames[frame].yoff);
        al_fwrite16le(file, w);
        al_fwrite16le(file, h);

         /* 7: local palette
         * 6: interlaced
         * 5: sorted
         * 012: palette bits
         */

         for (i = 1, j = 0; i < gif->frames[frame].palette.colors_count; i *= 2, j++);
         al_fputc(file, (j ? 128 : 0) + (j ? j - 1 : 0));

         if (j)
            write_palette (file, &gif->frames[frame].palette, j);
    }


    al_fclose(file);
    cout<<"Hello World";
}




#endif // SAVE_GIF_H_INCLUDED
