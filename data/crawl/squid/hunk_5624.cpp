     return cachable;
 }
 
+static void
+gopherHTMLHeader(StoreEntry * e, const char *title, const char *substring)
+{
+    storeAppendPrintf(e, "<HTML><HEAD><TITLE>");
+    storeAppendPrintf(e, title, substring);
+    storeAppendPrintf(e, "</TITLE></HEAD>\n<BODY><H1>");
+    storeAppendPrintf(e, title, substring);
+    storeAppendPrintf(e, "</H1>\n");
+}
+
+static void
+gopherHTMLFooter(StoreEntry * e)
+{
+    storeAppendPrintf(e, "<HR>\n");
+    storeAppendPrintf(e, "<ADDRESS>\n");
+    storeAppendPrintf(e, "Generated %s by %s (%s)\n",
+	mkrfc1123(squid_curtime),
+	getMyHostname(),
+	full_appname_string);
+    storeAppendPrintf(e, "</ADDRESS></BODY></HTML>\n");
+}
+
 static void
 gopherEndHTML(GopherStateData * gopherState)
 {
-    if (!gopherState->data_in)
-	storeAppendPrintf(gopherState->entry,
-	    "<HTML><HEAD><TITLE>Server Return Nothing.</TITLE>\n"
-	    "</HEAD><BODY><HR><H1>Server Return Nothing.</H1></BODY></HTML>\n");
+    StoreEntry *e = gopherState->entry;
+    if (!gopherState->data_in) {
+	gopherHTMLHeader(e, "Server Return Nothing", NULL);
+	storeAppendPrintf(e, "<P>The Gopher query resulted in a blank response</P>");
+    } else {
+	storeAppendPrintf(e, "</PRE>\n");
+    }
+    gopherHTMLFooter(e);
 }
 
 
