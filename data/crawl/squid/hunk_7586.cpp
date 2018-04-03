 
     debug(20, 3, "storeSwapOutHandle: '%s'\n", e->key);
     if (mem == NULL) {
-	debug(20, 0, "HELP! Someone is swapping out a bad entry:\n");
 	debug(20, 0, "%s\n", storeToString(e));
-	fatal_dump(NULL);
+	debug_trap("Someone is swapping out a bad entry");
 	return;
     }
     e->timestamp = squid_curtime;
