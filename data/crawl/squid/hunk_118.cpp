 //          fn (IN): file name of squid.conf to use
 // returns: number of entries, or negative to warn of errors
 {
+    static const char* expression =
+        "^[ \t]*cache_dir([ \t]+([[:alpha:]]+))?[ \t]+([[:graph:]]+)[ \t]+([0-9]+)[ \t]+([0-9]+)[ \t]+([0-9]+)";
+
     // try to open file
     if ( debug ) fprintf( debug, "# trying to open %s\n", fn ? fn : "(null)" );
     std::ifstream cfgin(fn);
