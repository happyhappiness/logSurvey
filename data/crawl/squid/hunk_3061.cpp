     // seek end of output file ...
     off_t position = lseek( out, filesize-metasize-1, SEEK_SET );
     if ( position == -1 ) {
-        fprintf( stderr, "lseek(%s,%lu): %s\n", filename, filesize-metasize,
+        fprintf( stderr, "lseek(%s,%lu): %s\n", filename, 
+                 (unsigned long)filesize-metasize,
                  strerror(errno) );
         BAUTZ(false);
     } else if ( debug & 0x02 ) {
         fprintf( stderr, "# filesize=%lu, metasize=%lu, filepos=%ld\n",
-                 filesize, metasize, position );
+                 (unsigned long)filesize, (unsigned long)metasize,
+                 (long)position );
     }
 
     // ...and write 1 byte there (create a file that length)
