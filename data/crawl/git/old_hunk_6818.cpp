				const char *new_path;
				clean_merge = 0;
				try_merge = 1;
				output(1, "CONFLICT (rename/add): Rename %s->%s in %s. "
				       "%s added in %s",
				       ren1_src, ren1_dst, branch1,
				       ren1_dst, branch2);
				new_path = unique_path(ren1_dst, branch2);
				output(1, "Adding as %s instead", new_path);
				update_file(0, dst_other.sha1, dst_other.mode, new_path);
			} else if ((item = string_list_lookup(ren1_dst, renames2Dst))) {
				ren2 = item->util;
				clean_merge = 0;
				ren2->processed = 1;
				output(1, "CONFLICT (rename/rename): Rename %s->%s in %s. "
				       "Rename %s->%s in %s",
				       ren1_src, ren1_dst, branch1,
				       ren2->pair->one->path, ren2->pair->two->path, branch2);
				conflict_rename_rename_2(ren1, branch1, ren2, branch2);
			} else
				try_merge = 1;

			if (try_merge) {
				struct diff_filespec *o, *a, *b;
				struct merge_file_info mfi;
				src_other.path = (char *)ren1_src;

				o = ren1->pair->one;
				if (a_renames == renames1) {
					a = ren1->pair->two;
					b = &src_other;
				} else {
					b = ren1->pair->two;
					a = &src_other;
				}
				mfi = merge_file(o, a, b,
						a_branch, b_branch);

				if (mfi.clean &&
				    sha_eq(mfi.sha, ren1->pair->two->sha1) &&
