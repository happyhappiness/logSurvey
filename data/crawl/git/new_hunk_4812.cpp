			 * it may have been deleted since the index
			 * was loaded!
			 */
			if (!is_pack_valid(p)) {
				error("packfile %s cannot be accessed", p->pack_name);
				goto next;
			}