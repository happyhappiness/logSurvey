 			strcat(tag, refs[i]);
 			ref = tag;
 		}
+		if (!strcmp("HEAD", ref)) {
+			unsigned char sha1_dummy[20];
+			ref = resolve_ref(ref, sha1_dummy, 1, NULL);
+			if (!ref)
+				die("HEAD cannot be resolved.");
+			if (prefixcmp(ref, "refs/heads/"))
+				die("HEAD cannot be resolved to branch.");
+			ref = xstrdup(ref + 11);
+		}
 		add_refspec(ref);
 	}
 }
