		status = d->worktree_status;
		break;
	default:
		die("BUG: unhandled change_type %d in wt_longstatus_print_change_data",
		    change_type);
	}

