 static int debugLevels[MAX_DEBUG_SECTIONS];
 
 #if defined(__STRICT_ANSI__)
-void _db_print(int section,...)
+void _db_print(int section, int level, char *format...)
 {
     va_list args;
 #else
