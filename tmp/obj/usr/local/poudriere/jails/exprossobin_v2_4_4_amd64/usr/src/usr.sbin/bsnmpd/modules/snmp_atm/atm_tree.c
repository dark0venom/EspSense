#include <sys/types.h>
#include <stdio.h>
#include <stdint.h>
#include <bsnmp/asn1.h>
#include <bsnmp/snmp.h>
#include <bsnmp/snmpagent.h>
#include "atm_tree.h"

const struct snmp_node atm_ctree[] = {
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 101, 1, 1, 1, 1, }}, "begemotAtmIfName", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_atmif, 0, 0x11, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 101, 1, 1, 1, 2, }}, "begemotAtmIfPcr", SNMP_NODE_COLUMN, SNMP_SYNTAX_GAUGE, op_atmif, 0, 0x11, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 101, 1, 1, 1, 3, }}, "begemotAtmIfMedia", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_atmif, 0, 0x11, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 101, 1, 1, 1, 4, }}, "begemotAtmIfVpiBits", SNMP_NODE_COLUMN, SNMP_SYNTAX_GAUGE, op_atmif, 0, 0x11, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 101, 1, 1, 1, 5, }}, "begemotAtmIfVciBits", SNMP_NODE_COLUMN, SNMP_SYNTAX_GAUGE, op_atmif, 0, 0x11, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 101, 1, 1, 1, 6, }}, "begemotAtmIfMaxVpcs", SNMP_NODE_COLUMN, SNMP_SYNTAX_GAUGE, op_atmif, 0, 0x11, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 101, 1, 1, 1, 7, }}, "begemotAtmIfMaxVccs", SNMP_NODE_COLUMN, SNMP_SYNTAX_GAUGE, op_atmif, 0, 0x11, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 101, 1, 1, 1, 8, }}, "begemotAtmIfEsi", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_atmif, 0, 0x11, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 101, 1, 1, 1, 9, }}, "begemotAtmIfCarrierStatus", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_atmif, 0, 0x11, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 101, 1, 1, 1, 10, }}, "begemotAtmIfMode", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_atmif, 0|SNMP_NODE_CANSET, 0x11, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 4, 1, 12325, 1, 101, 1, 2, }}, "begemotAtmIfTableLastChange", SNMP_NODE_LEAF, SNMP_SYNTAX_TIMETICKS, op_atm, 0, 0, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 101, 1, 3, 1, 1, }}, "begemotAtmHWVendor", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_atmhw, 0, 0x11, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 101, 1, 3, 1, 2, }}, "begemotAtmHWDevice", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_atmhw, 0, 0x11, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 101, 1, 3, 1, 3, }}, "begemotAtmHWSerial", SNMP_NODE_COLUMN, SNMP_SYNTAX_GAUGE, op_atmhw, 0, 0x11, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 101, 1, 3, 1, 4, }}, "begemotAtmHWVersion", SNMP_NODE_COLUMN, SNMP_SYNTAX_GAUGE, op_atmhw, 0, 0x11, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 101, 1, 3, 1, 5, }}, "begemotAtmHWSoftVersion", SNMP_NODE_COLUMN, SNMP_SYNTAX_GAUGE, op_atmhw, 0, 0x11, NULL, NULL },
    {{ 16, { 1, 3, 6, 1, 4, 1, 12325, 1, 101, 1, 4, 1, 1, 1, 1, 1, }}, "begemotAtmIfNodeId", SNMP_NODE_COLUMN, SNMP_SYNTAX_GAUGE, op_atmif_ng, 0, 0x11, NULL, NULL },
};

