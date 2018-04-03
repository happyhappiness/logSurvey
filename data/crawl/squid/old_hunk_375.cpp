        return false;

    debugs(11,5, HERE << "entry is not Accepting!");
    abortTransaction(abortReason);
    return true;
}

