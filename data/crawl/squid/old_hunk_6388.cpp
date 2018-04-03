static void
gopherEndHTML(GopherStateData * gopherState)
{
    LOCAL_ARRAY(char, tmpbuf, TEMP_BUF_SIZE);

    if (!gopherState->data_in) {
	snprintf(tmpbuf, TEMP_BUF_SIZE,
	    "<HTML><HEAD><TITLE>Server Return Nothing.</TITLE>\n"
	    "</HEAD><BODY><HR><H1>Server Return Nothing.</H1></BODY></HTML>\n");
	storeAppend(gopherState->entry, tmpbuf, strlen(tmpbuf));
	return;
    }
}


