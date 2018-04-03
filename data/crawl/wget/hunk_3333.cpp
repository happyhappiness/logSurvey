   DEBUGP (("Closing fd %d\n", x));		\
 } while (0)
 
-/* Define a large ("very long") type useful for storing large
-   non-negative quantities that exceed sizes of normal download.  Note
-   that this has nothing to do with large file support.  For example,
-   one should be able to say `--quota=10G', large files
-   notwithstanding.
-
-   On the machines where `long' is 64-bit, we use long.  Otherwise, we
-   check whether `long long' is available and if yes, use that.  If
-   long long is unavailable, we give up and just use `long'.
-
-   Note: you cannot use VERY_LONG_TYPE along with printf().  When you
-   need to print it, use very_long_to_string().  */
-
-#if SIZEOF_LONG >= 8 || SIZEOF_LONG_LONG == 0
-/* either long is "big enough", or long long is unavailable which
-   leaves long as the only choice. */ 
-# define VERY_LONG_TYPE   unsigned long
-#else  /* use long long */
-/* long is smaller than 8 bytes, but long long is available. */
-# define VERY_LONG_TYPE   unsigned long long
-#endif /* use long long */
+/* Define a large integral type useful for storing large sizes that
+   exceed sizes of one download, such as when printing the sum of all
+   downloads.  Note that this has nothing to do with large file
+   support, yet.
+
+   We use a 64-bit integral type where available, `double' otherwise.
+   It's hard to print LARGE_INT's portably, but fortunately it's
+   rarely needed.  */
+
+#if SIZEOF_LONG >= 8
+/* Long is large enough: use it.  */
+typedef long LARGE_INT;
+# define LARGE_INT_FMT "%ld"
+#else
+# if SIZEOF_LONG_LONG == 8
+/* Long long is large enough: use it.  */
+typedef long long LARGE_INT;
+#  define LARGE_INT_FMT "%lld"
+# else
+/* Use `double'. */
+typedef double LARGE_INT;
+#  define LARGE_INT_FMT "%.0f"
+# endif
+#endif
 
 /* These are defined in cmpt.c if missing, therefore it's generally
    safe to declare their parameters.  */
