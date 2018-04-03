			}
			break;
		default:
			die ("Unexpected object of type %s",
			     typename(e->item->type));
		}
		if (commit->util)
			/* more than one name for the same object */