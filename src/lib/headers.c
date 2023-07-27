#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <nyarchive/headers.h>

// directory must be named of the directory
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

    memcpy(header.name, directory, length);
    header.created_at = dir_info.stx_btime.tv_sec;
    header.permissions = dir_info.stx_mode;
    header.uid = dir_info.stx_uid;
    header.gid = dir_info.stx_gid;
    close(dirFd);

    return header;
}

file_header generate_file_header(char *file, short checksum) {
    file_header header;
    memset(&header, 0, sizeof(file_header));

    size_t length = strlen(file);
    assert(length <= 255);

    int fd = open(file, O_RDONLY);
    struct statx file_info;

    if (statx(fd, "", AT_EMPTY_PATH,
              STATX_BTIME | STATX_MODE | STATX_UID | STATX_GID| STATX_SIZE,
              &file_info) == -1) {
        perror("Getting information about directory");
        return header;
    }

    if (checksum) {
        errno = ENOSYS;
        perror("Checksum failed");
        return header;
    }

    memcpy(header.name, file, length);
    header.created_at = file_info.stx_btime.tv_sec;
    header.permissions = file_info.stx_mode;
    header.uid = file_info.stx_uid;
    header.gid = file_info.stx_gid;
    header.size = file_info.stx_size;
    close(fd);

    return header;
}