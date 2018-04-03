 StorePointer Store::CurrentRoot = NULL;
 
 extern "C" void
-#if STDC_HEADERS
-    storeAppendPrintf(StoreEntry * e, const char *fmt,...)
-#else
-    storeAppendPrintf(va_alist)
-    va_dcl
-#endif
+storeAppendPrintf(StoreEntry * e, const char *fmt,...)
 {
     fatal("Not implemented");
 }
 
 extern "C" void
-    storeAppendVPrintf(StoreEntry * e, const char *fmt, va_list vargs)
+storeAppendVPrintf(StoreEntry * e, const char *fmt, va_list vargs)
 {
     fatal("Not implemented");
 }
