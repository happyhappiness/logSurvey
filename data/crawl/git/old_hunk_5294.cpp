				fputs(ws, stream);
				fwrite(line + written, i - written, 1, stream);
				fputs(reset, stream);
			}
		} else if (stream)
			fwrite(line + written, i - written, 1, stream);
		if (stream)
			fwrite(line + i, 1, 1, stream);
		written = i + 1;
	}
