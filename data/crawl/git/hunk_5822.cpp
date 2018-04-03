 		memcpy(template + template_baselen, de->d_name, namelen+1);
 		if (lstat(path, &st_git)) {
 			if (errno != ENOENT)
-				die("cannot stat %s", path);
+				die_errno("cannot stat '%s'", path);
 		}
 		else
 			exists = 1;
 
 		if (lstat(template, &st_template))
-			die("cannot stat template %s", template);
+			die_errno("cannot stat template '%s'", template);
 
 		if (S_ISDIR(st_template.st_mode)) {
 			DIR *subdir = opendir(template);
 			int baselen_sub = baselen + namelen;
 			int template_baselen_sub = template_baselen + namelen;
 			if (!subdir)
-				die("cannot opendir %s", template);
+				die_errno("cannot opendir '%s'", template);
 			path[baselen_sub++] =
 				template[template_baselen_sub++] = '/';
 			path[baselen_sub] =
