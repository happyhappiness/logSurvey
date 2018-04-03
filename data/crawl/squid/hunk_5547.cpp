     while ((hptr = hash_next(htable))) {
 	c = (ptr *) hptr;
 	storeAppendPrintf(sentry, "%20p last used %9d seconds ago by %s:%d\n",
-	    c->key, squid_curtime - c->when, c->file, c->line);
+	    c->key, (int) (squid_curtime - c->when), c->file, c->line);
     }
 }
