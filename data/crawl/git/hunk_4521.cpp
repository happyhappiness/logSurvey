 
 	object_ref = argc == 2 ? argv[1] : "HEAD";
 	if (argc > 2)
-		die("too many params");
+		die(_("too many params"));
 
 	if (get_sha1(object_ref, object))
-		die("Failed to resolve '%s' as a valid ref.", object_ref);
+		die(_("Failed to resolve '%s' as a valid ref."), object_ref);
 
 	if (snprintf(ref, sizeof(ref), "refs/tags/%s", tag) > sizeof(ref) - 1)
-		die("tag name too long: %.*s...", 50, tag);
+		die(_("tag name too long: %.*s..."), 50, tag);
 	if (check_ref_format(ref))
-		die("'%s' is not a valid tag name.", tag);
+		die(_("'%s' is not a valid tag name."), tag);
 
 	if (!resolve_ref(ref, prev, 1, NULL))
 		hashclr(prev);
 	else if (!force)
-		die("tag '%s' already exists", tag);
+		die(_("tag '%s' already exists"), tag);
 
 	if (annotate)
 		create_tag(object, tag, &buf, msg.given || msgfile,
 			   sign, prev, object);
 
 	lock = lock_any_ref_for_update(ref, prev, 0);
 	if (!lock)
-		die("%s: cannot lock the ref", ref);
+		die(_("%s: cannot lock the ref"), ref);
 	if (write_ref_sha1(lock, object, NULL) < 0)
-		die("%s: cannot update the ref", ref);
+		die(_("%s: cannot update the ref"), ref);
 	if (force && hashcmp(prev, object))
-		printf("Updated tag '%s' (was %s)\n", tag, find_unique_abbrev(prev, DEFAULT_ABBREV));
+		printf(_("Updated tag '%s' (was %s)\n"), tag, find_unique_abbrev(prev, DEFAULT_ABBREV));
 
 	strbuf_release(&buf);
 	return 0;