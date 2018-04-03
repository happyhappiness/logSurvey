
bool ICAPXaction::done() const
{
    if (stopReason != NULL) // mustStop() has been called
        return true;

    return doneAll();
}
