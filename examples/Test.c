#include "clsh.c" //include the library here for an example am including the source code (for simplicity)
#include <stdbool.h>

int main(int argc, char **argv) {
    clsh my_obj; //create clsh object
    initclsh(&my_obj); //Initialize
    char *commands[256], *files[256], *spe[256], *unknown[256];
    CLShandler(&my_obj, commands, files, spe, unknown, argc, argv);
    //To Handle Special statements
    for(int i = 0; i < getspelen(&my_obj); i++) {
        //Assume the user types ./a.out --help in the terminal to detect command '--help' (special statement) 
        if(strcmp(spe[i], "--help") == 0) { //string.h already included in clsh.c
            //display_help(); 
        } else if(strcmp(spe[i], "--options") == 0) {
            //display_options
        }
    }
    //To Handle Commands or flags you can say
    bool o2 = 0, flto = 0; // True = 1
                           // False = 0
    for(int i = 0; i < getcmdlen(&my_obj); i++) {
        //Assume the user types ./a.out -O2 -flto in the terminal to detect command
        if(strcmp(commands[i], "-O2") == 0) {
            o2 = 1;
        } else if(strcmp(commands[i], "-flto") == 0) {
           flto = 1;
        }
    }

}
