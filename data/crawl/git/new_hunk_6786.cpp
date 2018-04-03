				unsigned int mode;

				if (i+3 >= argc)
					die("git update-index: --cacheinfo <mode> <sha1> <path>");

				if (strtoul_ui(argv[i+1], 8, &mode) ||
				    get_sha1_hex(argv[i+2], sha1) ||
				    add_cacheinfo(mode, sha1, argv[i+3], 0))
					die("git update-index: --cacheinfo"
					    " cannot add %s", argv[i+3]);
				i += 3;
				continue;
			}
			if (!strcmp(path, "--chmod=-x") ||
			    !strcmp(path, "--chmod=+x")) {
				if (argc <= i+1)
					die("git update-index: %s <path>", path);
				set_executable_bit = path[8];
				continue;
			}
