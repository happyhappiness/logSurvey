				return 0;
		}

		return error("Untracked working tree file '%s' "
			     "would be %s by merge.", ce->name, action);
	}
	return 0;
}
