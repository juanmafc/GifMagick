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

        int getFramesCount();
        Picture* getFrame(int frameNumber);

        double getTotalDuration();

    protected:

    private:
        vector<Picture*> frames;
        double totalDuration = 0;
};

#endif // GIF_H
