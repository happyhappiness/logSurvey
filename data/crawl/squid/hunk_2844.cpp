         debugs(4, 2, HERE << "No existing error page language negotiated for " << errorPageName(page_id) << ". Using default error file.");
     }
 
+    return ConvertText(m, true);
+}
+
+MemBuf *ErrorState::ConvertText(const char *text, bool allowRecursion)
+{
+    MemBuf *content = new MemBuf;
+    const char *p;
+    const char *m = text;
     assert(m);
     content->init();
 
     while ((p = strchr(m, '%'))) {
         content->append(m, p - m);	/* copy */
-        t = Convert(*++p, false);	/* convert */
+        const char *t = Convert(*++p, false, allowRecursion);	/* convert */
         content->Printf("%s", t);	/* copy */
         m = p + 1;			/* advance */
     }
