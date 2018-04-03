 		o->call_depth--;
 
 		if (!merged_common_ancestors)
-			return error(_("merge returned no commit"));
+			return err(o, _("merge returned no commit"));
 	}
 
 	discard_cache();
