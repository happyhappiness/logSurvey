     return p;
 }
 
-/// \ingroup ServerProtocolFTPInternal
-static const char *
-dots_fill(size_t len)
-{
-    static char buf[256];
-    size_t i = 0;
-
-    if (len > Config.Ftp.list_width) {
-        memset(buf, ' ', 256);
-        buf[0] = '\n';
-        buf[Config.Ftp.list_width + 4] = '\0';
-        return buf;
-    }
-
-    for (i = len; i < Config.Ftp.list_width; i++)
-        buf[i - len] = (i % 2) ? '.' : ' ';
-
-    buf[i - len] = '\0';
-
-    return buf;
-}
-
-char *
+MemBuf *
 FtpStateData::htmlifyListEntry(const char *line)
 {
-    LOCAL_ARRAY(char, icon, 2048);
-    LOCAL_ARRAY(char, href, 2048 + 40);
-    LOCAL_ARRAY(char, text, 2048);
-    LOCAL_ARRAY(char, size, 2048);
-    LOCAL_ARRAY(char, chdir, 2048 + 40);
-    LOCAL_ARRAY(char, view, 2048 + 40);
-    LOCAL_ARRAY(char, download, 2048 + 40);
-    LOCAL_ARRAY(char, link, 2048 + 40);
-    LOCAL_ARRAY(char, html, 8192);
-    LOCAL_ARRAY(char, prefix, 2048);
-    size_t width = Config.Ftp.list_width;
+    char icon[2048];
+    char href[2048 + 40];
+    char text[ 2048];
+    char size[ 2048];
+    char chdir[ 2048 + 40];
+    char view[ 2048 + 40];
+    char download[ 2048 + 40];
+    char link[ 2048 + 40];
+    MemBuf *html;
+    char prefix[2048];
     ftpListParts *parts;
-    *icon = *href = *text = *size = *chdir = *view = *download = *link = *html = '\0';
+    *icon = *href = *text = *size = *chdir = *view = *download = *link = '\0';
 
-    if ((int) strlen(line) > 1024) {
-        snprintf(html, 8192, "%s\n", line);
+    debugs(9, 7, HERE << " line ={" << line << "}");
+
+    if (strlen(line) > 1024) {
+        html = new MemBuf();
+        html->init();
+        html->Printf("<tr><td colspan=\"5\">%s</td></tr>\n", line);
         return html;
     }
 
