 	}
 
 	if (!max_candidates)
-		die(_("no tag exactly matches '%s'"), sha1_to_hex(cmit->object.sha1));
+		die(_("no tag exactly matches '%s'"), oid_to_hex(&cmit->object.oid));
 	if (debug)
 		fprintf(stderr, _("searching to describe %s\n"), arg);
 
