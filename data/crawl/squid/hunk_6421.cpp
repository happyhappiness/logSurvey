 	"Operation",
 	"Next Execution");
     while (e != NULL) {
-	storeAppendPrintf(sentry, "%s\t%d seconds\n",
-	    e->name, (int) (e->when - squid_curtime));
+	storeAppendPrintf(sentry, "%s\t%f seconds\n",
+	    e->name, e->when - current_dtime);
 	e = e->next;
     }
 }
