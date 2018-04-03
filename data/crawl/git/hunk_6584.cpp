 					t->tag,
 					diff_get_color_opt(&rev.diffopt, DIFF_RESET));
 			ret = show_object(o->sha1, 1, &rev);
-			objects[i].item = parse_object(t->tagged->sha1);
+			if (ret)
+				break;
+			o = parse_object(t->tagged->sha1);
+			if (!o)
+				ret = error("Could not read object %s",
+					    sha1_to_hex(t->tagged->sha1));
+			objects[i].item = o;
 			i--;
 			break;
 		}
