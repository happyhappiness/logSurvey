 			break;
 	}
 	if (cf->die_on_error)
-		die(_("bad config file line %d in %s"), cf->linenr, cf->name);
+		die(_("bad config line %d in %s %s"), cf->linenr, cf->origin_type, cf->name);
 	else
-		return error(_("bad config file line %d in %s"), cf->linenr, cf->name);
+		return error(_("bad config line %d in %s %s"), cf->linenr, cf->origin_type, cf->name);
 }
 
 static int parse_unit_factor(const char *end, uintmax_t *val)
