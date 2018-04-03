 			int len;
 			len = readlink(template, lnk, sizeof(lnk));
 			if (len < 0)
-				die_errno("cannot readlink '%s'", template);
+				die_errno(_("cannot readlink '%s'"), template);
 			if (sizeof(lnk) <= len)
-				die("insanely long symlink %s", template);
+				die(_("insanely long symlink %s"), template);
 			lnk[len] = 0;
 			if (symlink(lnk, path))
-				die_errno("cannot symlink '%s' '%s'", lnk, path);
+				die_errno(_("cannot symlink '%s' '%s'"), lnk, path);
 		}
 		else if (S_ISREG(st_template.st_mode)) {
 			if (copy_file(path, template, st_template.st_mode))
-				die_errno("cannot copy '%s' to '%s'", template,
+				die_errno(_("cannot copy '%s' to '%s'"), template,
 					  path);
 		}
 		else
-			error("ignoring template %s", template);
+			error(_("ignoring template %s"), template);
 	}
 }
 
