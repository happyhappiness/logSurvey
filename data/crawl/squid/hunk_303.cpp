         fp = fopen(file_name, "r");
     }
 
-    if (fp == NULL)
-        fatalf("Unable to open configuration file: %s: %s", file_name, xstrerror());
+    if (!fp) {
+        int xerrno = errno;
+        fatalf("Unable to open configuration file: %s: %s", file_name, xstrerr(xerrno));
+    }
 
 #if _SQUID_WINDOWS_
     setmode(fileno(fp), O_TEXT);
