         fatal("UFSSwapDir::parseSizeL1L2: invalid level 2 directories value");
 }
 
-/*
- * storeUfsDirReconfigure
- *
- * This routine is called when the given swapdir needs reconfiguring
- */
-
 void
-UFSSwapDir::reconfigure()
+Fs::Ufs::UFSSwapDir::reconfigure()
 {
     parseSizeL1L2();
     parseOptions(1);
 }
 
-/*
- * storeUfsDirParse
- *
- * Called when a *new* fs is being setup.
- */
 void
-UFSSwapDir::parse (int anIndex, char *aPath)
+Fs::Ufs::UFSSwapDir::parse (int anIndex, char *aPath)
 {
     index = anIndex;
     path = xstrdup(aPath);
