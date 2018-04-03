{
	struct object *tagged = tag->tagged;

	if (!tagged) {
		return objerror(&tag->object, "could not load tagged object");
	}
