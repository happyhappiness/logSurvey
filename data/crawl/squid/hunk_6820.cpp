     for (k = 0; k < (int) i->addrs.count; k++)
 	storeAppendPrintf(sentry, " %15s-%3s", inet_ntoa(i->addrs.in_addrs[k]),
 	    i->addrs.bad_mask[k] ? "BAD" : "OK ");
-    storeAppendPrintf(sentry, close_bracket);
 }
 
 /* process objects list */
