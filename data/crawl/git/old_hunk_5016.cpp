		buffer_skip_bytes(5);
		len -= 5;
	}
	printf("blob\nmark :%d\ndata %d\n", mark, len);
	buffer_copy_bytes(len);
	fputc('\n', stdout);
}
