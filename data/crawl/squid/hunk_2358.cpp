     exit (1);
 }
 
-void
-fatal_dump(const char *message)
-{
-    fprintf(stderr, "Fatal: %s",message);
-    exit (1);
-}
-
-void
-fatal(const char *message)
-{
-    fprintf(stderr, "Fatal: %s", message);
-    exit (1);
-}
-
-/* used by fatalf */
-static void
-fatalvf(const char *fmt, va_list args)
-{
-    static char fatal_str[BUFSIZ];
-    vsnprintf(fatal_str, sizeof(fatal_str), fmt, args);
-    fatal(fatal_str);
-}
-
-/* printf-style interface for fatal */
-void
-fatalf(const char *fmt,...)
-{
-    va_list args;
-    va_start(args, fmt);
-    fatalvf(fmt, args);
-    va_end(args);
-}
-
-void
-debug_trap(const char *message)
-{
-    fatal(message);
-}
-
 dlink_node *
 dlinkNodeNew()
 {