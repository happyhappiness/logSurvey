 } while (0)
 #define OK(cond) OK1(cond, #cond)
 
-#define STREQ(expect, actual) do { \
+#define EXPECT_EQ_STR(expect, actual) do { \
   if (strcmp (expect, actual) != 0) { \
-    printf ("not ok %i - %s incorrect: expected \"%s\", got \"%s\"\n", \
-        ++check_count__, #actual, expect, actual); \
+    printf ("not ok %i - %s = \"%s\", want \"%s\"\n", \
+        ++check_count__, #actual, actual, expect); \
     return (-1); \
   } \
-  printf ("ok %i - %s evaluates to \"%s\"\n", ++check_count__, #actual, expect); \
+  printf ("ok %i - %s = \"%s\"\n", ++check_count__, #actual, actual); \
 } while (0)
 
-#define EXPECT_EQ(expect, actual, format) do { \
-  if ((expect) != (actual)) {\
-    printf ("not ok %i - %s incorrect: expected " format ", got " format "\n", \
-        ++check_count__, #actual, expect, actual); \
-    return (-1); \
-  } \
-  printf ("ok %i - %s evaluates to " format "\n", ++check_count__, #actual, expect); \
-} while (0)
-
-#define EXPECT_INTEQ(expect, actual) do { \
-  if ((expect) != (actual)) {\
-    printf ("not ok %i - %s incorrect: expected %d, got %d\n", \
-        ++check_count__, #actual, expect, actual); \
+#define EXPECT_EQ_INT(expect, actual) do { \
+  int want__ = (int) expect; \
+  int got__  = (int) actual; \
+  if (got__ != want__) { \
+    printf ("not ok %i - %s = %d, want %d\n", \
+        ++check_count__, #actual, got__, want__); \
     return (-1); \
   } \
-  printf ("ok %i - %s evaluates to %d\n", ++check_count__, #actual, expect); \
+  printf ("ok %i - %s = %d\n", ++check_count__, #actual, got__); \
 } while (0)
 
 #define EXPECT_EQ_UINT64(expect, actual) do { \
