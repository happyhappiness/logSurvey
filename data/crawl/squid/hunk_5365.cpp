     double f;
     int *D = (int *)xcalloc(A->capacity, sizeof(int));
     assert(A->capacity == B->capacity);
+
     for (i = 0; i < A->capacity; i++) {
-	D[i] = B->bins[i] - A->bins[i];
-	assert(D[i] >= 0);
+        D[i] = B->bins[i] - A->bins[i];
+        assert(D[i] >= 0);
     }
+
     for (i = 0; i < A->capacity; i++)
-	s1 += D[i];
+        s1 += D[i];
+
     h = s1 >> 1;
+
     for (i = 0; i < A->capacity; i++) {
-	J = i;
-	b += D[J];
-	if (a <= h && h <= b)
-	    break;
-	I = i;
-	a += D[I];
+        J = i;
+        b += D[J];
+
+        if (a <= h && h <= b)
+            break;
+
+        I = i;
+
+        a += D[I];
     }
+
     xfree(D);
+
     if (s1 == 0)
-	return 0.0;
+        return 0.0;
+
     if (a > h)
-	return 0.0;
+        return 0.0;
+
     if (a >= b)
-	return 0.0;
+        return 0.0;
+
     if (I >= J)
-	return 0.0;
+        return 0.0;
+
     f = (h - a) / (b - a);
+
     K = (int) floor(f * (double) (J - I) + I);
+
     return statHistVal(A, K);
 }
 
 static void
 statHistBinDumper(StoreEntry * sentry, int idx, double val, double size, int count)
 {
     if (count)
-	storeAppendPrintf(sentry, "\t%3d/%f\t%d\t%f\n",
-	    idx, val, count, count / size);
+        storeAppendPrintf(sentry, "\t%3d/%f\t%d\t%f\n",
+                          idx, val, count, count / size);
 }
 
 void
 statHistDump(const StatHist * H, StoreEntry * sentry, StatHistBinDumper * bd)
 {
     int i;
     double left_border = H->min;
+
     if (!bd)
-	bd = statHistBinDumper;
+        bd = statHistBinDumper;
+
     for (i = 0; i < H->capacity; i++) {
-	const double right_border = statHistVal(H, i + 1);
-	assert(right_border - left_border > 0.0);
-	bd(sentry, i, left_border, right_border - left_border, H->bins[i]);
-	left_border = right_border;
+        const double right_border = statHistVal(H, i + 1);
+        assert(right_border - left_border > 0.0);
+        bd(sentry, i, left_border, right_border - left_border, H->bins[i]);
+        left_border = right_border;
     }
 }
 
