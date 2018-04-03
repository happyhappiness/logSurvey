 #define SZ_FMT "%zu"
 #endif
 
-static void report(const char* name, unsigned int count, size_t size)
+static void report(const char *name, unsigned int count, size_t size)
 {
     fprintf(stderr, "%10s: %8u (" SZ_FMT " kB)\n", name, count, size);
 }
