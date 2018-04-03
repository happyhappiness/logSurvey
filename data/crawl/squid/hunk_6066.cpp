 	hier_strings[al->hier.code]);
 }
 
-static void
-accessLogOpen(const char *fname)
-{
-    assert(fname);
-    xstrncpy(LogfileName, fname, SQUID_MAXPATHLEN);
-    LogfileFD = file_open(LogfileName, O_WRONLY | O_CREAT);
-    if (LogfileFD == DISK_ERROR) {
-	if (ENOENT == errno) {
-	    fatalf("%s cannot be created, since the\n"
-		"\tdirectory it is to reside in does not exist."
-		"\t(%s)\n", LogfileName, xstrerror());
-	} else if (EACCES == errno) {
-	    fatalf("cannot create %s:\n"
-		"\t%s.\n"
-		"\tThe directory access.log is to reside in needs to be\n"
-		"\twriteable by the user %s, the cache_effective_user\n"
-		"\tset in squid.conf.",
-		LogfileName, xstrerror(), Config.effectiveUser);
-	} else {
-	    debug(50, 0) ("%s: %s\n", LogfileName, xstrerror());
-	    fatalf("Cannot open %s: %s", LogfileName, xstrerror());
-	}
-    }
-    LogfileStatus = LOG_ENABLE;
-}
-
 void
 accessLogLog(AccessLogEntry * al)
 {
-    MemBuf mb;
-    char *xbuf = NULL;
     LOCAL_ARRAY(char, ident_buf, USER_IDENT_SZ);
 
     if (LogfileStatus != LOG_ENABLE)
