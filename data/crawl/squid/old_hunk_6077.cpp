	s = "encode";
    else if (var == URI_WHITESPACE_CHOP)
	s = "chop";
    else
	s = "deny";
    storeAppendPrintf(entry, "%s %s\n", name, s);
}

