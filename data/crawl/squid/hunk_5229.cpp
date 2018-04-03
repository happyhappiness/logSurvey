     debug (0,0) ("Fatal: %s",message);
     exit (1);
 }
+
+std::ostream &
+Debug::getDebugOut()
+{
+    assert (currentDebug == NULL);
+    currentDebug = new std::ostringstream();
+    return *currentDebug;
+}
+
+void
+Debug::finishDebug()
+{
+    _db_print("%s\n", currentDebug->str().c_str());
+    delete currentDebug;
+    currentDebug = NULL;
+}
+
+std::ostringstream *Debug::currentDebug (NULL);