     qsort((char *) list,
 	i,
 	sizeof(netdbEntry *),
-	(QS) sortByRtt);
+	(QS *) sortByRtt);
     for (k = 0; k < i; k++) {
 	n = *(list + k);
 	storeAppendPrintf(sentry, "{%-16.16s %4d/%4d %7.1f %5.1f",	/* } */
