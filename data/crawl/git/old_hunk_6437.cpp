				printf("    %s\n", states.heads.items[i].string);
		}

		for (i = 0; i < branch_list.nr; i++) {
			struct string_list_item *branch = branch_list.items + i;
			struct branch_info *info = branch->util;
			int j;

			if (!info->merge.nr || strcmp(*argv, info->remote_name))
				continue;
			printf("  Remote branch%s merged with 'git pull' "
				"while on branch %s\n   ",
				info->merge.nr > 1 ? "es" : "",
				branch->string);
			for (j = 0; j < info->merge.nr; j++)
				printf(" %s", info->merge.items[j].string);
			printf("\n");
		}

		if (!no_query) {
			show_list("  New remote branch%s (next fetch "
				"will store in remotes/%s)",
				&states.new, states.remote->name);
			show_list("  Stale tracking branch%s (use 'git remote "
				"prune')", &states.stale, "");
		}

		show_list("  Tracked remote branch%s", &states.tracked, "");

		if (states.remote->push_refspec_nr) {
			printf("  Local branch%s pushed with 'git push'\n",
				states.remote->push_refspec_nr > 1 ?
