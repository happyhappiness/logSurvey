 	storeAppendPrintf(sentry, "Flags:");
 	if (SD->flags.selected)
 	    storeAppendPrintf(sentry, " SELECTED");
+	if (SD->flags.read_only)
+	    storeAppendPrintf(sentry, " READ-ONLY");
 	storeAppendPrintf(sentry, "\n");
     }
 }
