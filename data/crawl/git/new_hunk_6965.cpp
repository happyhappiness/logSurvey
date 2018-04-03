			printf("  Remote branch%s merged with 'git pull' "
				"while on branch %s\n   ",
				info->merge.nr > 1 ? "es" : "",
				branch->string);
			for (j = 0; j < info->merge.nr; j++)
				printf(" %s", info->merge.items[j].string);
			printf("\n");
		}

