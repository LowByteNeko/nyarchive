#ifndef NYARCHIVE_HEADERS
#define NYARCHIVE_HEADERS

#include <sys/types.h>

typedef enum {
    Dir = 1 << 0,
    File = 1 << 1,
    Hardlink = 1 << 2,
    Symlink = 1 << 3
} header_type;

typedef enum {
    Checksum = 1 << 7
} header_flags;

typedef struct {
    char name[255];
    time_t created_at;
    mode_t permissions;
    uid_t uid;
    gid_t gid;
} dir_header;

typedef struct {
    char name[255];
    time_t created_at;
    off_t size;
    mode_t permissions;
    uid_t uid;
    gid_t gid;
    unsigned char *checksum;
} file_header;

typedef struct {
    char name[255];
    time_t created_at;
    mode_t permissions;
    uid_t uid;
    gid_t gid;
    char *path; // strlen can be used here
} hardlink_header;

typedef hardlink_header symlink_header;

dir_header generate_dir_header(char *directory);
file_header generate_file_header(char *file, short checksum);
#endif
