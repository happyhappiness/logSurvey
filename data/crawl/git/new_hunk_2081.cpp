		FILE *f = to_stdout ? stdout : fopen(fpath, "wb");

		if (!f)
			ret = error_errno("Could not open %s for writing",
					  filename);
		else if (result.size &&
			 fwrite(result.ptr, result.size, 1, f) != 1)
			ret = error_errno("Could not write to %s", filename);
		else if (fclose(f))
			ret = error_errno("Could not close %s", filename);
		free(result.ptr);
	}
