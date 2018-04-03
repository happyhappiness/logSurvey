			}
			if (quiet)
				continue;
			show_file(needs_update_fmt, ce->name, in_porcelain, &first, header_msg);
			has_errors = 1;
			continue;
		}
