			fprintf(stderr, _("See \"git help gc\" for manual housekeeping.\n"));
		}
		if (detach_auto) {
			if (gc_before_repack())
				return -1;
			/*
			 * failure to daemonize is ok, we'll continue
			 * in foreground
			 */
			daemonize();
		}
	} else
		add_repack_all_option();
