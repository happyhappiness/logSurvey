     basevar = (type *)xrealloc (basevar, DR_newsize * sizeof (type));	\
 } while (0)
 
+/* Used to print pointers (usually for debugging).  Print pointers
+   using printf ("%0*lx", PTR_FORMAT (p)).  (%p is too unpredictable;
+   some implementations prepend 0x, while some don't, and most don't
+   0-pad the address.)  */
+#define PTR_FORMAT(p) 2 * sizeof (void *), (unsigned long) (p)
+
 extern const char *exec_name;
 
 /* Document type ("dt") flags */
