					output(3, "Skipped %s (merged same as existing)", ren1_dst);
				else {
					if (mfi.merge || !mfi.clean)
						output(1, "Renaming %s => %s", ren1_src, ren1_dst);
					if (mfi.merge)
						output(2, "Auto-merging %s", ren1_dst);
					if (!mfi.clean) {
						output(1, "CONFLICT (rename/modify): Merge conflict in %s",
						       ren1_dst);
