    fwd->fail(err);
    fwd->dontRetry(true);

    abortOnData("timely adaptation block");
}

void
