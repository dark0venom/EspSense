int	op_atmif(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotAtmIfName 1
# define LEAF_begemotAtmIfPcr 2
# define LEAF_begemotAtmIfMedia 3
# define LEAF_begemotAtmIfVpiBits 4
# define LEAF_begemotAtmIfVciBits 5
# define LEAF_begemotAtmIfMaxVpcs 6
# define LEAF_begemotAtmIfMaxVccs 7
# define LEAF_begemotAtmIfEsi 8
# define LEAF_begemotAtmIfCarrierStatus 9
# define LEAF_begemotAtmIfMode 10
int	op_atm(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotAtmIfTableLastChange 2
int	op_atmhw(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotAtmHWVendor 1
# define LEAF_begemotAtmHWDevice 2
# define LEAF_begemotAtmHWSerial 3
# define LEAF_begemotAtmHWVersion 4
# define LEAF_begemotAtmHWSoftVersion 5
int	op_atmif_ng(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotAtmIfNodeId 1

#ifdef SNMPTREE_TYPES

#endif /* SNMPTREE_TYPES */

#define atm_CTREE_SIZE 17
extern const struct snmp_node atm_ctree[];
