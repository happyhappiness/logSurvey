     unlinkd_fd = unlinkdCreate();
     if (unlinkd_fd < 0)
 	fatal("unlinkdInit: failed to start unlinkd\n");
-    fd_note(unlinkd_fd, Config.Program.unlinkd);
     debug(43, 0, "Unlinkd pipe opened on FD %d\n", unlinkd_fd);
 }
 
