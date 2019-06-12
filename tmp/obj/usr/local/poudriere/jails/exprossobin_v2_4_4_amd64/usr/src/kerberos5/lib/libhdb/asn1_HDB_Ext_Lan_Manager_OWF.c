/* Generated from /usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hdb/hdb.asn1 */
/* Do not edit */

#define  ASN1_LIB

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <krb5-types.h>
#include <hdb_asn1.h>
#include <hdb_asn1-priv.h>
#include <asn1_err.h>
#include <der.h>
#include <der-private.h>
#include <asn1-template.h>
#include <parse_units.h>

int ASN1CALL
encode_HDB_Ext_Lan_Manager_OWF(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const HDB_Ext_Lan_Manager_OWF *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

e = der_put_octet_string(p, len, data, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_OctetString, &l);
if (e) return e;
p -= l; len -= l; ret += l;

*size = ret;
return 0;
}

int ASN1CALL
decode_HDB_Ext_Lan_Manager_OWF(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, HDB_Ext_Lan_Manager_OWF *data, size_t *size)
{
size_t ret = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int e HEIMDAL_UNUSED_ATTRIBUTE;

memset(data, 0, sizeof(*data));
{
size_t Top_datalen, Top_oldlen;
Der_type Top_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &Top_type, UT_OctetString, &Top_datalen, &l);
if (e == 0 && Top_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
Top_oldlen = len;
if (Top_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = Top_datalen;
e = der_get_octet_string(p, len, data, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_HDB_Ext_Lan_Manager_OWF(data);
return e;
}

void ASN1CALL
free_HDB_Ext_Lan_Manager_OWF(HDB_Ext_Lan_Manager_OWF *data)
{
der_free_octet_string(data);
}

size_t ASN1CALL
length_HDB_Ext_Lan_Manager_OWF(const HDB_Ext_Lan_Manager_OWF *data)
{
size_t ret = 0;
ret += der_length_octet_string(data);
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_HDB_Ext_Lan_Manager_OWF(const HDB_Ext_Lan_Manager_OWF *from, HDB_Ext_Lan_Manager_OWF *to)
{
memset(to, 0, sizeof(*to));
if(der_copy_octet_string(from, to)) goto fail;
return 0;
fail:
free_HDB_Ext_Lan_Manager_OWF(to);
return ENOMEM;
}



