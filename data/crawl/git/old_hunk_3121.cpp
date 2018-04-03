	return sigc->result != 'G' && sigc->result != 'U';
}

/*
 * Look at GPG signed content (e.g. a signed tag object), whose
 * payload is followed by a detached signature on it.  Return the
