			rm->merge ? "" : "not-for-merge",
			note);

		if (ref)
			update_local_ref(ref, note, verbose);
	}
	fclose(fp);
}
