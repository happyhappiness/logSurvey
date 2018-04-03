	}
    }
    debug(20, 1, "Created directory %s\n", path);
    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode) != 0) {
        sprintf(tmp_error_buf,
	    "Failed to create directory %s: %s", path, xstrerror());
        fatal(tmp_error_buf);
    }
    return 1;
}

int
