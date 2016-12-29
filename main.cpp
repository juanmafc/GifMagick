#include <stdio.h>
#include <allegro5/allegro.h>
#include "AllegroTutorials.h"
#include "Save_gif.h"
#include "algif5src/algif.h"


static ALGIF_ANIMATION *load(char const *name) {
    ALLEGRO_PATH *examples = al_create_path_for_directory("examples");
    ALLEGRO_PATH *path = al_create_path(name);
    ALGIF_ANIMATION *gif = algif_load_animation(al_path_cstr(path, '/'));
    if (!gif) {
        al_rebase_path(examples, path);
        gif = algif_load_animation(al_path_cstr(path, '/'));
    }
    al_destroy_path(examples);
    al_destroy_path(path);
    if (!gif) {
        printf("Could not load %s.\n", name);
        exit(1);
    }
    return gif;
}




int main(int argc, char **argv){
    //AlTutorialBasicDisplay();
    //AlTutorialMaxMinResolutionDisplay();
    //AlTutorialBasicEvents();
    //AlTutorialTimers();
    //AlTutorialBasicBitmap();
    //AlTutorialImageLoading();
    al_init();

    ALGIF_ANIMATION* spookyScary = load("disposeGOAL.gif");


    saveGif("disposeREACHED.gif", spookyScary);
}


