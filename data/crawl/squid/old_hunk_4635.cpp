    mustStop("ICAP service connection externally closed");
}

bool ICAPXaction::done() const
{
    // stopReason, set in mustStop(), overwrites all other conditions
    return stopReason != NULL || doneAll();
}

bool ICAPXaction::doneAll() const
{
    return !connector && !reader && !writer;
}

void ICAPXaction::updateTimeout() {
