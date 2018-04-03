 	    debug(50, 0) ("chdir: %s: %s\n", Config.coredump_dir, xstrerror());
 	}
     }
-    if (!Config.effectiveUser) {
-	char *p = getcwd(NULL, 0);
-	debug(0, 1) ("Current Directory is %s\n", p);
-	xfree(p);
-	return;
-    }
-    /* we were probably started as root, so cd to a swap
-     * directory in case we dump core */
-    if (!chdir(storeSwapDir(0))) {
-	debug(0, 1) ("Set Current Directory to %s\n", storeSwapDir(0));
-	return;
-    } else {
-	debug(50, 0) ("%s: %s\n", storeSwapDir(0), xstrerror());
-	fatal_dump("Cannot cd to swap directory?");
-    }
+    debug(0, 1) ("Current Directory is %s\n", p);
+    xfree(p);
+    return;
 }
 
 static void