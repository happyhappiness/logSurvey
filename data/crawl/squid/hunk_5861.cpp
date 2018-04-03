     header[])
 {
     int i;
-    storeAppendPrintf(entry, "%s:", name);
     for (i = 0; i < HDR_ENUM_END; i++) {
 	if (NULL == header[i].replacement)
 	    continue;
-	storeAppendPrintf(entry, "\t%s: %s", httpHeaderNameById(i),
+	storeAppendPrintf(entry, "%s %s %s\n", name, httpHeaderNameById(i),
 	    header[i].replacement);
     }
 }