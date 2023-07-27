#include <nyarchive/headers.h>
#include <stdio.h>

int main() {
    dir_header header = generate_dir_header("src");
    printf("%s\n", header.name);
    printf("%ld %d %d %u\n", header.created_at, header.uid, header.gid, header.permissions);

    file_header header2 = generate_file_header("LICENSE", 0);
    printf("%s\n", header2.name);
    printf("%ld %d %d %u %ld\n", header2.created_at, header2.uid, header2.gid, header2.permissions, header2.size);
    return 0;
}