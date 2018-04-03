     storeAppendPrintf(sentry, "\tCache Hits:           %8.5f %8.5f\n",
 	statMedianSvc(5, MEDIAN_HIT) / 1000.0,
 	statMedianSvc(60, MEDIAN_HIT) / 1000.0);
+    storeAppendPrintf(sentry, "\tNear Hits:            %8.5f %8.5f\n",
+	statMedianSvc(5, MEDIAN_NH) / 1000.0,
+	statMedianSvc(60, MEDIAN_NH) / 1000.0);
     storeAppendPrintf(sentry, "\tNot-Modified Replies: %8.5f %8.5f\n",
 	statMedianSvc(5, MEDIAN_NM) / 1000.0,
 	statMedianSvc(60, MEDIAN_NM) / 1000.0);
