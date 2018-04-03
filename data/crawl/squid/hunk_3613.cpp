     return (os << (int)d);
 }
 
+/* Legacy debug style. Still used in some places. needs to die... */
+#define do_debug(SECTION, LEVEL) ((Debug::level = (LEVEL)) > Debug::Levels[SECTION])
+#define old_debug(SECTION, LEVEL) \
+        do_debug(SECTION, LEVEL) ? (void) 0 : _db_print
+
+
 #endif /* SQUID_DEBUG_H */
