 
     for (p = Config.peers; p; p = p->next) {
         storeAppendPrintf(sentry, "%24s %10x %10f %10f %10f\n",
-                          p->name, p->carp.hash,
-                          p->carp.load_multiplier,
-                          p->carp.load_factor,
+                          p->name, p->userhash.hash,
+                          p->userhash.load_multiplier,
+                          p->userhash.load_factor,
                           sumfetches ? (double) p->stats.fetches / sumfetches : -1.0);
     }
 }