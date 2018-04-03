 	die("bad config variable '%s'", var);
 }
 
-static const char* color(int slot)
+static const char *color(int slot)
 {
 	return wt_status_use_color > 0 ? wt_status_colors[slot] : "";
 }