            buf.append(" A?", 3);
    }

    buf.appendf(" %s%u]", id.Prefix, id.value);

    buf.terminate();
