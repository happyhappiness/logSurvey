     storeAppendPrintf(e, "</TITLE>\n");
     if (ftpState->flags.use_base)
 	storeAppendPrintf(e, "<BASE HREF=\"%s\">\n",
-	    ftpState->title_url);
+	    ftpState->base_href);
     storeAppendPrintf(e, "</HEAD><BODY>\n");
     if (ftpState->cwd_message) {
 	storeAppendPrintf(e, "<PRE>\n");
