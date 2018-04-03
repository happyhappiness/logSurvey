 
         switch (log->type) {
 
-        case CLF_CUSTOM:
+        case Log::Format::CLF_CUSTOM:
             storeAppendPrintf(entry, "%s %s", log->filename, log->logFormat->name);
             break;
 
-        case CLF_NONE:
+        case Log::Format::CLF_NONE:
             storeAppendPrintf(entry, "none");
             break;
 
-        case CLF_SQUID:
+        case Log::Format::CLF_SQUID:
             storeAppendPrintf(entry, "%s squid", log->filename);
             break;
 
-        case CLF_COMMON:
-            storeAppendPrintf(entry, "%s squid", log->filename);
+        case Log::Format::CLF_COMBINED:
+            storeAppendPrintf(entry, "%s combined", log->filename);
+            break;
+
+        case Log::Format::CLF_COMMON:
+            storeAppendPrintf(entry, "%s common", log->filename);
             break;
+
 #if ICAP_CLIENT
-        case CLF_ICAP_SQUID:
+        case Log::Format::CLF_ICAP_SQUID:
             storeAppendPrintf(entry, "%s icap_squid", log->filename);
             break;
 #endif
-        case CLF_AUTO:
-
-            if (log->aclList)
-                storeAppendPrintf(entry, "%s auto", log->filename);
-            else
-                storeAppendPrintf(entry, "%s", log->filename);
+        case Log::Format::CLF_USERAGENT:
+            storeAppendPrintf(entry, "%s useragent", log->filename);
+            break;
 
+        case Log::Format::CLF_REFERER:
+            storeAppendPrintf(entry, "%s referrer", log->filename);
             break;
 
-        case CLF_UNKNOWN:
+        case Log::Format::CLF_UNKNOWN:
             break;
         }
 
