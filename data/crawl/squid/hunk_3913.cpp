 /// \ingroup StoreAPI
 SQUIDCEXTERN int expiresMoreThan(time_t, time_t);
 
-#if STDC_HEADERS
 /// \ingroup StoreAPI
 SQUIDCEXTERN void storeAppendPrintf(StoreEntry *, const char *,...) PRINTF_FORMAT_ARG2;
-#else
-/// \ingroup StoreAPI
-SQUIDCEXTERN void storeAppendPrintf();
-#endif
 
 /// \ingroup StoreAPI
 SQUIDCEXTERN void storeAppendVPrintf(StoreEntry *, const char *, va_list ap);
