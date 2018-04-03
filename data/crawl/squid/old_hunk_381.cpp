    fwd->fail(err);
    fwd->dontRetry(true);

    abortTransaction("timely adaptation block");
}

void
