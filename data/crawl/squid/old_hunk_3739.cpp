    Must(s != NULL);
    return new Adaptation::Icap::ModXact(this, virgin.header, virgin.cause, s);
}
