 	Config2.onoff.enable_purge = 1;
     if (geteuid() == 0) {
 	if (NULL != Config.effectiveUser) {
-    	    struct passwd *pwd = getpwnam(Config.effectiveUser);
-    	    if (NULL == pwd)
-	    /*
-	     * Andres Kroonmaa <andre@online.ee>:
-	     * Some getpwnam() implementations (Solaris?) require
-	     * an available FD < 256 for opening a FILE* to the
-	     * passwd file.
-	     * DW:
-	     * This should be safe at startup, but might still fail
-	     * during reconfigure.
-	     */
-    		fatalf("getpwnam failed to find userid for effective user '%s'",
-    		    Config.effectiveUser,
-    		    xstrerror());
-    	    Config2.effectiveUserID = pwd->pw_uid;
+	    struct passwd *pwd = getpwnam(Config.effectiveUser);
+	    if (NULL == pwd)
+		/*
+		 * Andres Kroonmaa <andre@online.ee>:
+		 * Some getpwnam() implementations (Solaris?) require
+		 * an available FD < 256 for opening a FILE* to the
+		 * passwd file.
+		 * DW:
+		 * This should be safe at startup, but might still fail
+		 * during reconfigure.
+		 */
+		fatalf("getpwnam failed to find userid for effective user '%s'",
+		    Config.effectiveUser,
+		    xstrerror());
+	    Config2.effectiveUserID = pwd->pw_uid;
 	    Config2.effectiveGroupID = pwd->pw_gid;
-       	}
+	}
     } else {
 	Config2.effectiveUserID = geteuid();
 	Config2.effectiveGroupID = getegid();
