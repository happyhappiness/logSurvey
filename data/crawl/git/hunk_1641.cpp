 		for (i = 0; i < num_base_list; ++i) {
 			struct commit *base;
 			if (!(base = get_ref(base_list[i], oid_to_hex(base_list[i]))))
-				return error(_("Could not parse object '%s'"),
+				return err(o, _("Could not parse object '%s'"),
 					oid_to_hex(base_list[i]));
 			commit_list_insert(base, &ca);
 		}
