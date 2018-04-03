	case STATUS_FORMAT_PORCELAIN:
		wt_porcelain_print(&s);
		break;
	case STATUS_FORMAT_UNSPECIFIED:
		die("BUG: finalize_deferred_config() should have been called");
		break;
	case STATUS_FORMAT_NONE:
	case STATUS_FORMAT_LONG:
		s.verbose = verbose;
