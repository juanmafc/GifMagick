#ifndef SAVE_GIF_H_INCLUDED
#define SAVE_GIF_H_INCLUDED

#include "allegro5/allegro.h"
#include "algif5src/algif.h"
#include <iostream>
#include <fstream>

using namespace std;


static void write_palette (ALLEGRO_FILE *file, ALGIF_PALETTE *palette, int bits)
{
    int i;
    for (i = 0; i < (1 << bits); i++)
    {
        al_fputc(file, palette->colors[i].r);
        al_fputc(file, palette->colors[i].g);
        al_fputc(file, palette->colors[i].b);
    }
}




static unsigned int colorToInt(ALLEGRO_COLOR color) {
    unsigned char* colorComponents = new unsigned char[4];

    al_unmap_rgb(color, &colorComponents[0], &colorComponents[1], &colorComponents[2]);
    return (colorComponents[0] << 24) + (colorComponents[1] << 16) + (colorComponents[2] << 8) + colorComponents[3];
}


//static int get_minimum_bitsize (ALGIF_BITMAP *bmp) {
static int get_minimum_bitsize (ALLEGRO_BITMAP *bmp) {
    int x, y, max = 0, b = 2;
    int w, h;

    w = al_get_bitmap_width(bmp);
    h = al_get_bitmap_height(bmp);

    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            ALLEGRO_COLOR pixel = al_get_pixel(bmp, x, y);
            unsigned int c = colorToInt(pixel);
            //int c = getpixel (bmp, x, y);
            //cout<<"Color como numero "<<c<<"\n";
            if (c > max)
                max = c;
        }
    }

    while ((1 << b) <= max)
    {
        b++;
    }

    return b;
}





static void write_code(ALLEGRO_FILE* file, char *buf, int *bit_pos, int bit_size, int code) {

    int i;
    int pos = 1;

    for (i = 0; i < bit_size; i++)
    {
        int byte_pos = *bit_pos >> 3;

        if (code & pos)
            buf[byte_pos] |= (1 << (*bit_pos & 7));
        else
            buf[byte_pos] &= ~(1 << (*bit_pos & 7));
        (*bit_pos)++;
        if (*bit_pos == 2040)
        {
            al_fputc(file, byte_pos + 1);
            al_fwrite(file, buf, byte_pos + 1);
            *bit_pos = 0;
        }
        pos += pos;
    }
}






//void LZW_encode (ALLEGRO_FILE* file, ALGIF_BITMAP* bmp) {
void LZW_encode (ALLEGRO_FILE* file, ALLEGRO_BITMAP* bmp) {

    int orig_bit_size;
    int bit_size;
    char buf[256];
    int bit_pos;
    int clear_marker;
    int end_marker;
    struct
    {
        int prefix;
        int c;
        int len;
    }
    codes[4096];                /* Maximum bit size is 12. */

    int code, prev;
    int in_pos;
    int n, i;

    orig_bit_size = get_minimum_bitsize (bmp);

    n = 2 + (1 << orig_bit_size);

    for (i = 0; i < n; i++)
    {
        codes[i].c = i;
        codes[i].len = 0;
    }

    clear_marker = n - 2;
    end_marker = n - 1;

    al_fputc(file, orig_bit_size);

    bit_size = orig_bit_size + 1;

    bit_pos = 0;

    /* Play fair and put a clear marker at the start. */
//    write_code (file, buf, &bit_pos, bit_size, clear_marker);
//
//    prev = read_pixel (bmp, 0);
//
//    for (in_pos = 1; in_pos < bmp->w * bmp->h; in_pos++)
//    {
//        code = read_pixel (bmp, in_pos);
//
//        if (prev != clear_marker)
//        {
//            /* Search for the code. */
//            for (i = end_marker + 1; i < n; i++)
//            {
//                if (codes[i].prefix == prev && codes[i].c == code)
//                {
//                    code = i;
//                    break;
//                }
//            }
//
//            /* If not found, add it, and write previous code. */
//            if (i == n)
//            {
//                codes[n].prefix = prev;
//                codes[n].len = codes[prev].len + 1;
//                codes[n].c = code;
//                n++;
//
//                write_code (file, buf, &bit_pos, bit_size, prev);
//            }
//        }
//
//        /* Out of bits? Increase. */
//        if (n == 1 + (1 << bit_size))
//        {
//            if (bit_size < 12)
//                bit_size++;
//        }
//
//        /* Too big table? Clear and start over. */
//        if (n == 4096)
//        {
//            write_code (file, buf, &bit_pos, bit_size, clear_marker);
//            bit_size = orig_bit_size + 1;
//            n = end_marker + 1;
//        }
//
//        prev = code;
//    }
//    write_code (file, buf, &bit_pos, bit_size, prev);
//    write_code (file, buf, &bit_pos, bit_size, end_marker);
//    if (bit_pos)
//    {
//        int byte_pos = (bit_pos + 7) / 8;
//
//        pack_putc (byte_pos, file);
//        pack_fwrite (buf, byte_pos, file);
//    }
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


        int x, y, max = 0, b = 2;
        ALGIF_BITMAP* bmp = gif->frames[frame].bitmap_8_bit;

        //LZW_encode(file, gif->frames[frame].bitmap_8_bit);
        LZW_encode(file, gif->frames[frame].rendered);
    }


    al_fclose(file);
    cout<<"Hello World";
}




#endif // SAVE_GIF_H_INCLUDED
