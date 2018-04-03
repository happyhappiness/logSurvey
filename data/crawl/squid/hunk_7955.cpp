     stat_init(&CacheInfo, getAccessLogFile());
     storeInit();
     stmemInit();
-
-#ifdef WRITE_PID_FILE
-    /* Try to write the pid to cached.pid in the same directory as
-     * cached.conf */
-    memset(pidfn, '\0', MAXPATHLEN);
-    strcpy(pidfn, config_file);
-    if ((s = strrchr(pidfn, '/')) != NULL)
-	strcpy(s, "/cached.pid");
-    else
-	strcpy(pidfn, "/usr/local/harvest/lib/cached.pid");
-    pid_fp = fopen(pidfn, "w");
-    if (pid_fp != NULL) {
-	fprintf(pid_fp, "%d\n", (int) getpid());
-	fclose(pid_fp);
-    }
-#endif
+    writePidFile();
 
     /* after this point we want to see the mallinfo() output */
     do_mallinfo = 1;
