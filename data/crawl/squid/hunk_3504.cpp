     lf->data = ll;
 
     if (strncmp(path, "//", 2) == 0) {
-       path += 2;
+        path += 2;
     }
     strAddr = xstrdup(path);
     if (!GetHostWithPort(strAddr, &addr)) {
-	if (lf->flags.fatal) {
-	    fatalf("Invalid UDP logging address '%s'\n", lf->path);
-	} else {
-	    debugs(50, DBG_IMPORTANT, "Invalid UDP logging address '" << lf->path << "'");
-	    safe_free(strAddr);
-	    return FALSE;
-	}
+        if (lf->flags.fatal) {
+            fatalf("Invalid UDP logging address '%s'\n", lf->path);
+        } else {
+            debugs(50, DBG_IMPORTANT, "Invalid UDP logging address '" << lf->path << "'");
+            safe_free(strAddr);
+            return FALSE;
+        }
     }
     safe_free(strAddr);
 
