 	args,
 	"diskd",
 	&rfd,
-	&diskdinfo->wfd);
+	&DIO->wfd);
     if (x < 0)
 	fatalf("execl: %s", Config.Program.diskd);
-    if (rfd != diskdinfo->wfd)
+    if (rfd != DIO->wfd)
 	comm_close(rfd);
-    fd_note(diskdinfo->wfd, "squid -> diskd");
-    commSetTimeout(diskdinfo->wfd, -1, NULL, NULL);
-    commSetNonBlocking(diskdinfo->wfd);
+    fd_note(DIO->wfd, "squid -> diskd");
+    commSetTimeout(DIO->wfd, -1, NULL, NULL);
+    commSetNonBlocking(DIO->wfd);
     
-    commonUfsDirInit (sd);
+    UFSSwapDir::init();
     
     comm_quick_poll_required();
 }
