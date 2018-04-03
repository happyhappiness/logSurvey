		buffer_skip_bytes(5);
		len -= 5;
	}
	printf("blob\nmark :%"PRIu32"\ndata %"PRIu32"\n", mark, len);
	buffer_copy_bytes(len);
	fputc('\n', stdout);
}
