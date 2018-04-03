						: "false");
				continue;
			}
			if (!prefixcmp(arg, "--since=")) {
				show_datestring("--max-age=", arg+8);
				continue;
