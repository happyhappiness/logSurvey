 
 	alias = alias_lookup(cmd);
 	if (alias) {
-		printf_ln(_("`git %s' is aliased to `%s'"), cmd, alias);
+		printf_ln(_("'%s' is aliased to '%s'"), cmd, alias);
 		free(alias);
 		exit(0);
 	}