		}
	}

	for (rm = ref_map; rm; rm = rm->next) {
		if (rm->peer_ref && check_ref_format(rm->peer_ref->name + 5))
			die("* refusing to create funny ref '%s' locally",
			    rm->peer_ref->name);
	}

	if (ref_map)