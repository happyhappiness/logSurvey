 extern void storeSetMemStatus(StoreEntry * e, int);
 #if STDC_HEADERS
 extern void
-storeAppendPrintf(StoreEntry *, const char *,...) PRINTF_FORMAT_ARG(2);
+storeAppendPrintf(StoreEntry *, const char *,...) PRINTF_FORMAT_ARG2;
 #else
 extern void storeAppendPrintf();
 #endif
