 			if (opt->status_only)
 				return 1;
 			if (opt->name_only) {
-				show_name(opt, name);
+				show_name(opt, gs->name);
 				return 1;
 			}
 			if (opt->count)
 				goto next_line;
 			if (binary_match_only) {
 				opt->output(opt, "Binary file ", 12);
-				output_color(opt, name, strlen(name),
+				output_color(opt, gs->name, strlen(gs->name),
 					     opt->color_filename);
 				opt->output(opt, " matches\n", 9);
 				return 1;
