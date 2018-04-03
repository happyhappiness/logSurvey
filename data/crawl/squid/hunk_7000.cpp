 	    storeAppendPrintf(sentry, "\t\tswapin_fd: %d\n",
 		(int) sc->swapin_fd);
 	}
+	BIT_CLR(sentry->flag, DELAY_SENDING);
+	storeAppendPrintf(sentry, "\n");
     }
 }
 
