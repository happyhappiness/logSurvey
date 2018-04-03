     storeAppendPrintf(e, "FTP Directory: ");
     /* "ftp://" == 6 characters */
     assert(ftpState->title_url.size() >= 6);
-    title = html_quote(ftpState->title_url.buf());
+    k = 6 + strcspn(&title[6], "/");
 
     for (i = 6, j = 0; title[i]; j = i) {
         storeAppendPrintf(e, "<A HREF=\"");
         i += strcspn(&title[i], "/");
 
-        if (title[i] == '/')
-            i++;
-
-        for (k = 0; k < i; k++)
-            storeAppendPrintf(e, "%c", title[k]);
-
-        storeAppendPrintf(e, "\">");
-
-        for (k = j; k < i - 1; k++)
-            storeAppendPrintf(e, "%c", title[k]);
-
-        if (ftpState->title_url.buf()[k] != '/')
-            storeAppendPrintf(e, "%c", title[k++]);
+        if (i > j) {
+            char *url = xstrdup(title);
+            url[i] = '\0';
+            storeAppendPrintf(e, "%s", html_quote(url + k));
+            storeAppendPrintf(e, "/");
+            storeAppendPrintf(e, "\">");
+            rfc1738_unescape(url + j);
+            storeAppendPrintf(e, "%s", html_quote(url + j));
+            safe_free(url);
+            storeAppendPrintf(e, "</A>");
+        }
 
-        storeAppendPrintf(e, "</A>");
+        storeAppendPrintf(e, "/");
 
-        if (k < i)
-            storeAppendPrintf(e, "%c", title[k++]);
+        if (title[i] == '/')
+            i++;
 
         if (i == j) {
             /* Error guard, or "assert" */
             storeAppendPrintf(e, "ERROR: Failed to parse URL: %s\n",
-                              html_quote(ftpState->title_url.buf()));
-            debug(9, 0) ("Failed to parse URL: %s\n", ftpState->title_url.buf());
+                              html_quote(title));
+            debug(9, 0) ("Failed to parse URL: %s\n", title);
             break;
         }
     }