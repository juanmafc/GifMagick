#include "Gif.h"

using namespace std;

Gif::Gif(string gifPath) {
    this->totalDuration = 0;
    //TODO: tal vez sea mas rapido levantarlo con pingImages
    //Tambien puede ser que sea mas rapido levantar una por una, no se
    /*  Problema: no se si esto va a tomar mas tiempo, lo de crear dos veces la misma imagen
        Una opcion:
        guardar este vector como atributo privado y por otro lado guardar el vector con Pictures
    */
    list<Magick::Image> magickFrames;
    Magick::readImages(&magickFrames, gifPath);
    Magick::coalesceImages(&magickFrames, magickFrames.begin(), magickFrames.end());
    int i = 1;
    int cantidad = magickFrames.size();
    for (list<Magick::Image>::iterator it = magickFrames.begin(); it != magickFrames.end(); ++it) {
        //Magick::Image* currentFrame = &(*it);
        //this->frames.push_back( new Picture(currentFrame)) ;
        cout<<"Cargando el frame "<<i<<" de "<<cantidad<<"\n";
        Frame* frame = new Frame(new Magick::Image(*it));
        this->frames.push_back(  frame ) ;
        this->totalDuration += frame->getDuration();
        i++;
    }
}

Gif::~Gif() {
    for (vector<Frame*>::iterator it = this->frames.begin(); it != this->frames.end(); ++it) {
        delete (*it);
    }
}


int Gif::getColumns() {
    return (this->frames[0])->getColumns();

}

int Gif::getRows() {
    return (this->frames[0])->getRows();
}



Frame* Gif::getFrame(int frameNumber) {
    return (this->frames[frameNumber]);
}


Frame* Gif::getFrameForAGivenTime(double seconds) {
    int n = this->getFramesCount();
    seconds = fmod(seconds, this->getTotalDuration());/// 100.0);
    double d = 0;
    int i;
    //TODO: esto se podria optimizar pero no creo que aora valga la pena
    for (i = 0; i < n; i++) {
        d += this->getFrame(i)->getDuration();/// 100.0;
        if (seconds < d)
            return this->getFrame(i);
    }
    return this->getFrame(0);
}










int Gif::getFramesCount() {
    return this->frames.size();

}

double Gif::getTotalDuration() {
    return this->totalDuration;
}




void Gif::save(string gifPath) {
    list<Magick::Image> magickFrames;
    for (vector<Frame*>::iterator it = this->frames.begin(); it != this->frames.end(); ++it) {
        (*it)->flushImage();
        magickFrames.push_back(  *((*it)->getImage())  );
    }
    Magick::writeImages(magickFrames.begin(), magickFrames.end(),gifPath);
}




