             while ( offset + addon <= datastart ) {
                 unsigned int size = 0;
                 memcpy( &size, linebuffer+offset+sizeof(char), sizeof(unsigned int) );
+                if (size+offset > readLen) {
+                    fputs( "WARNING: Partial meta data loaded.\n", stderr );
+                    break;
+                }
                 meta.append( SquidMetaType(*(linebuffer+offset)),
                              size, linebuffer+offset+addon );
                 offset += ( addon + size );