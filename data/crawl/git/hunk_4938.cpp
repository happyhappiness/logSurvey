 			die("failed to concatenate notes "
 			    "(combine_notes_concatenate)");
 		return 0;
+	case NOTES_MERGE_RESOLVE_CAT_SORT_UNIQ:
+		OUTPUT(o, 2, "Concatenating unique lines in local and remote "
+		       "notes for %s", sha1_to_hex(p->obj));
+		if (add_note(t, p->obj, p->remote, combine_notes_cat_sort_uniq))
+			die("failed to concatenate notes "
+			    "(combine_notes_cat_sort_uniq)");
+		return 0;
 	}
 	die("Unknown strategy (%i).", o->strategy);
 }
