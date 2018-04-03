			ren2->processed = 1;
			if (strcmp(ren1_dst, ren2_dst) != 0) {
				clean_merge = 0;
				output(o, 1, "CONFLICT (rename/rename): "
				       "Rename \"%s\"->\"%s\" in branch \"%s\" "
				       "rename \"%s\"->\"%s\" in \"%s\"%s",
				       src, ren1_dst, branch1,
