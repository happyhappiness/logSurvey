 	     * This should be safe at startup, but might still fail
 	     * during reconfigure.
 	     */
-	    fatalf("getpwnam failed to find userid for effective user '%s'",
-		Config.effectiveUser,
-		xstrerror());
-	Config2.effectiveUserID = pwd->pw_uid;
+    		fatalf("getpwnam failed to find userid for effective user '%s'",
+    		    Config.effectiveUser,
+    		    xstrerror());
+    	    Config2.effectiveUserID = pwd->pw_uid;
+	    Config2.effectiveGroupID = pwd->pwd_gid;
+       	}
+    } else {
+	Config2.effectiveUserID = geteuid();
+	Config2.effectiveGroupID = getegid();
     }
     if (NULL != Config.effectiveGroup) {
 	struct group *grp = getgrnam(Config.effectiveGroup);
