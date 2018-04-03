 	    (int) f->name_count);
 	for (k = 0; k < (int) f->name_count; k++)
 	    storeAppendPrintf(sentry, " %s", f->names[k]);
-        storeAppendPrintf(sentry, "\n");
+	storeAppendPrintf(sentry, "\n");
     }
 }
 
