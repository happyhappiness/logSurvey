 	    else
 		storeAppendPrintf(sentry, "!%s ", d->domain);
 	}
+	storeAppendPrintf(sentry, "\n");
 	storeAppendPrintf(sentry, "Keep-Alive Ratio: %d%%\n",
 	    percent(e->stats.n_keepalives_recv, e->stats.n_keepalives_sent));
     }