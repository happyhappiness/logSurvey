 static void
 _db_print_stderr(const char *format, va_list args)
 {
-    if (1 < Debug::level)
+    if (1 < Debug::Level())
         return;
 
     vfprintf(stderr, format, args);
 }
 
-Debug::OutStream *Debug::CurrentDebug(NULL);
+void
+Debug::parseOptions(char const *)
+{}
 
-std::ostream &
-Debug::getDebugOut()
+const char*
+SkipBuildPrefix(const char* path)
 {
-    if (!CurrentDebug) {
-        CurrentDebug = new Debug::OutStream;
-        CurrentDebug->setf(std::ios::fixed);
-        CurrentDebug->precision(2);
-    }
-    return *CurrentDebug;
+    return path;
 }
 
-void
-Debug::parseOptions(char const *)
-{}
+Debug::Context *Debug::Current = nullptr;
 
-void
-Debug::finishDebug()
+Debug::Context::Context(const int aSection, const int aLevel):
+    level(aLevel),
+    sectionLevel(Levels[aSection]),
+    upper(Current)
 {
-    std::cerr << "debugs: " << CurrentDebug->str() << std::endl;
-    delete CurrentDebug;
-    CurrentDebug = NULL;
+    buf.setf(std::ios::fixed);
+    buf.precision(2);
 }
 
-void
-Debug::xassert(const char *msg, const char *file, int line)
+std::ostringstream &
+Debug::Start(const int section, const int level)
 {
-    getDebugOut() << "assertion failed: " << file << ":" << line <<
-                  ": \"" << msg << "\"";
-    abort();
+    Current = new Context(section, level);
+    return Current->buf;
 }
 
-const char*
-SkipBuildPrefix(const char* path)
+void
+Debug::Finish()
 {
-    return path;
+    if (Current) {
+        _db_print("%s\n", Current->buf.str().c_str());
+        delete Current;
+        Current = nullptr;
+    }
 }
 
 std::ostream &
