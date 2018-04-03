		return split_mail_conv(stgit_patch_to_mail, state, paths, keep_cr);
	case PATCH_FORMAT_STGIT_SERIES:
		return split_mail_stgit_series(state, paths, keep_cr);
	default:
		die("BUG: invalid patch_format");
	}
