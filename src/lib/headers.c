#include <unistd.h>
#include <time.h>
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <nyarchive/headers.h>

// directory must be name of the directory
dir_header generate_dir_header(char *directory) {
    dir_header header;
    memset(&header, 0, sizeof(dir_header));

    size_t length = strlen(directory);
    assert(length <= 255);

    int dirFd = open(directory, O_RDONLY | O_DIRECTORY);

    struct statx dir_info;

    if (statx(dirFd, "", AT_EMPTY_PATH,
                STATX_BTIME | STATX_MODE | STATX_UID | STATX_GID,
                &dir_info) == -1) {
        perror("Getting information about directory");
        return header;
    }

    memcpy(header.name, directory, strlen(directory));
    header.created_at = dir_info.stx_btime.tv_sec;
    header.permissions = dir_info.stx_mode;
    header.uid = dir_info.stx_uid;
    header.gid = dir_info.stx_gid;
    close(dirFd);

    return header;
}
