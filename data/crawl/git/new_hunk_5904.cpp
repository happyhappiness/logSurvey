				fclose(pack_edges);
			pack_edges = fopen(a + 20, "a");
			if (!pack_edges)
				die_errno("Cannot open '%s'", a + 20);
		} else if (!strcmp(a, "--force"))
			force_update = 1;
		else if (!strcmp(a, "--quiet"))