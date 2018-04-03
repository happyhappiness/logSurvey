
    return status;
}

char *
wildcard_expansion (wc, o)
char * wc, * o;
{
#   define PATH_SIZE	1024
    struct AnchorPath * apath;

    if ( (apath = AllocMem (sizeof (struct AnchorPath) + PATH_SIZE,
	    MEMF_CLEAR))
	)
    {
	apath->ap_Strlen = PATH_SIZE;

	if (MatchFirst (wc, apath) == 0)
	{
	    do
	    {
		o = variable_buffer_output (o, apath->ap_Buf,
			strlen (apath->ap_Buf));
		o = variable_buffer_output (o, " ",1);
	    } while (MatchNext (apath) == 0);
	}

	MatchEnd (apath);
	FreeMem (apath, sizeof (struct AnchorPath) + PATH_SIZE);
    }

    return o;
}

