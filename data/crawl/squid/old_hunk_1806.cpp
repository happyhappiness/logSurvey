            while ( offset + addon <= datastart ) {
                unsigned int size = 0;
                memcpy( &size, linebuffer+offset+sizeof(char), sizeof(unsigned int) );
                meta.append( SquidMetaType(*(linebuffer+offset)),
                             size, linebuffer+offset+addon );
                offset += ( addon + size );