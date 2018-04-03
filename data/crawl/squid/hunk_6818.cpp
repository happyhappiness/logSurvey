 {
     http_server_cc_t i;
     http_hdr_misc_t j;
-    storeAppendPrintf(entry, open_bracket);
-    storeAppendPrintf(entry, "{HTTP Reply Headers:}\n");
-    storeAppendPrintf(entry, "{       Headers parsed: %d}\n",
+    storeAppendPrintf(entry, "HTTP Reply Headers:\n");
+    storeAppendPrintf(entry, "       Headers parsed: %d\n",
 	ReplyHeaderStats.parsed);
     for (j = HDR_AGE; j < HDR_MISC_END; j++)
-	storeAppendPrintf(entry, "{%21.21s: %d}\n",
+	storeAppendPrintf(entry, "%21.21s: %d\n",
 	    HttpHdrMiscStr[j],
 	    ReplyHeaderStats.misc[j]);
     for (i = SCC_PUBLIC; i < SCC_ENUM_END; i++)
-	storeAppendPrintf(entry, "{Cache-Control %s: %d}\n",
+	storeAppendPrintf(entry, "Cache-Control %s: %d\n",
 	    HttpServerCCStr[i],
 	    ReplyHeaderStats.cc[i]);
-    storeAppendPrintf(entry, close_bracket);
 }
 
 static void
