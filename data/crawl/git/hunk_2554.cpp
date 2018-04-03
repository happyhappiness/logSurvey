 					diff_get_color_opt(&rev.diffopt, DIFF_COMMIT),
 					t->tag,
 					diff_get_color_opt(&rev.diffopt, DIFF_RESET));
-			ret = show_tag_object(o->sha1, &rev);
+			ret = show_tag_object(get_object_hash(*o), &rev);
 			rev.shown_one = 1;
 			if (ret)
 				break;
-			o = parse_object(t->tagged->sha1);
+			o = parse_object(get_object_hash(*t->tagged));
 			if (!o)
 				ret = error(_("Could not read object %s"),
 					    sha1_to_hex(t->tagged->sha1));
