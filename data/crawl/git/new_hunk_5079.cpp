		}

		return o->gently ? -1 :
			error(ERRORMSG(o, ERROR_WOULD_LOSE_UNTRACKED), ce->name, action);
	}
	return 0;
}
