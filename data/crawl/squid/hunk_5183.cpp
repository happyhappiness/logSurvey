 
     assert(q->aq_state == AQ_STATE_SETUP);
 
-#if 0
-
-    file_write(fd, offset, buf, len, callback, data, freefunc);
-#endif
     /* Find a free slot */
     slot = a_file_findslot(q);
 
     if (slot < 0) {
-        /* No free slot? Callback error, and return */
-        fatal("Aiee! out of aiocb slots!\n");
+        debug(79, 1) ("WARNING: out of aiocb slots!\n");
+        /* fall back to blocking method */
+        file_write(fd, offset, buf, len, callback, data, freefunc);
+        return;
     }
 
     /* Mark slot as ours */
