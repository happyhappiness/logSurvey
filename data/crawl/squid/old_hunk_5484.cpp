	    sb = httpHeaderGetListMember(&request->header, format->header_id, format->member, format->separator);
	    str = strBuf(sb);
	    break;
	}
	if (str)
	    if (!*str)
