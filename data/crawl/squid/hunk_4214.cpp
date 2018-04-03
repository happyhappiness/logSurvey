         }
     }
 
+    error_stylesheet.reset();
+
     // look for and load stylesheet into global MemBuf for it.
     if(Config.errorStylesheet) {
-        error_page_stylesheet_content = errorLoadText(Config.errorStylesheet);
+        char *temp = errorLoadText(Config.errorStylesheet);
+        if(temp) {
+            error_stylesheet.Printf("%s",temp);
+            safe_free(temp);
+        }
     }
 }
 
