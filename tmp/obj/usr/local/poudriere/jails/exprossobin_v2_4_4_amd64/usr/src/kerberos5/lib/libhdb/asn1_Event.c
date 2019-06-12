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
encode_Event(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const Event *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* principal */
if((data)->principal) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_Principal(p, len, (data)->principal, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 1, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* time */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_KerberosTime(p, len, &(data)->time, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 0, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, CONS, UT_Sequence, &l);
if (e) return e;
p -= l; len -= l; ret += l;

*size = ret;
return 0;
}

int ASN1CALL
decode_Event(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, Event *data, size_t *size)
{
size_t ret = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int e HEIMDAL_UNUSED_ATTRIBUTE;

memset(data, 0, sizeof(*data));
{
size_t Top_datalen, Top_oldlen;
Der_type Top_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &Top_type, UT_Sequence, &Top_datalen, &l);
if (e == 0 && Top_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
Top_oldlen = len;
if (Top_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = Top_datalen;
{
size_t time_datalen, time_oldlen;
Der_type time_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &time_type, 0, &time_datalen, &l);
if (e == 0 && time_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
time_oldlen = len;
if (time_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = time_datalen;
e = decode_KerberosTime(p, len, &(data)->time, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = time_oldlen - time_datalen;
}
{
size_t principal_datalen, principal_oldlen;
Der_type principal_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &principal_type, 1, &principal_datalen, &l);
if (e == 0 && principal_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->principal = NULL;
} else {
(data)->principal = calloc(1, sizeof(*(data)->principal));
if ((data)->principal == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
principal_oldlen = len;
if (principal_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = principal_datalen;
e = decode_Principal(p, len, (data)->principal, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = principal_oldlen - principal_datalen;
}
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_Event(data);
return e;
}

void ASN1CALL
free_Event(Event *data)
{
free_KerberosTime(&(data)->time);
if((data)->principal) {
free_Principal((data)->principal);
free((data)->principal);
(data)->principal = NULL;
}
}

size_t ASN1CALL
length_Event(const Event *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_KerberosTime(&(data)->time);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->principal){
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_Principal((data)->principal);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_Event(const Event *from, Event *to)
{
memset(to, 0, sizeof(*to));
if(copy_KerberosTime(&(from)->time, &(to)->time)) goto fail;
if((from)->principal) {
(to)->principal = malloc(sizeof(*(to)->principal));
if((to)->principal == NULL) goto fail;
if(copy_Principal((from)->principal, (to)->principal)) goto fail;
}else
(to)->principal = NULL;
return 0;
fail:
free_Event(to);
return ENOMEM;
}



