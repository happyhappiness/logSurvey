    ~QosConfig() {};

    void parseConfigLine();
    void dumpConfigLine(StoreEntry *entry, const char *name) const;
};

/* legacy parser access wrappers */
#define parse_QosConfig(X)	(X)->parseConfigLine()
#define dump_QosConfig(e,n,X)	(X).dumpConfigLine(e,n)
#define free_QosConfig(X)

#endif /* USE_ZPH_QOS */
#endif /* SQUID_QOSCONFIG_H */
