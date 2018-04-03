         switch (log->type) {
 
         case Log::Format::CLF_CUSTOM:
-            storeAppendPrintf(entry, "%s %s", log->filename, log->logFormat->name);
+            storeAppendPrintf(entry, "%s logformat=%s", log->filename, log->logFormat->name);
             break;
 
         case Log::Format::CLF_NONE:
-            storeAppendPrintf(entry, "none");
+            storeAppendPrintf(entry, "logformat=none");
             break;
 
         case Log::Format::CLF_SQUID:
-            storeAppendPrintf(entry, "%s squid", log->filename);
+            storeAppendPrintf(entry, "%s logformat=squid", log->filename);
             break;
 
         case Log::Format::CLF_COMBINED:
-            storeAppendPrintf(entry, "%s combined", log->filename);
+            storeAppendPrintf(entry, "%s logformat=combined", log->filename);
             break;
 
         case Log::Format::CLF_COMMON:
-            storeAppendPrintf(entry, "%s common", log->filename);
+            storeAppendPrintf(entry, "%s logformat=common", log->filename);
             break;
 
 #if ICAP_CLIENT
         case Log::Format::CLF_ICAP_SQUID:
-            storeAppendPrintf(entry, "%s icap_squid", log->filename);
+            storeAppendPrintf(entry, "%s logformat=icap_squid", log->filename);
             break;
 #endif
         case Log::Format::CLF_USERAGENT:
-            storeAppendPrintf(entry, "%s useragent", log->filename);
+            storeAppendPrintf(entry, "%s logformat=useragent", log->filename);
             break;
 
         case Log::Format::CLF_REFERER:
-            storeAppendPrintf(entry, "%s referrer", log->filename);
+            storeAppendPrintf(entry, "%s logformat=referrer", log->filename);
             break;
 
         case Log::Format::CLF_UNKNOWN:
             break;
         }
 
+        // default is on-error=die
+        if (!log->fatal)
+            storeAppendPrintf(entry, " on-error=drop");
+
+        // default: 64KB
+        if (log->bufferSize != 64*1024)
+            storeAppendPrintf(entry, " buffer-size=%d", log->bufferSize);
+
+        if (log->rotateCount >= 0)
+            storeAppendPrintf(entry, " rotate=%d", log->rotateCount);
+
         if (log->aclList)
             dump_acl_list(entry, log->aclList);
 