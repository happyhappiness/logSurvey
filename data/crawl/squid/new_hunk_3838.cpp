    }
}

void Adaptation::Icap::ModXact::disableBypass(const char *reason)
{
    if (canStartBypass) {
        debugs(93,7, HERE << "will never start bypass because " << reason);
