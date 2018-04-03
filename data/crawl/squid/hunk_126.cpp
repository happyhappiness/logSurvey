     }
 
     // prepare regular expression for matching
+    static const char * expression = "^[ \t]*cache_dir([ \t]+([[:alpha:]]+))?[ \t]+([[:graph:]]+)[ \t]+([0-9]+)[ \t]+([0-9]+)[ \t]+([0-9]+)";
     if ( debug ) fprintf( debug, "# trying to compile \"%s\"\n", expression );
-    regex_t rexp;
-    int result = regcomp( &rexp, expression, REG_EXTENDED );
-    if ( result != 0 ) {
-        char buffer[256];
-        regerror( result, &rexp, buffer, sizeof(buffer) );
-        fprintf( stderr, "regular expression \"%s\": %s\n", expression, buffer );
-        return -1;
-    }
+
+    static const std::regex rexp(expression, std::regex::extended);
 
     // read line by line
     if ( debug ) fputs( "# trying to read lines\n", debug );
 
-    regmatch_t subs[8];
+    std::smatch subs; // set of std::string so we can use ==
     char *s, line[1024];
     CacheDir cd;
     while ( cfgin.getline( line, sizeof(line)) ) {
