    storeAppendPrintf(sentry, "\nsee also \"Memory utilization\" for detailed per type statistics\n");
}

CallbackData &
CallbackData::operator =(const CallbackData &other)
{
    if (data_ != other.data_) { // assignment to self and no-op assignments
        auto old = data_;
        data_ = cbdataReference(other.data_);
        cbdataReferenceDone(old);
    }
    return *this;
}

CBDATA_CLASS_INIT(generic_cbdata);

#if USE_CBDATA_DEBUG
