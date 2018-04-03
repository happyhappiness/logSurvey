		return parse_short_magic(magic, elem);
}

/*
 * Take an element of a pathspec and check for magic signatures.
 * Append the result to the prefix. Return the magic bitmap.
