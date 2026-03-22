//------------------------------------------clsh source file----------------------------------
//Written by: T.Vikram 
//Date: 12/06/2026
//Revised date: 22/06/2026
#include <stdio.h>
#include <string.h>
#include "clsh.h" 


void initclsh(clsh *obj) {
      if(!obj)
         return;
      obj->commands_lim = 256;
      obj->files_lim = 256;
      obj->specials_lim = 256;
      obj->unknown_lim = 256;
      obj->command_len = 1;
      obj->files_len = 1;
      obj->special_len = 1;
      obj->unknown_len = 1;
}

int findch(char *src, int ch, size_t src_size) { //helper
	if(!src || !src_size) 
		return -1;
	char *tmp = memchr(src, ch, src_size);
	if(!tmp) {
		return -1;
	}
	return (tmp-src);
}


void append(char **ptr, size_t *index, char *data, size_t limit) { //to make more readable for idiots like me only
     if(*index > limit) 
        return;
      if(!ptr || !data) return;
      
     ptr[*index] = data;
     (*index)++;
}


void CLShandler(clsh *obj, char **commands, char **files, char **special_statements, char **unknown, int argc, char *argv[]) {
           size_t i, len_cmd = 0, len_files = 0, len_special = 0, len_unknown = 0;
           for(i = 0; i < argc; i++) {
               if(argv[i][0] == '-' && argv[i][1] == '-') {  
                  append(special_statements, &len_special, argv[i], obj->specials_lim);
                  
               } else if(argv[i][0] == '-') {                
                  append(commands, &len_cmd, argv[i], obj->commands_lim);
                  
               } else if(findch(argv[i], '.', strlen(argv[i])) != -1) { 
                  append(files, &len_files, argv[i], obj->files_lim);
                  
              } else {
                 append(unknown, &len_unknown, argv[i], obj->unknown_lim); 
              
              }
         }
        obj->command_len = len_cmd;
        obj->files_len = len_files;
        obj->special_len = len_special;
        obj->unknown_len = len_unknown;
}



void setcmdlim(clsh *obj, size_t lim) {
     if(!obj) return;
     obj->commands_lim = lim;
}



void setfileslim(clsh *obj, size_t lim) {
     if(!obj) return;
     obj->files_lim = lim;
}



void setspeciallim(clsh *obj, size_t lim) {
     if(!obj) return;
     obj->specials_lim = lim;
}




void setunlim(clsh *obj, size_t lim) {
     if(!obj) return;
     obj->unknown_lim = lim;
}


void setlimits(clsh *obj, size_t cmd, size_t fileslim, size_t spe, size_t unknown) {
	if(!obj) return;
	obj->commands_lim = cmd;
	obj->files_lim = fileslim;
	obj->specials_lim = spe;
	obj->unknown_lim = unknown;
}

size_t getcmdlen(const clsh *obj) {
       if(!obj) return 0;
       return obj->command_len;
}



size_t getfileslen(const clsh *obj) {
        if(!obj) return 0;
       return obj->files_len;
}


size_t getspelen(const clsh *obj) {
        if(!obj) return 0;
       return obj->special_len;
}



size_t getunklen(const clsh *obj) {
        if(!obj) return 0;
       return obj->unknown_len;
}


en = 1;
}

int findch(char *src, int ch, size_t src_size) { //helper
	if(!src || !src_size) 
		return -1;
	char *tmp = memchr(src, ch, src_size);
	if(!tmp) {
		return -1;
	}
	return (tmp-src);
}


void append(char **ptr, size_t *index, char *data, size_t limit) { //to make more readable for idiots like me only
     if(*index > limit) 
        return;
      if(!ptr || !data) return;
      
     ptr[*index] = data;
     (*index)++;
}


void CLShandler(clsh *obj, char **commands, char **files, char **special_statements, char **unknown, int argc, char *argv[]) {
           size_t i, len_cmd = 0, len_files = 0, len_special = 0, len_unknown = 0;
           for(i = 0; i < argc; i++) {
               if(argv[i][0] == '-' && argv[i][1] == '-') {  
                  append(special_statements, &len_special, argv[i], obj->specials_lim);
                  
               } else if(argv[i][0] == '-') {                
                  append(commands, &len_cmd, argv[i], obj->commands_lim);
                  
               } else if(findch(argv[i], '.', strlen(argv[i])) != -1) { 
                  append(files, &len_files, argv[i], obj->files_lim);
                  
              } else {
                 append(unknown, &len_unknown, argv[i], obj->unknown_lim); 
              
              }
         }
        obj->command_len = len_cmd;
        obj->files_len = len_files;
        obj->special_len = len_special;
        obj->unknown_len = len_unknown;
}



void setcmdlim(clsh *obj, size_t lim) {
     if(!obj) return;
     obj->commands_lim = lim;
}



void setfileslim(clsh *obj, size_t lim) {
     if(!obj) return;
     obj->files_lim = lim;
}



void setspeciallim(clsh *obj, size_t lim) {
     if(!obj) return;
     obj->specials_lim = lim;
}




void setunlim(clsh *obj, size_t lim) {
     if(!obj) return;
     obj->unknown_lim = lim;
}


void setlimits(clsh *obj, size_t cmd, size_t fileslim, size_t spe, size_t unknown) {
	if(!obj) return;
	obj->commands_lim = cmd;
	obj->files_lim = fileslim;
	obj->specials_lim = spe;
	obj->unknown_lim = unknown;
}

size_t getcmdlen(const clsh *obj) {
       if(!obj) return 0;
       return obj->command_len;
}



size_t getfileslen(const clsh *obj) {
        if(!obj) return 0;
       return obj->files_len;
}


size_t getspelen(const clsh *obj) {
        if(!obj) return 0;
       return obj->special_len;
}



size_t getunklen(const clsh *obj) {
        if(!obj) return 0;
       return obj->unknown_len;
}


