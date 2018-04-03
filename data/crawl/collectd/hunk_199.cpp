 #include "utils_parse_option.h"
 
 #define print_to_socket(fh, ...) \
-	if (fprintf (fh, __VA_ARGS__) < 0) { \
-		char errbuf[1024]; \
-		WARNING ("handle_flush: failed to write to socket #%i: %s", \
-				fileno (fh), sstrerror (errno, errbuf, sizeof (errbuf))); \
-		return -1; \
-	} \
-	fflush(fh);
+	do { \
+		if (fprintf (fh, __VA_ARGS__) < 0) { \
+			char errbuf[1024]; \
+			WARNING ("handle_flush: failed to write to socket #%i: %s", \
+					fileno (fh), sstrerror (errno, errbuf, sizeof (errbuf))); \
+			return -1; \
+		} \
+		fflush(fh); \
+	} while (0);
 
 static int add_to_array (char ***array, int *array_num, char *value)
 {
