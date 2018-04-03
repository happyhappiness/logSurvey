		}
		refs[j] = NULL;
		ref_nr = j;
	}

	signal(SIGINT, unlock_pack_on_signal);