     while (e != NULL) {
 	storeAppendPrintf(sentry, "%s\t%f seconds\t%d\t%s\n",
 	    e->name, e->when - current_dtime, e->weight,
-	    e->arg ? cbdataValid(e->arg) ? "yes" : "no" : "N/A");
+	    e->arg ? cbdataReferenceValid(e->arg) ? "yes" : "no" : "N/A");
 	e = e->next;
     }
 }
