    buf.append("/", 1);
    fillDoneStatus(buf);

    buf.Printf(" %s%u]", id.Prefix, id.value);

    buf.terminate();

