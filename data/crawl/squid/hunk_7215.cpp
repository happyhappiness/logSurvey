 	    continue;
 	if ((++N & 0xFF) == 0) {
 	    getCurrentTime();
-	    debug(18, 3, "stat_objects_get:  Processed %d objects...\n", N);
+	    debug(18, 3) ("stat_objects_get:  Processed %d objects...\n", N);
 	}
 	storeAppendPrintf(sentry, "{%s %dL %-25s %s %3d %2d %8d %s}\n",
 	    describeStatuses(entry),
