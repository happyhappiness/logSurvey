			ren2 = lookup->util;
			ren2_dst = ren2->pair->two->path;
			if (strcmp(ren1_dst, ren2_dst) != 0)
				die("BUG: ren1_dst != ren2_dst");

			clean_merge = 0;
			ren2->processed = 1;
