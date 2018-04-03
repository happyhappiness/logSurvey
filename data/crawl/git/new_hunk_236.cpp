						: "false");
				continue;
			}
			if (!strcmp(arg, "--is-shallow-repository")) {
				printf("%s\n", is_repository_shallow() ? "true"
						: "false");
				continue;
			}
			if (!strcmp(arg, "--shared-index-path")) {
				if (read_cache() < 0)
					die(_("Could not read the index"));
