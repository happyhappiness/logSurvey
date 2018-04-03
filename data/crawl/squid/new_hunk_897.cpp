    assert (range->elength >= 0);

    if (!known_spec(range->elength))
        p->Printf("/*");
    else
        p->Printf("/%" PRId64, range->elength);
}

void
