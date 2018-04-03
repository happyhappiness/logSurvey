 		p->rtt,
 		p->hops);
 	}
+	/* put a new line if no peers */
+	if (!n->n_peers)
+	    storeAppendPrintf(sentry, "\n");
     }
     xfree(list);
 #else
