 	unsigned int kind;
 
 	if (flag & REF_BAD_NAME) {
-		warning("ignoring ref with broken name %s", refname);
+		warning(_("ignoring ref with broken name %s"), refname);
 		return 0;
 	}
 
 	if (flag & REF_ISBROKEN) {
-		warning("ignoring broken ref %s", refname);
+		warning(_("ignoring broken ref %s"), refname);
 		return 0;
 	}
 