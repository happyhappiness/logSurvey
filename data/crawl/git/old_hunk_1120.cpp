			 *
			 * Also --all and --remotes do not make sense either.
			 */
			die("--reflog is incompatible with --all, --remotes, "
			    "--independent or --merge-base");
	}

	/* If nothing is specified, show all branches by default */
