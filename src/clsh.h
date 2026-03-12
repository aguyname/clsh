//-----------------------------------------clsh header file-----------------------------------------------------
//Def: Command line statement handler is a tool used to handle commands/flags i.e which start with '-' notation 
//->files (whenever files have . extention)
//->special statements like '--help' 
//->if the command argument's doesn't support the above conditions then it's appended to unknown statements 
//[Imp Note]: The Usage of this library is written in README.md  
//Written by: a idiot T.Vikram (don't be like this guy)                                                              
//Date:12/06/2026

 
#ifndef CLSH_H
#define CLSH_H

//core clsh structure
typedef struct clsh {
        //limits
        size_t commands_lim;
        size_t files_lim;
        size_t specials_lim;
        size_t unknown_lim;
        
        //lengths
        size_t command_len;
        size_t files_len;
        size_t special_len;
        size_t unknown_len;
        
} clsh;
//Initialize with default values i.e command limit, file limit, special_statements limit, unknown limit all = 256

void initclsh(clsh *obj);

//CLSH Core function.
void CLShandler(clsh *obj, char **commands, char **files, char **special_statements, char **unknown, int argc, char *argv[]);

//Subfunctions: 

//Subfuncs1: 
void setcmdlim(clsh *obj, size_t lim); //set the limit of maximum no of commands. Usage: setcmdlim(&my_obj, 1024);

void setfileslim(clsh *obj, size_t lim); //set the limit of maximum no of files. Usage: setfileslim(&my_obj, 1024);

void setpeciallim(clsh *obj, size_t lim); //set the limit of maximum no of special statements. Usage: setspeciallim(&my_obj, 1024);

void setunlim(clsh *obj, size_t lim); //set the limit of maximum no of unknown statements. Usage: setunlim(&my_obj, 1024);

//Subfuncs2:
size_t getcmdlen(const clsh *obj); //get the no of command statements. Usage: int cmmd_count =  getcmdlen(&my_obj);

size_t getfileslen(const clsh *obj); //get the no of files. Usage: int files_count = getfileslen(&my_obj);

size_t getspelen(const clsh *obj); //get the no of command statements. Usage: int special_count = getspelen(&my_obj);

size_t getunklen(const clsh *obj); //get the no of command statements. Usage: int unknown_count = getunklen(&my_obj);

#endif
