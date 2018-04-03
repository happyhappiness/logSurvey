 max %u in one bucket.\n",
 	      (double) nvariables / (double) set->buckets,
 	      per_bucket);
+#else
+      {
+	int f = (nvariables * 1000 + 5) / set->buckets;
+	printf ("# average of %d.%d variables per bucket, \
+max %u in one bucket.\n",
+	      f/10, f%10,
+	      per_bucket);
+      }
 #endif
     }
 }
