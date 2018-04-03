 	 */
 	if (opt->count && count) {
 		char buf[32];
-		opt->output(opt, name, strlen(name));
-		snprintf(buf, sizeof(buf), "%c%u\n",
-			 opt->null_following_name ? '\0' : ':', count);
+		output_color(opt, name, strlen(name), opt->color_filename);
+		output_sep(opt, ':');
+		snprintf(buf, sizeof(buf), "%u\n", count);
 		opt->output(opt, buf, strlen(buf));
 	}
 	return !!last_hit;
