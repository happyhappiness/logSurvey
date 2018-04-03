		line = packet_read_line(0, &len);
		if (!line)
			break;
		if (len < 83 ||
		    line[40] != ' ' ||
		    line[81] != ' ' ||
