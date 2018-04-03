				 * update_file().
				 */
				update_file_flags(o,
						  ren1->pair->two->oid.hash,
						  ren1->pair->two->mode,
						  ren1_dst,
						  1, /* update_cache */
						  0  /* update_wd    */);
			} else if (!sha_eq(dst_other.oid.hash, null_sha1)) {
				clean_merge = 0;
				try_merge = 1;
				output(o, 1, _("CONFLICT (rename/add): Rename %s->%s in %s. "
