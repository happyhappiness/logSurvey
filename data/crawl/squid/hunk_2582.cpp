     return NULL;
 }
 
-/**
- * \ingroup ErrorPageInternal
- *
- * Load into the in-memory error text Index a file probably available at:
- *  (a) admin specified custom directory (error_directory)
- *  (b) default language translation directory (error_default_language)
- *  (c) English sub-directory where errors should ALWAYS exist
- */
-static char *
-errorLoadText(const char *page_name)
+TemplateFile::TemplateFile(const char *name): silent(false), wasLoaded(false), templateName(name)
 {
-    char *text = NULL;
+    assert(name);
+}
+
+bool
+TemplateFile::loadDefault()
+{
+    if (loaded()) // already loaded?
+        return true;
 
     /** test error_directory configured location */
-    if (Config.errorDirectory)
-        text = errorTryLoadText(page_name, Config.errorDirectory);
+    if (Config.errorDirectory) {
+        char path[MAXPATHLEN];
+        snprintf(path, sizeof(path), "%s/%s", Config.errorDirectory, templateName.termedBuf());
+        loadFromFile(path);
+    }
 
 #if USE_ERR_LOCALES
     /** test error_default_language location */
-    if (!text && Config.errorDefaultLanguage) {
-        char dir[256];
-        snprintf(dir,256,"%s/%s", DEFAULT_SQUID_ERROR_DIR, Config.errorDefaultLanguage);
-        text = errorTryLoadText(page_name, dir);
-        if (!text) {
+    if (!loaded() && Config.errorDefaultLanguage) {
+        if (!tryLoadTemplate(Config.errorDefaultLanguage)) {
             debugs(1, DBG_CRITICAL, "Unable to load default error language files. Reset to backups.");
         }
     }
 #endif
 
     /* test default location if failed (templates == English translation base templates) */
-    if (!text) {
-        text = errorTryLoadText(page_name, DEFAULT_SQUID_ERROR_DIR"/templates");
+    if (!loaded()) {
+        tryLoadTemplate("templates");
     }
 
     /* giving up if failed */
-    if (!text)
+    if (!loaded())
         fatal("failed to find or read error text file.");
 
-    return text;
+    return true;
 }
 
-/// \ingroup ErrorPageInternal
-static char *
-errorTryLoadText(const char *page_name, const char *dir, bool silent)
+bool
+TemplateFile::tryLoadTemplate(const char *lang)
 {
-    int fd;
+    assert(lang);
+
     char path[MAXPATHLEN];
+    /* TODO: prep the directory path string to prevent snprintf ... */
+    snprintf(path, sizeof(path), "%s/%s/%s",
+             DEFAULT_SQUID_ERROR_DIR, lang, templateName.termedBuf());
+    path[MAXPATHLEN-1] = '\0';
+
+    if (loadFromFile(path))
+        return true;
+
+#if HAVE_GLOB
+    if ( strlen(lang) == 2) {
+        /* TODO glob the error directory for sub-dirs matching: <tag> '-*'   */
+        /* use first result. */
+        debugs(4,2, HERE << "wildcard fallback errors not coded yet.");
+    }
+#endif
+
+    return false;
+}
+
+bool
+TemplateFile::loadFromFile(const char *path)
+{
+    int fd;
     char buf[4096];
-    char *text;
     ssize_t len;
-    MemBuf textbuf;
 
-    // maybe received compound parts, maybe an absolute page_name and no dir
-    if (dir)
-        snprintf(path, sizeof(path), "%s/%s", dir, page_name);
-    else
-        snprintf(path, sizeof(path), "%s", page_name);
+    if (loaded()) // already loaded?
+        return true;
 
     fd = file_open(path, O_RDONLY | O_TEXT);
 
     if (fd < 0) {
         /* with dynamic locale negotiation we may see some failures before a success. */
         if (!silent)
             debugs(4, DBG_CRITICAL, HERE << "'" << path << "': " << xstrerror());
-        return NULL;
+        wasLoaded = false;
+        return wasLoaded;
     }
 
-    textbuf.init();
-
     while ((len = FD_READ_METHOD(fd, buf, sizeof(buf))) > 0) {
-        textbuf.append(buf, len);
+        if (!parse(buf, len, false)) {
+            debugs(4, DBG_CRITICAL, HERE << " parse error while reading template file: " << path);
+            wasLoaded = false;
+            return wasLoaded;
+        }
     }
+    parse(buf, 0, true);
 
     if (len < 0) {
         debugs(4, DBG_CRITICAL, HERE << "failed to fully read: '" << path << "': " << xstrerror());
     }
 
     file_close(fd);
 
-    /* Shrink memory size down to exact size. MemBuf has a tencendy
-     * to be rather large..
-     */
-    text = xstrdup(textbuf.buf);
+    wasLoaded = true;
+    return wasLoaded;
+}
+
+bool strHdrAcptLangGetItem(const String &hdr, char *lang, int langLen, size_t &pos)
+{
+    while(pos < hdr.size()) {
+        char *dt = lang;
+
+        if (!pos) {
+            /* skip any initial whitespace. */
+            while (pos < hdr.size() && xisspace(hdr[pos])) pos++;
+        }
+        else {
+            // IFF we terminated the tag on whitespace or ';' we need to skip to the next ',' or end of header.
+            while (pos < hdr.size() && hdr[pos] != ',') pos++;
+            if (hdr[pos] == ',') pos++;
+        }
 
-    textbuf.clean();
+        /*
+         * Header value format:
+         *  - sequence of whitespace delimited tags
+         *  - each tag may suffix with ';'.* which we can ignore.
+         *  - IFF a tag contains only two characters we can wildcard ANY translations matching: <it> '-'? .*
+         *    with preference given to an exact match.
+         */
+        bool invalid_byte = false;
+        while (pos < hdr.size() && hdr[pos] != ';' && hdr[pos] != ',' && !xisspace(hdr[pos]) && dt < (lang + (langLen -1)) ) {
+            if (!invalid_byte) {
+#if USE_HTTP_VIOLATIONS
+                // if accepting violations we may as well accept some broken browsers
+                //  which may send us the right code, wrong ISO formatting.
+                if (hdr[pos] == '_')
+                    *dt = '-';
+                else
+#endif
+                    *dt = xtolower(hdr[pos]);
+                // valid codes only contain A-Z, hyphen (-) and *
+                if (*dt != '-' && *dt != '*' && (*dt < 'a' || *dt > 'z') )
+                    invalid_byte = true;
+                else
+                    dt++; // move to next destination byte.
+            }
+            pos++;
+        }
+        *dt++ = '\0'; // nul-terminated the filename content string before system use.
 
-    return text;
+        debugs(4, 9, HERE << "STATE: dt='" << dt << "', lang='" << lang << "', pos=" << pos << ", buf='" << ((pos < hdr.size()) ? hdr.substr(pos,hdr.size()) : "") << "'");
+
+        /* if we found anything we might use, try it. */
+        if (*lang != '\0' && !invalid_byte)
+            return true;
+    }
+    return false;
+}
+
+bool
+TemplateFile::loadFor(HttpRequest *request)
+{
+    String hdr;
+
+    if (loaded()) // already loaded?
+        return true;
+
+    if (!request || !request->header.getList(HDR_ACCEPT_LANGUAGE, &hdr) )
+        return false;
+
+    char lang[256];
+    size_t pos = 0; // current parsing position in header string
+
+    debugs(4, 6, HERE << "Testing Header: '" << hdr << "'");
+
+    while ( strHdrAcptLangGetItem(hdr, lang, 256, pos) ) {
+
+        /* wildcard uses the configured default language */
+        if (lang[0] == '*' && lang[1] == '\0') {
+            debugs(4, 6, HERE << "Found language '" << lang << "'. Using configured default.");
+            return false;
+        }
+
+        debugs(4, 6, HERE << "Found language '" << lang << "', testing for available template");
+
+        if (tryLoadTemplate(lang)) {
+            /* store the language we found for the Content-Language reply header */
+            errLanguage = lang;
+            break;
+        } else if (Config.errorLogMissingLanguages) {
+            debugs(4, DBG_IMPORTANT, "WARNING: Error Pages Missing Language: " << lang);
+        }
+    }
+
+    return loaded();
 }
 
 /// \ingroup ErrorPageInternal
