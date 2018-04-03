     }
 
     /* giving up if failed */
-    if (!loaded())
-        fatal("failed to find or read error text file.");
+    if (!loaded()) {
+        debugs(1, DBG_CRITICAL, "WARNING: failed to find or read error text file " << templateName);
+        parse("Internal Error: Missing Template ", 33, '\0');
+        parse(templateName.termedBuf(), templateName.size(), '\0');
+    }
 
     return true;
 }
