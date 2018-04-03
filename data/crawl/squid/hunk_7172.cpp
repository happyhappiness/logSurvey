 {
     FD_ENTRY *fde = &fd_table[fd];
     if (fde->type == FD_FILE) {
-	if (fde->read_handler)
-	    fatal_dump("file_close: read_handler present");
-	if (fde->write_handler)
-	    fatal_dump("file_close: write_handler present");
+	assert(fde->read_handler == NULL);
+	assert(fde->write_handler == NULL);
     }
     fdUpdateBiggest(fd, fde->open = FD_CLOSE);
     memset(fde, '\0', sizeof(FD_ENTRY));
