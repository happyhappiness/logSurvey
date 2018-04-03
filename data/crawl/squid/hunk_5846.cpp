 #define debug(X...)		/* */
 #endif /* DEBUG */
 #else /* __GNUC__ */
-#define debug(char *format, ...) {}	/* Too lazy to write va_args stuff */
+static void 
+debug(char *format,...)
+{
+}
+
 #endif
 
 
 /* A couple of harmless helper macros */
 #define SEND(X) debug("sending '%s' to squid\n",X); printf(X); printf("\n");
+#ifdef __GNUC__
 #define SEND2(X,Y...) debug("sending '" X "' to squid\n",Y); printf(X,Y);\
          printf("\n");
+#else
+/* no gcc, no debugging. varargs macros are a gcc extension */
+#define SEND2 printf
+#endif
 
 extern int ntlm_errno;
 #define NTLM_NO_ERROR 0
