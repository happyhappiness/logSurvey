				merge_all();
				continue;
			}
			die("git-merge-index: unknown option %s", arg);
		}
		merge_file(arg);
	}
