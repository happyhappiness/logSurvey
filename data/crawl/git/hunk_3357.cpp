 
 #define INDEX_FORMAT_DEFAULT 3
 
+static unsigned int get_index_format_default(void)
+{
+	char *envversion = getenv("GIT_INDEX_VERSION");
+	if (!envversion) {
+		return INDEX_FORMAT_DEFAULT;
+	} else {
+		char *endp;
+		unsigned int version = strtoul(envversion, &endp, 10);
+
+		if (*endp ||
+		    version < INDEX_FORMAT_LB || INDEX_FORMAT_UB < version) {
+			warning(_("GIT_INDEX_VERSION set, but the value is invalid.\n"
+				  "Using version %i"), INDEX_FORMAT_DEFAULT);
+			version = INDEX_FORMAT_DEFAULT;
+		}
+		return version;
+	}
+}
+
 /*
  * dev/ino/uid/gid/size are also just tracked to the low 32 bits
  * Again - this is just a (very strong in practice) heuristic that
