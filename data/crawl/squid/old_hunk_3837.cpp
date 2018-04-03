        parseBody();
}

void ICAPModXact::callException(const std::exception &e)
{
    if (!canStartBypass || isRetriable) {
        ICAPXaction::callException(e);
        return;
    }

    try {
        debugs(93, 3, "bypassing ICAPModXact::" << inCall << " exception: " <<
               e.what() << ' ' << status());
        bypassFailure();
    } catch (const std::exception &bypassE) {
        ICAPXaction::callException(bypassE);
    }
}

void ICAPModXact::bypassFailure()
{
    disableBypass("already started to bypass");

