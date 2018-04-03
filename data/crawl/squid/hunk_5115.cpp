     char *new_path = xstrdup(storeCossDirSwapLogFile(sd, ".new"));
     int anfd;
     file_close(sd->swaplog_fd);
-#if defined (_SQUID_OS2_) || defined (_SQUID_CYGWIN_)
 
-    if (unlink(swaplog_path) < 0) {
-        debug(50, 0) ("%s: %s\n", swaplog_path, xstrerror());
-        fatal("storeCossDirCloseTmpSwapLog: unlink failed");
-    }
-
-#endif
     if (xrename(new_path, swaplog_path) < 0) {
         fatal("storeCossDirCloseTmpSwapLog: rename failed");
     }
