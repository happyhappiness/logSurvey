				printf("boundary\n");
		}
		write_filename_info(suspect->path);
		maybe_flush_or_die(stdout, "stdout");
	}
}

