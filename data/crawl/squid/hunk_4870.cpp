     callback (callbackData, writeBuffer);
     PROF_stop(MemObject_write);
 }
+
+void
+MemObject::replaceHttpReply(HttpReply *newrep)
+{
+    fatal ("Not implemented");
+}
