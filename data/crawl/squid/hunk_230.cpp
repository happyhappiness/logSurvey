     return Ctx_Descrs[ctx] ? Ctx_Descrs[ctx] : "<null>";
 }
 
-int Debug::TheDepth = 0;
+Debug::Context *Debug::Current = nullptr;
 
-Debug::OutStream *Debug::CurrentDebug(NULL);
+Debug::Context::Context(const int aSection, const int aLevel):
+    level(aLevel),
+    sectionLevel(Levels[aSection]),
+    upper(Current)
+{
+    formatStream();
+}
 
-std::ostream &
-Debug::getDebugOut()
+/// Optimization: avoids new Context creation for every debugs().
+void
+Debug::Context::rewind(const int aSection, const int aLevel)
 {
-    assert(TheDepth >= 0);
-    ++TheDepth;
-    if (TheDepth > 1) {
-        assert(CurrentDebug);
-        *CurrentDebug << std::endl << "reentrant debuging " << TheDepth << "-{";
-    } else {
-        assert(!CurrentDebug);
-        CurrentDebug = new Debug::OutStream;
-        // set default formatting flags
-        CurrentDebug->setf(std::ios::fixed);
-        CurrentDebug->precision(2);
-    }
-    return *CurrentDebug;
+    level = aLevel;
+    sectionLevel = Levels[aSection];
+    assert(upper == Current);
+
+    buf.str(std::string());
+    buf.clear();
+    // debugs() users are supposed to preserve format, but
+    // some do not, so we have to waste cycles resetting it for all.
+    formatStream();
 }
 
+/// configures default formatting for the debugging stream
 void
-Debug::finishDebug()
+Debug::Context::formatStream()
+{
+    const static std::ostringstream cleanStream;
+    buf.flags(cleanStream.flags() | std::ios::fixed);
+    buf.width(cleanStream.width());
+    buf.precision(2);
+    buf.fill(' ');
+    // If this is not enough, use copyfmt(cleanStream) which is ~10% slower.
+}
+
+std::ostringstream &
+Debug::Start(const int section, const int level)
 {
-    assert(TheDepth >= 0);
-    assert(CurrentDebug);
-    if (TheDepth > 1) {
-        *CurrentDebug << "}-" << TheDepth << std::endl;
+    Context *future = nullptr;
+
+    // prepare future context
+    if (Current) {
+        // all reentrant debugs() calls get here; create a dedicated context
+        future = new Context(section, level);
     } else {
-        assert(TheDepth == 1);
-        _db_print("%s\n", CurrentDebug->str().c_str());
-        delete CurrentDebug;
-        CurrentDebug = NULL;
+        // Optimization: Nearly all debugs() calls get here; avoid allocations
+        static Context *topContext = new Context(1, 1);
+        topContext->rewind(section, level);
+        future = topContext;
     }
-    --TheDepth;
+
+    Current = future;
+
+    return future->buf;
 }
 
-// Hack: replaces global ::xassert() to debug debugging assertions
-// Relies on assert macro calling xassert() without a specific scope.
 void
-Debug::xassert(const char *msg, const char *file, int line)
+Debug::Finish()
 {
-
-    if (CurrentDebug) {
-        *CurrentDebug << "assertion failed: " << file << ":" << line <<
-                      ": \"" << msg << "\"";
-    }
-    abort();
+    // TODO: Optimize to remove at least one extra copy.
+    _db_print("%s\n", Current->buf.str().c_str());
+
+    Context *past = Current;
+    Current = past->upper;
+    if (Current)
+        delete past;
+    // else it was a static topContext from Debug::Start()
 }
 
 size_t
