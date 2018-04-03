 SBuf&
 SBuf::Printf(const char *fmt, ...)
 {
-    // with printf() an arg might be a dangerous char*
+    // with printf() the fmt or an arg might be a dangerous char*
     // NP: cant rely on vappendf() Locker because of clear()
-    Locker prevent_raw_memory_madness(this, buf(), length());
+    const Locker blobKeeper(this, buf());
 
     va_list args;
     va_start(args, fmt);
