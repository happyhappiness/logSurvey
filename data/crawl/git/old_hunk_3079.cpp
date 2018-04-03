		 */
		exit_if_skipped_commits(tried, NULL);

		printf("%s was both good and bad\n",
		       oid_to_hex(current_bad_oid));
		exit(1);
	}

