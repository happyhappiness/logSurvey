   printf ("ok %i - %s = %"PRIu64"\n", ++check_count__, #actual, got__); \
 } while (0)
 
-#define DBLEQ(expect, actual) do { \
-  double e = (expect); double a = (actual); \
-  if (isnan (e) && !isnan (a)) { \
-    printf ("not ok %i - %s incorrect: expected %.15g, got %.15g\n", \
-        ++check_count__, #actual, e, a); \
+#define EXPECT_EQ_DOUBLE(expect, actual) do { \
+  double want__ = (double) expect; \
+  double got__  = (double) actual; \
+  if (isnan (want__) && !isnan (got__)) { \
+    printf ("not ok %i - %s = %.15g, want %.15g\n", \
+        ++check_count__, #actual, got__, want__); \
     return (-1); \
-  } else if (!isnan (e) && (((e-a) < -DBL_PRECISION) || ((e-a) > DBL_PRECISION))) { \
-    printf ("not ok %i - %s incorrect: expected %.15g, got %.15g\n", \
-        ++check_count__, #actual, e, a); \
+  } else if (!isnan (want__) && (((want__-got__) < -DBL_PRECISION) || ((want__-got__) > DBL_PRECISION))) { \
+    printf ("not ok %i - %s = %.15g, want %.15g\n", \
+        ++check_count__, #actual, got__, want__); \
     return (-1); \
   } \
-  printf ("ok %i - %s evaluates to %.15g\n", ++check_count__, #actual, e); \
+  printf ("ok %i - %s = %.15g\n", ++check_count__, #actual, got__); \
 } while (0)
 
 #define CHECK_NOT_NULL(expr) do { \
