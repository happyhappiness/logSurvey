    assert (range->elength >= 0);

    if (!known_spec(range->elength))
        p->append("/*", 2);
    else
        p->appendf("/%" PRId64, range->elength);
}

void
