			continue;
		}

		if (!dwim_ref(argv[i], spec - argv[i], sha1, &ref)) {
			status |= error("%s points nowhere!", argv[i]);
			continue;
		}

