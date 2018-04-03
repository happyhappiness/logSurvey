				      "need to pull first?",
				      ref->name,
				      ref->peer_ref->name);
				if (helper_status)
					printf("error %s non-fast forward\n", ref->name);
				rc = -2;
				continue;
			}
