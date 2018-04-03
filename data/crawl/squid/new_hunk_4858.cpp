
bool ICAPXaction::done() const
{
    if (stopReason != NULL) { // mustStop() has been called
        debugs(93,1,HERE << "ICAPXaction is done() because " << stopReason);
        return true;
    }

    return doneAll();
}
