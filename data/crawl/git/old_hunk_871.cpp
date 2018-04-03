	strbuf_addf(sb, ",prefix:%d)", prefixlen);
}

/*
 * Take an element of a pathspec and check for magic signatures.
 * Append the result to the prefix. Return the magic bitmap.
