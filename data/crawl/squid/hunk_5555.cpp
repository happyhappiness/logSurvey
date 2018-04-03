     t = mp.arena + mp.hblkhd;
     storeAppendPrintf(sentry, "\tTotal size:            %6d KB\n",
 	t >> 10);
-#if HAVE_EXT_MALLINFO
+#if HAVE_STRUCT_MALLINFO_MXFAST
     storeAppendPrintf(sentry, "\tmax size of small blocks:\t%d\n", mp.mxfast);
     storeAppendPrintf(sentry, "\tnumber of small blocks in a holding block:\t%d\n",
 	mp.nlblks);
