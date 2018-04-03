	s = "encode";
    else if (var == URI_WHITESPACE_CHOP)
	s = "chop";
    else if (var == URI_WHITESPACE_DENY)
	s = "deny";
    else
	s = "strip";
    storeAppendPrintf(entry, "%s %s\n", name, s);
}

