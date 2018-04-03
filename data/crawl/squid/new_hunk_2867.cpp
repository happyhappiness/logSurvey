SQUIDCEXTERN void storeAppendPrintf(StoreEntry *, const char *,...) PRINTF_FORMAT_ARG2;

/// \ingroup StoreAPI
extern void storeAppendVPrintf(StoreEntry *, const char *, va_list ap);

/// \ingroup StoreAPI
SQUIDCEXTERN int storeTooManyDiskFilesOpen(void);
