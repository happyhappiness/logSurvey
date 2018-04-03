    fdc_table[fd].half_closed = true;
}

AbortChecker &AbortChecker::Instance() {return Instance_;}

AbortChecker AbortChecker::Instance_;
