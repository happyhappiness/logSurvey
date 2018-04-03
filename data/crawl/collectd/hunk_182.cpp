   printf ("ok %i - %s evaluates to %d\n", ++check_count__, #actual, expect); \
 } while (0)
 
-#define EXPECT_EQ_UINT64(expect, actual) EXPECT_EQ((expect), (actual), "%"PRIu64)
+#define EXPECT_EQ_UINT64(expect, actual) do { \
+  uint64_t want__ = (uint64_t) expect; \
+  uint64_t got__  = (uint64_t) actual; \
+  if (got__ != want__) { \
+    printf ("not ok %i - %s = %"PRIu64", want %"PRIu64"\n", \
+        ++check_count__, #actual, got__, want__); \
+    return (-1); \
+  } \
+  printf ("ok %i - %s = %"PRIu64"\n", ++check_count__, #actual, got__); \
+} while (0)
 
 #define DBLEQ(expect, actual) do { \
   double e = (expect); double a = (actual); \