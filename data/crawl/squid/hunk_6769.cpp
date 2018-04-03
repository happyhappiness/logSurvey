 #define debug(SECTION, LEVEL) \
         ((LEVEL) > debugLevels[SECTION]) ? (void) 0 : _db_print
 #endif
+
+/* useful for temporary debuging messages, delete it later @?@ */
+#define here __FILE__,__LINE__
+#define dev_null 1 ? ((void)0) : 
+#ifdef HAVE_SYSLOG
+#define tmp_debug(fl) _db_level = 0, dev_null _db_print("%s:%d: ",fl), dev_null _db_print
+#else
+#define tmp_debug(fl) _dev_null db_print("%s[%d]: ",fl), dev_null _db_print
+#endif
+
 #define safe_free(x)	if (x) { xxfree(x); x = NULL; }
 
 #define DISK_OK                   (0)
