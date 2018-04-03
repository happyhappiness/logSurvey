 {
     char buf[512];
     snprintf(buf, sizeof(buf), "%i %s \"%s\"", code, visible_appname_string, text);
-    putStr(HDR_WARNING, buf);
+    putStr(Http::HdrType::WARNING, buf);
 }
 
 /* add extension header (these fields are not parsed/analyzed/joined, etc.) */
