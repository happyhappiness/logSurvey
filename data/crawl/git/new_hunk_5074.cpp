		}

		return o->gently ? -1 :
			add_rejected_path(o, error_type, ce->name);
	}
	return 0;
}
