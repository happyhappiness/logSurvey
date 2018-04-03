 	GIT_COLOR_RED,    /* WT_STATUS_UNMERGED */
 };
 
-static int parse_status_slot(const char *var, int offset)
-{
-	if (!strcasecmp(var+offset, "header"))
-		return WT_STATUS_HEADER;
-	if (!strcasecmp(var+offset, "updated")
-		|| !strcasecmp(var+offset, "added"))
-		return WT_STATUS_UPDATED;
-	if (!strcasecmp(var+offset, "changed"))
-		return WT_STATUS_CHANGED;
-	if (!strcasecmp(var+offset, "untracked"))
-		return WT_STATUS_UNTRACKED;
-	if (!strcasecmp(var+offset, "nobranch"))
-		return WT_STATUS_NOBRANCH;
-	if (!strcasecmp(var+offset, "unmerged"))
-		return WT_STATUS_UNMERGED;
-	die("bad config variable '%s'", var);
-}
-
 static const char *color(int slot, struct wt_status *s)
 {
 	return s->use_color > 0 ? s->color_palette[slot] : "";
