 void
 FtpStateData::listingStart()
 {
+    debugs(9,3,HERE << "listingStart()");
     wordlist *w;
     char *dirup;
     int i, j, k;
     const char *title = title_url.buf();
-    storeAppendPrintf(entry, "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\">\n");
-    storeAppendPrintf(entry, "<!-- HTML listing generated by Squid %s -->\n",
-                      version_string);
-    storeAppendPrintf(entry, "<!-- %s -->\n", mkrfc1123(squid_curtime));
-    storeAppendPrintf(entry, "<HTML><HEAD><TITLE>\n");
+    flags.listing_started = true;
+    printfReplyBody("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\">\n");
+    printfReplyBody("<!-- HTML listing generated by Squid %s -->\n",
+                    version_string);
+    printfReplyBody("<!-- %s -->\n", mkrfc1123(squid_curtime));
+    printfReplyBody("<HTML><HEAD><TITLE>\n");
     {
         char *t = xstrdup(title);
         rfc1738_unescape(t);
-        storeAppendPrintf(entry, "FTP Directory: %s\n", html_quote(t));
+        printfReplyBody("FTP Directory: %s\n", html_quote(t));
         xfree(t);
     }
 
-    storeAppendPrintf(entry, "</TITLE>\n");
-    storeAppendPrintf(entry, "<STYLE type=\"text/css\"><!--BODY{background-color:#ffffff;font-family:verdana,sans-serif}--></STYLE>\n");
+    printfReplyBody("</TITLE>\n");
+    printfReplyBody("<STYLE type=\"text/css\"><!--BODY{background-color:#ffffff;font-family:verdana,sans-serif}--></STYLE>\n");
 
     if (flags.need_base_href)
-        storeAppendPrintf(entry, "<BASE HREF=\"%s\">\n",
-                          html_quote(base_href.buf()));
+        printfReplyBody("<BASE HREF=\"%s\">\n",
+                        html_quote(base_href.buf()));
 
-    storeAppendPrintf(entry, "</HEAD><BODY>\n");
+    printfReplyBody("</HEAD><BODY>\n");
 
     if (cwd_message) {
-        storeAppendPrintf(entry, "<PRE>\n");
+        printfReplyBody("<PRE>\n");
 
         for (w = cwd_message; w; w = w->next)
-            storeAppendPrintf(entry, "%s\n", html_quote(w->key));
+            printfReplyBody("%s\n", html_quote(w->key));
 
-        storeAppendPrintf(entry, "</PRE>\n");
+        printfReplyBody("</PRE>\n");
 
-        storeAppendPrintf(entry, "<HR noshade size=\"1px\">\n");
+        printfReplyBody("<HR noshade size=\"1px\">\n");
 
         wordlistDestroy(&cwd_message);
     }
 
-    storeAppendPrintf(entry, "<H2>\n");
-    storeAppendPrintf(entry, "FTP Directory: ");
+    printfReplyBody("<H2>\n");
+    printfReplyBody("FTP Directory: ");
     /* "ftp://" == 6 characters */
     assert(title_url.size() >= 6);
     k = 6 + strcspn(&title[6], "/");
 
     for (i = 6, j = 0; title[i]; j = i) {
-        storeAppendPrintf(entry, "<A HREF=\"");
+        printfReplyBody("<A HREF=\"");
         i += strcspn(&title[i], "/");
 
         if (i > j) {
             char *url = xstrdup(title);
             url[i] = '\0';
-            storeAppendPrintf(entry, "%s", html_quote(url + k));
-            storeAppendPrintf(entry, "/");
-            storeAppendPrintf(entry, "\">");
+            printfReplyBody("%s", html_quote(url + k));
+            printfReplyBody("/");
+            printfReplyBody("\">");
             rfc1738_unescape(url + j);
-            storeAppendPrintf(entry, "%s", html_quote(url + j));
+            printfReplyBody("%s", html_quote(url + j));
             safe_free(url);
-            storeAppendPrintf(entry, "</A>");
+            printfReplyBody("</A>");
         }
 
-        storeAppendPrintf(entry, "/");
+        printfReplyBody("/");
 
         if (title[i] == '/')
             i++;
 
         if (i == j) {
             /* Error guard, or "assert" */
-            storeAppendPrintf(entry, "ERROR: Failed to parse URL: %s\n",
-                              html_quote(title));
+            printfReplyBody("ERROR: Failed to parse URL: %s\n",
+                            html_quote(title));
             debug(9, 0) ("Failed to parse URL: %s\n", title);
             break;
         }
     }
 
-    storeAppendPrintf(entry, "</H2>\n");
-    storeAppendPrintf(entry, "<PRE>\n");
+    printfReplyBody("</H2>\n");
+    printfReplyBody("<PRE>\n");
     dirup = htmlifyListEntry("<internal-dirup>");
-    storeAppend(entry, dirup, strlen(dirup));
+    writeReplyBody(dirup, strlen(dirup));
     flags.html_header_sent = 1;
 }
 
 void
 FtpStateData::listingFinish()
 {
+    debugs(9,3,HERE << "listingFinish()");
     storeBuffer(entry);
-    storeAppendPrintf(entry, "</PRE>\n");
+    printfReplyBody("</PRE>\n");
 
     if (flags.listformat_unknown && !flags.tried_nlst) {
-        storeAppendPrintf(entry, "<A HREF=\"%s/;type=d\">[As plain directory]</A>\n",
-                          flags.dir_slash ? rfc1738_escape_part(old_filepath) : ".");
+        printfReplyBody("<A HREF=\"%s/;type=d\">[As plain directory]</A>\n",
+                        flags.dir_slash ? rfc1738_escape_part(old_filepath) : ".");
     } else if (typecode == 'D') {
         const char *path = flags.dir_slash ? filepath : ".";
-        storeAppendPrintf(entry, "<A HREF=\"%s/\">[As extended directory]</A>\n", html_quote(path));
+        printfReplyBody("<A HREF=\"%s/\">[As extended directory]</A>\n", html_quote(path));
     }
 
-    storeAppendPrintf(entry, "<HR noshade size=\"1px\">\n");
-    storeAppendPrintf(entry, "<ADDRESS>\n");
-    storeAppendPrintf(entry, "Generated %s by %s (%s)\n",
-                      mkrfc1123(squid_curtime),
-                      getMyHostname(),
-                      visible_appname_string);
-    storeAppendPrintf(entry, "</ADDRESS></BODY></HTML>\n");
+    printfReplyBody("<HR noshade size=\"1px\">\n");
+    printfReplyBody("<ADDRESS>\n");
+    printfReplyBody("Generated %s by %s (%s)\n",
+                    mkrfc1123(squid_curtime),
+                    getMyHostname(),
+                    visible_appname_string);
+    printfReplyBody("</ADDRESS></BODY></HTML>\n");
 }
 
 static const char *Month[] =
