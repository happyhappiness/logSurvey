  * Called when a *new* fs is being setup.
  */
 void
-UfsSwapDir::parse(int anIndex, char *aPath)
+UFSSwapDir::parse (int anIndex, char *aPath)
 {
-    UFSSwapDir::parse (anIndex, aPath);
+    parseSizeL1L2();
 
-    parse_cachedir_options(this, options, 1);
-}
+    index = anIndex;
 
-void
-UFSSwapDir::parse (int anIndex, char *aPath)
-{
-    max_size = GetInteger() << 10;		/* Mbytes to kbytes */
+    path = xstrdup(aPath);
 
-    if (max_size <= 0)
-        fatal("storeAufsDirParse: invalid size value");
+    /* Initialise replacement policy stuff */
+    repl = createRemovalPolicy(Config.replPolicy);
 
-    l1 = GetInteger();
+    parseOptions(0);
+}
 
-    if (l1 <= 0)
-        fatal("storeAufsDirParse: invalid level 1 directories value");
+SwapDirOption *
+UFSSwapDir::getOptionTree() const
+{
+    SwapDirOption *parentResult = SwapDir::getOptionTree();
+    SwapDirOption *ioOptions = IO->getOptionTree();
 
-    l2 = GetInteger();
+    if (!ioOptions)
+        return parentResult;
 
-    if (l2 <= 0)
-        fatal("storeAufsDirParse: invalid level 2 directories value");
+    SwapDirOptionVector *result = new SwapDirOptionVector();
 
-    index = anIndex;
+    result->options.push_back(parentResult);
 
-    path = xstrdup(aPath);
+    result->options.push_back(ioOptions);
 
-    /* Initialise replacement policy stuff */
-    repl = createRemovalPolicy(Config.replPolicy);
+    return result;
 }
 
 /*
