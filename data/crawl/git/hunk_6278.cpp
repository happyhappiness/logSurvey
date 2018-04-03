 		const char *name = used_atom[i];
 		struct atom_value *v = &ref->value[i];
 		int deref = 0;
+		const char *refname;
+		const char *formatp;
+
 		if (*name == '*') {
 			deref = 1;
 			name++;
 		}
-		if (!prefixcmp(name, "refname")) {
-			const char *formatp = strchr(name, ':');
-			const char *refname = ref->refname;
-
-			/* look for "short" refname format */
-			if (formatp) {
-				formatp++;
-				if (!strcmp(formatp, "short"))
-					refname = get_short_ref(ref->refname);
-				else
-					die("unknown refname format %s",
-					    formatp);
-			}
 
-			if (!deref)
-				v->s = refname;
-			else {
-				int len = strlen(refname);
-				char *s = xmalloc(len + 4);
-				sprintf(s, "%s^{}", refname);
-				v->s = s;
-			}
+		if (!prefixcmp(name, "refname"))
+			refname = ref->refname;
+		else
+			continue;
+
+		formatp = strchr(name, ':');
+		/* look for "short" refname format */
+		if (formatp) {
+			formatp++;
+			if (!strcmp(formatp, "short"))
+				refname = get_short_ref(refname);
+			else
+				die("unknown %.*s format %s",
+				    (int)(formatp - name), name, formatp);
+		}
+
+		if (!deref)
+			v->s = refname;
+		else {
+			int len = strlen(refname);
+			char *s = xmalloc(len + 4);
+			sprintf(s, "%s^{}", refname);
+			v->s = s;
 		}
 	}
 