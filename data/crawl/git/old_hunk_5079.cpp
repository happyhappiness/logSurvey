		}

		return o->gently ? -1 :
			error(ERRORMSG(o, would_lose_untracked), ce->name, action);
	}
	return 0;
}
