 
     // look for and load stylesheet into global MemBuf for it.
     if (Config.errorStylesheet) {
-        char *temp = errorTryLoadText(Config.errorStylesheet,NULL);
-        if (temp) {
-            error_stylesheet.Printf("%s",temp);
-            safe_free(temp);
-        }
+        ErrorPageFile  tmpl("StylesSheet");
+        tmpl.loadFromFile(Config.errorStylesheet);
+        error_stylesheet.Printf("%s",tmpl.text());
     }
+
+    Ssl::errorDetailInitialize();
 }
 
 void
