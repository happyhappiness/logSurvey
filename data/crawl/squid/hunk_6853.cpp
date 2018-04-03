     StoreEntry *e = ftpState->entry;
     storeBuffer(e);
     storeAppendPrintf(e, "</PRE>\n");
+    if (EBIT_TEST(ftpState->flags, FTP_LISTFORMAT_UNKNOWN) && !EBIT_TEST(ftpState->flags, FTP_TRIED_NLST)) {
+	storeAppendPrintf(e, "<A HREF=\"./;type=d\">[As plain directory]</A>\n");
+    } else if (ftpState->typecode=='D') {
+	storeAppendPrintf(e, "<A HREF=\"./\">[As extended directory]</A>\n");
+    }
     storeAppendPrintf(e, "<HR>\n");
     storeAppendPrintf(e, "<ADDRESS>\n");
     storeAppendPrintf(e, "Generated %s, by %s/%s@%s\n",
