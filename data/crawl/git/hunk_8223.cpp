 
 int remote_find_tracking(struct remote *remote, struct refspec *refspec)
 {
+	int find_src = refspec->src == NULL;
+	char *needle, **result;
 	int i;
+
+	if (find_src) {
+		if (refspec->dst == NULL)
+			return error("find_tracking: need either src or dst");
+		needle = refspec->dst;
+		result = &refspec->src;
+	} else {
+		needle = refspec->src;
+		result = &refspec->dst;
+	}
+
 	for (i = 0; i < remote->fetch_refspec_nr; i++) {
 		struct refspec *fetch = &remote->fetch[i];
+		const char *key = find_src ? fetch->dst : fetch->src;
+		const char *value = find_src ? fetch->src : fetch->dst;
 		if (!fetch->dst)
 			continue;
 		if (fetch->pattern) {
-			if (!prefixcmp(refspec->src, fetch->src)) {
-				refspec->dst =
-					xmalloc(strlen(fetch->dst) +
-						strlen(refspec->src) -
-						strlen(fetch->src) + 1);
-				strcpy(refspec->dst, fetch->dst);
-				strcpy(refspec->dst + strlen(fetch->dst),
-				       refspec->src + strlen(fetch->src));
-				refspec->force = fetch->force;
-				return 0;
-			}
-		} else {
-			if (!strcmp(refspec->src, fetch->src)) {
-				refspec->dst = xstrdup(fetch->dst);
+			if (!prefixcmp(needle, key)) {
+				*result = xmalloc(strlen(value) +
+						  strlen(needle) -
+						  strlen(key) + 1);
+				strcpy(*result, value);
+				strcpy(*result + strlen(value),
+				       needle + strlen(key));
 				refspec->force = fetch->force;
 				return 0;
 			}
+		} else if (!strcmp(needle, key)) {
+			*result = xstrdup(value);
+			refspec->force = fetch->force;
+			return 0;
 		}
 	}
-	refspec->dst = NULL;
 	return -1;
 }
 
