#ifndef NYARCHIVE_TYPES
#define NYARCHIVE_TYPES

#include <stdio.h>

#import "headers.h"

typedef struct {
    union {
        dir_header d;
        file_header f;
        hardlink_header h;
        symlink_header s;
    } data;
    header_type type;
    unsigned long length;
    unsigned char *content;
} nya_file;

typedef FILE* nya_archive;

#endif
