#ifndef GIF_H
#define GIF_H

#include "Magick++.h"
#include "Picture.h"
#include <vector>

using namespace std;

class Gif
{
    public:
        Gif(string gifPath);
        virtual ~Gif();


        int getColumns();
        int getRows();

        Picture* getFrame(int frameNumber);

    protected:

    private:
        vector<Picture*> frames;
};

#endif // GIF_H
