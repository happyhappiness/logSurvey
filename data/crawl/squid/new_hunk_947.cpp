
    if (preview.enabled()) {
        if (preview.done())
            buf.appendf("P%s", preview.ieof() ? "(ieof)" : "");
    }

    if (doneReading())
