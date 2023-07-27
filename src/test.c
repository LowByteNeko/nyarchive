#include <nyarchive/headers.h>
#include <stdio.h>

int main() {
    dir_header header = generate_dir_header("src");
    printf("%s\n", header.name);
    printf("%ld %d %d %u\n", header.created_at, header.uid, header.gid, header.permissions);

    return 0;
}