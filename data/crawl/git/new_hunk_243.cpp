			if (supported_capabilities)
				*supported_capabilities |= capabilities[i].flag;
		} else {
			die("subprocess '%s' requested unsupported capability '%s'",
			    process->argv[0], p);
		}
	}
