				       "%s added in %s",
				       ren1_src, ren1_dst, branch1,
				       ren1_dst, branch2);
				new_path = unique_path(o, ren1_dst, branch2);
				output(o, 1, "Adding as %s instead", new_path);
				update_file(o, 0, dst_other.sha1, dst_other.mode, new_path);
			} else if ((item = string_list_lookup(ren1_dst, renames2Dst))) {
				ren2 = item->util;
				clean_merge = 0;
