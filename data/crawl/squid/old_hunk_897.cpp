    assert (range->elength >= 0);

    if (!known_spec(range->elength))
        packerPrintf(p, "/*");
    else
        packerPrintf(p, "/%" PRId64, range->elength);
}

void
