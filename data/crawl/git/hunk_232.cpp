  */
 #define PATHSPEC_LITERAL_PATH (1<<6)
 
+/*
+ * Given command line arguments and a prefix, convert the input to
+ * pathspec. die() if any magic in magic_mask is used.
+ *
+ * Any arguments used are copied. It is safe for the caller to modify
+ * or free 'prefix' and 'args' after calling this function.
+ */
 extern void parse_pathspec(struct pathspec *pathspec,
 			   unsigned magic_mask,
 			   unsigned flags,