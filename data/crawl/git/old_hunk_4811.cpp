				die("packfile %s cannot be mapped: %s",
					p->pack_name,
					strerror(errno));
			pack_mmap_calls++;
			pack_open_windows++;
			if (pack_mapped > peak_pack_mapped)
