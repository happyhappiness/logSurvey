 					diff_get_color_opt(&rev.diffopt, DIFF_COMMIT),
 					t->tag,
 					diff_get_color_opt(&rev.diffopt, DIFF_RESET));
-			ret = show_tag_object(get_object_hash(*o), &rev);
+			ret = show_tag_object(o->oid.hash, &rev);
 			rev.shown_one = 1;
 			if (ret)
 				break;
-			o = parse_object(get_object_hash(*t->tagged));
+			o = parse_object(t->tagged->oid.hash);
 			if (!o)
 				ret = error(_("Could not read object %s"),
 					    oid_to_hex(&t->tagged->oid));
