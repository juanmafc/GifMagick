#include "Frame.h"

Frame::Frame(Magick::Image* image) : Picture(image){
    //ctor
}


Frame::~Frame()
{
    //dtor
}


double Frame::getDuration() {
    return this->image->animationDelay()/100.0;
}
