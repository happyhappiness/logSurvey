 
     /* Initiate aio */
     if (aio_read(&qe->aq_e_aiocb) < 0) {
-        fatalf("Aiee! aio_read() returned error (%d)!\n", errno);
+        debug(79, 1) ("WARNING: aio_read() returned error: %s\n", xstrerror());
+        /* fall back to blocking method */
+        file_read(fd, (char *) buf, req_len, offset, callback, data);
     }
 }
 
