 	} else {
 		name = find_name(first, NULL, p_value, TERM_SPACE | TERM_TAB);
 		name = find_name(second, name, p_value, TERM_SPACE | TERM_TAB);
-		patch->old_name = patch->new_name = name;
+		if (has_epoch_timestamp(first)) {
+			patch->is_new = 1;
+			patch->is_delete = 0;
+			patch->new_name = name;
+		} else if (has_epoch_timestamp(second)) {
+			patch->is_new = 0;
+			patch->is_delete = 1;
+			patch->old_name = name;
+		} else {
+			patch->old_name = patch->new_name = name;
+		}
 	}
 	if (!name)
 		die("unable to find filename in patch at line %d", linenr);
