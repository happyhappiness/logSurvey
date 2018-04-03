			if (supported_capabilities)
				*supported_capabilities |= capabilities[i].flag;
		} else {
			warning("external filter requested unsupported filter capability '%s'",
				p);
		}
	}
