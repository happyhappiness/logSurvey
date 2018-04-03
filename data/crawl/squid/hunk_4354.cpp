     fatal(message);
 }
 
+int Debug::TheDepth = 0;
+
 std::ostream &
 Debug::getDebugOut() {
-    assert (CurrentDebug == NULL);
-    CurrentDebug = new std::ostringstream();
+    assert(TheDepth >= 0);
+    ++TheDepth;
+    if (TheDepth > 1) {
+        assert(CurrentDebug);
+        *CurrentDebug << std::endl << "reentrant debuging " << TheDepth << "-{";
+    } else {
+        assert(!CurrentDebug);
+        CurrentDebug = new std::ostringstream();
+        // set default formatting flags
+        CurrentDebug->setf(std::ios::fixed);
+        CurrentDebug->precision(2);
+    }
     return *CurrentDebug;
 }
 
 void
 Debug::finishDebug() {
-    _db_print("%s\n", CurrentDebug->str().c_str());
-    delete CurrentDebug;
-    CurrentDebug = NULL;
+    assert(TheDepth >= 0);
+    assert(CurrentDebug);
+    if (TheDepth > 1) {
+        *CurrentDebug << "}-" << TheDepth << std::endl;
+    } else {
+        assert(TheDepth == 1);
+        _db_print("%s\n", CurrentDebug->str().c_str());
+        delete CurrentDebug;
+        CurrentDebug = NULL;
+    }
+    --TheDepth;
+}
+
+void
+Debug::xassert(const char *msg, const char *file, int line) {
+	
+    if (CurrentDebug) {
+        *CurrentDebug << "assertion failed: " << file << ":" << line <<
+            ": \"" << msg << "\"";
+    }
+    abort();
 }
 
 std::ostringstream *Debug::CurrentDebug (NULL);