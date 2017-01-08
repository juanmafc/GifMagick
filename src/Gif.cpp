#include "Gif.h"

using namespace std;

Gif::Gif(string gifPath) {
    //TODO: tal vez sea mas rapido levantarlo con pingImages
    //Tambien puede ser que sea mas rapido levantar una por una, no se
    /*  Problema: no se si esto va a tomar mas tiempo, lo de crear dos veces la misma imagen
        Una opcion:
        guardar este vector como atributo privado y por otro lado guardar el vector con Pictures
    */
    list<Magick::Image> magickFrames;
    Magick::readImages(&magickFrames, gifPath);
    for (list<Magick::Image>::iterator it = magickFrames.begin(); it != magickFrames.end(); ++it) {
        //Magick::Image* currentFrame = &(*it);
        //this->frames.push_back( new Picture(currentFrame)) ;
        this->frames.push_back( new Picture(new Magick::Image(*it))) ;
    }
}

Gif::~Gif() {
    for (vector<Picture*>::iterator it = this->frames.begin(); it != this->frames.end(); ++it) {
        delete (*it);
    }
}


int Gif::getColumns() {
    return (this->frames[0])->getColumns();

}

int Gif::getRows() {
    return (this->frames[0])->getRows();
}



Picture* Gif::getFrame(int frameNumber) {
    return (this->frames[frameNumber]);
}


