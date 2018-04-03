	case 7:
		return _("both modified:");
	default:
		die(_("bug: unhandled unmerged status %x"), stagemask);
	}
}

