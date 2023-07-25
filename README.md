# nyarchive
Own simple, highly efficent archive format 

## TODO
### libnyarchive
> Small library to handle .nya ( archive ) files
- [x] Custom headers per type ( Dir, File, Hardlink, Symlink ) 
- [x] Header flags ( Checksum )
- [ ] .nya ( archive ) parser
- [ ] .nya ( archive ) generator
- [ ] Support for checksums ( SHA-256 )
- [ ] Checksum-less mode
### nyarchive
> Application built with libnyarchive to create and manipulate archives
- [ ] Archive files into .nya ( archive )
- [ ] Unarchive files from .nya ( archive )
- [ ] Multi-threaded archiving
- [ ] Support for compression algorithms
