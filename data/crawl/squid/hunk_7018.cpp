 	    storeAppendPrintf(sentry, "\t\tswapin_fd: %d\n",
 		(int) sc->swapin_fd);
 	}
-#endif
     }
-#if OLD_CODE
-    storeAppendPrintf(sentry, close_bracket);
-#endif
 }
 
 void