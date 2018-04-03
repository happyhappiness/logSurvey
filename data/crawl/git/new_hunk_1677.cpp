	case 7:
		return _("both modified:");
	default:
		die("BUG: unhandled unmerged status %x", stagemask);
	}
}

