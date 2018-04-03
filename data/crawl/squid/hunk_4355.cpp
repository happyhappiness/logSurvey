     static void parseOptions(char const *);
 
 private:
+    // Hack: replaces global ::xassert() to debug debugging assertions
+    static void xassert(const char *msg, const char *file, int line);
+	
     static std::ostringstream *CurrentDebug;
+    static int TheDepth; // level of nested debugging calls
 };
 
 /* Debug stream */
