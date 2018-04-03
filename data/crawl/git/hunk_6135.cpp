 static int parse_branch_color_slot(const char *var, int ofs)
 {
 	if (!strcasecmp(var+ofs, "plain"))
-		return COLOR_BRANCH_PLAIN;
+		return BRANCH_COLOR_PLAIN;
 	if (!strcasecmp(var+ofs, "reset"))
-		return COLOR_BRANCH_RESET;
+		return BRANCH_COLOR_RESET;
 	if (!strcasecmp(var+ofs, "remote"))
-		return COLOR_BRANCH_REMOTE;
+		return BRANCH_COLOR_REMOTE;
 	if (!strcasecmp(var+ofs, "local"))
-		return COLOR_BRANCH_LOCAL;
+		return BRANCH_COLOR_LOCAL;
 	if (!strcasecmp(var+ofs, "current"))
-		return COLOR_BRANCH_CURRENT;
+		return BRANCH_COLOR_CURRENT;
 	die("bad config variable '%s'", var);
 }
 
