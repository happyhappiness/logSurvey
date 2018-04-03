			     quiet ? finish_object : show_object,
			     &info);

	if (revs.count) {
		if (revs.left_right)
			printf("%d\t%d\n", revs.count_left, revs.count_right);
		else
			printf("%d\n", revs.count_left + revs.count_right);
	}

	return 0;
}
