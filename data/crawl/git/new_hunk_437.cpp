	}

	if (show_stats) {
		printf("num read blob: %d\n", sb.num_read_blob);
		printf("num get patch: %d\n", sb.num_get_patch);
		printf("num commits: %d\n", sb.num_commits);
	}
	return 0;
}