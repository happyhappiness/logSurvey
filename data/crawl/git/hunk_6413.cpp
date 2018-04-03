 static int match_name_with_pattern(const char *key, const char *name,
 				   const char *value, char **result)
 {
-	size_t klen = strlen(key);
-	int ret = !strncmp(key, name, klen);
+	const char *kstar = strchr(key, '*');
+	size_t klen;
+	int ret;
+	if (!kstar)
+		die("Key '%s' of pattern had no '*'", key);
+	klen = kstar - key;
+	ret = !strncmp(key, name, klen);
 	if (ret && value) {
-		size_t vlen = strlen(value);
+		const char *vstar = strchr(value, '*');
+		size_t vlen;
+		if (!vstar)
+			die("Value '%s' of pattern has no '*'", value);
+		vlen = vstar - value;
 		*result = xmalloc(vlen +
 				  strlen(name) -
 				  klen + 1);