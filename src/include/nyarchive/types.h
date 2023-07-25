#ifndef NYARCHIVE_TYPES
#define NYARCHIVE_TYPES

#import "content_headers.h"

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

#endif
