#include "linkedList_Elian.h"
#ifndef files_H_INCLUDED
#define files_H_INCLUDED
int files_CreateFileText(char* file_Path);
int files_LoadFromText(char* file_path, LinkedList* linkedList);
int files_Parser_ObjectAFromText(FILE *ptr_File, LinkedList *linkedList);
int files_SaveAsText(char* file_path, LinkedList* linkedList);

int files_CreateFileBinary(char* file_Path);
int files_LoadFromBinary(char* path, LinkedList* linkedList);
int files_Parser_ObjectAFromBinary(FILE *ptr_File, LinkedList *linkedList);
int files_SaveAsBinary(char* file_path, LinkedList* linkedList);
#endif

