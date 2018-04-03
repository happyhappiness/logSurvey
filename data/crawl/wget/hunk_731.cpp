     }
 #ifdef SYSTEM_WGETRC
   printf ("%s (system)\n", SYSTEM_WGETRC);
+#else
+  putchar ('\n');
 #endif
 
   format_and_print_line (strdup (locale_title),
 NEWS          |  3 +++
 doc/ChangeLog |  5 +++++
 doc/wget.texi | 13 +++++++++++++
 3 files changed, 21 insertions(+)
