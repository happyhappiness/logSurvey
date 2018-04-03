 
 std::ostream &
 Debug::getDebugOut() {
-    assert (currentDebug == NULL);
-    currentDebug = new std::ostringstream();
-    return *currentDebug;
+    assert (CurrentDebug == NULL);
+    CurrentDebug = new std::ostringstream();
+    return *CurrentDebug;
 }
 
 void
 Debug::finishDebug() {
-    _db_print("%s\n", currentDebug->str().c_str());
-    delete currentDebug;
-    currentDebug = NULL;
+    _db_print("%s\n", CurrentDebug->str().c_str());
+    delete CurrentDebug;
+    CurrentDebug = NULL;
 }
 
-std::ostringstream *Debug::currentDebug (NULL);
-#
+std::ostringstream *Debug::CurrentDebug (NULL);
