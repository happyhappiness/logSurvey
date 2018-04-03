 dump_cachedir_option_maxsize(StoreEntry * e, const char *option, SwapDir * sd)
 {
     if (sd->max_objsize != -1)
-	storeAppendPrintf(e, " %s=%d", option, sd->max_objsize);
+	storeAppendPrintf(e, " %s=%ld", option, (long int) sd->max_objsize);
 }
 
 void
