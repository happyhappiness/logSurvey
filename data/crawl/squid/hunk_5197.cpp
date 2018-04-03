     char *new_path = xstrdup(logFile(".new"));
     int fd;
     file_close(swaplog_fd);
-#if defined (_SQUID_OS2_) || defined (_SQUID_WIN32_)
 
-    if (::unlink(swaplog_path) < 0) {
-        debug(50, 0) ("%s: %s\n", swaplog_path, xstrerror());
-        fatal("commonUfsDirCloseTmpSwapLog: unlink failed");
-    }
-
-#endif
     if (xrename(new_path, swaplog_path) < 0) {
         fatal("commonUfsDirCloseTmpSwapLog: rename failed");
     }
