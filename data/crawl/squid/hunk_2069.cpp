 }
 
 void
-UFSSwapDir::optionIODump(StoreEntry * e) const
+Fs::Ufs::UFSSwapDir::optionIODump(StoreEntry * e) const
 {
     storeAppendPrintf(e, " IOEngine=%s", ioType);
 }
 
 ConfigOption *
-UFSSwapDir::getOptionTree() const
+Fs::Ufs::UFSSwapDir::getOptionTree() const
 {
     ConfigOption *parentResult = SwapDir::getOptionTree();
 
