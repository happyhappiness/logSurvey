 #include "parse-options.h"
 
 static unsigned long garbage;
+static off_t size_garbage;
 
 static void real_report_garbage(const char *desc, const char *path)
 {
+	struct stat st;
+	if (!stat(path, &st))
+		size_garbage += st.st_size;
 	warning("%s: %s", desc, path);
 	garbage++;
 }
 
 static void count_objects(DIR *d, char *path, int len, int verbose,
 			  unsigned long *loose,
 			  off_t *loose_size,
-			  unsigned long *packed_loose,
-			  unsigned long *garbage)
+			  unsigned long *packed_loose)
 {
 	struct dirent *ent;
 	while ((ent = readdir(d)) != NULL) {
