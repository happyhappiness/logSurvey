    if (Config.Port.snmp > 0) {
        Config.Addrs.snmp_incoming.SetPort(Config.Port.snmp);

        AsyncCall::Pointer call = asyncCall(49, 2,
                                            "snmpIncomingConnectionOpened",
                                            SnmpListeningStartedDialer(&snmpIncomingConnectionOpened));
