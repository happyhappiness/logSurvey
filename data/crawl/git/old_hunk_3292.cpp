				fprintf(stderr, _("Auto packing the repository for optimum performance.\n"));
			fprintf(stderr, _("See \"git help gc\" for manual housekeeping.\n"));
		}
		if (detach_auto)
			/*
			 * failure to daemonize is ok, we'll continue
			 * in foreground
			 */
			daemonize();
	} else
		add_repack_all_option();

