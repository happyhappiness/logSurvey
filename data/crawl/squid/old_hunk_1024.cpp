    assert (spec->length >= 0);

    if (!known_spec(spec->offset) || !known_spec(spec->length))
        packerPrintf(p, "*");
    else
        packerPrintf(p, "bytes %" PRId64 "-%" PRId64,
                     spec->offset, spec->offset + spec->length - 1);
}

