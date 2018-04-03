		}

		return o->gently ? -1 :
			error("Untracked working tree file '%s' "
			      "would be %s by merge.", ce->name, action);
	}
	return 0;
}
