         case CLF_COMMON:
             storeAppendPrintf(entry, "%s squid", log->filename);
             break;
-
+#if ICAP_CLIENT
+        case CLF_ICAP_SQUID:
+            storeAppendPrintf(entry, "%s icap_squid", log->filename);
+            break;
+#endif
         case CLF_AUTO:
 
             if (log->aclList)
