 
 #ifdef XMALLOC_STATISTICS
 static void
-info_get_mallstat(int size, int number, void *data)
+info_get_mallstat(int size, int number, int oldnum, void *data)
 {
     StoreEntry *sentry = data;
     if (number > 0)
-	storeAppendPrintf(sentry, "\t%d = %d\n", size, number);
+	storeAppendPrintf(sentry, "%d\t %d\t %d\t %.1f\n", size, number, number - oldnum , xdiv((number - oldnum),xm_deltat));
 }
 #endif
 
