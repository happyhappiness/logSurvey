     if (do_quote)
         p = html_quote(p);
 
+    if (url_presentable && !no_urlescape)
+        p = rfc1738_escape_part(p);
+
     return p;
 }
 
+void
+ErrorState::DenyInfoLocation(const char *name, HttpRequest *request, MemBuf &result)
+{
+    char const *m = name;
+    char const *p = m;
+    char const *t;
+
+    while ((p = strchr(m, '%'))) {
+        result.append(m, p - m);       /* copy */
+        t = Convert(*++p, true);       /* convert */
+        result.Printf("%s", t);        /* copy */
+        m = p + 1;                     /* advance */
+    }
+
+    if (*m)
+        result.Printf("%s", m);        /* copy tail */
+
+    assert((size_t)result.contentSize() == strlen(result.content()));
+}
+
 HttpReply *
 ErrorState::BuildHttpReply()
 {
