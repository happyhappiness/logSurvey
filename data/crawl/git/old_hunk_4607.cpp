		if (!current_branch || !current_branch->merge
					|| !current_branch->merge[0]
					|| !current_branch->merge[0]->dst) {
			fprintf(stderr, "Could not find a tracked"
					" remote branch, please"
					" specify <upstream> manually.\n");
			usage_with_options(cherry_usage, options);
		}

