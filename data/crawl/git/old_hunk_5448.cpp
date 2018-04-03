	}

	nr = all - reaches - 1;
	printf("Bisecting: %d revisions left to test after this "
	       "(roughly %d steps)\n", nr, estimate_bisect_steps(all));

	return bisect_checkout(bisect_rev_hex);
}