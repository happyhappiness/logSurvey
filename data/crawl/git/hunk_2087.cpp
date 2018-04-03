 			path = "kfmclient";
 		strbuf_addf(&man_page, "man:%s(1)", page);
 		execlp(path, filename, "newTab", man_page.buf, (char *)NULL);
-		warning(_("failed to exec '%s': %s"), path, strerror(errno));
+		warning_errno(_("failed to exec '%s'"), path);
 	}
 }
 
