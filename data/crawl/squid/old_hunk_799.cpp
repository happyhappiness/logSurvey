}

void
HttpHdrRangeSpec::packInto(Packable * packer) const
{
    if (!known_spec(offset))    /* suffix */
        packer->Printf("-%" PRId64,  length);
    else if (!known_spec(length))       /* trailer */
        packer->Printf("%" PRId64 "-", offset);
    else            /* range */
        packer->Printf("%" PRId64 "-%" PRId64, offset, offset + length - 1);
}

void
