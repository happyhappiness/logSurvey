 helpMe( void )
 // purpuse: write help message and exit
 {
-    printf( "\n%s\nUsage:\t%s\t[-a] [-c cf] [-d l] [-(f|F) fn | -(e|E) re] "
+    printf( "\nUsage:\t%s\t[-a] [-c cf] [-d l] [-(f|F) fn | -(e|E) re] "
             "[-p h[:p]]\n\t\t[-P #] [-s] [-v] [-C dir [-H]] [-n]\n\n",
-            ::RCS_ID, ::programname );
+            ::programname );
     printf(
         " -a\tdisplay a little rotating thingy to indicate that I am alive (tty only).\n"
         " -c c\tsquid.conf location, default \"%s\".\n"
