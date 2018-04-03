 	idx->name,
 	tvSubDsec(t_start, t_end),
 	(double)1e6*tvSubDsec(t_start, t_end)/idx->count);
+    /* check how long it takes to traverse the hash */
+    gettimeofday(&t_start, NULL);
+    for (hashr = hash_first(idx->hash); hashr; hashr = hash_next(idx->hash)) {
+    }
+    gettimeofday(&t_end, NULL);
+    fprintf(stderr, "%s: hash scan took: %f sec, %f sec/M\n",
+	idx->name,
+	tvSubDsec(t_start, t_end),
+	(double)1e6*tvSubDsec(t_start, t_end)/idx->count);
 }
 
 static int