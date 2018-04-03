         exit(1);
     }
 
-#ifdef _SQUID_WIN32_
+#if _SQUID_WINDOWS_
     setmode(fileno(fp), O_TEXT);
-
 #endif
 
     fprintf(fp,
