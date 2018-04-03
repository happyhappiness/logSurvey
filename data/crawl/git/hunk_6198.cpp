 	}
 }
 
-static const char *prettify_ref(const struct ref *ref)
-{
-	const char *name = ref->name;
-	return name + (
-		!prefixcmp(name, "refs/heads/") ? 11 :
-		!prefixcmp(name, "refs/tags/") ? 10 :
-		!prefixcmp(name, "refs/remotes/") ? 13 :
-		0);
-}
-
 #define SUMMARY_WIDTH (2 * DEFAULT_ABBREV + 3)
 
 static void print_ref_status(char flag, const char *summary, struct ref *to, struct ref *from, const char *msg)
