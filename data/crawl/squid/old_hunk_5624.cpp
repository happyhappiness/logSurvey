    return cachable;
}

static void
gopherEndHTML(GopherStateData * gopherState)
{
    if (!gopherState->data_in)
	storeAppendPrintf(gopherState->entry,
	    "<HTML><HEAD><TITLE>Server Return Nothing.</TITLE>\n"
	    "</HEAD><BODY><HR><H1>Server Return Nothing.</H1></BODY></HTML>\n");
}


