/* Generated from /usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/ocsp.asn1 */
/* Do not edit */

#define  ASN1_LIB

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <krb5-types.h>
#include <ocsp_asn1.h>
#include <ocsp_asn1-priv.h>
#include <asn1_err.h>
#include <der.h>
#include <der-private.h>
#include <asn1-template.h>
#include <parse_units.h>

int ASN1CALL
encode_OCSPResponderID(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const OCSPResponderID *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;


switch((data)->element) {
case choice_OCSPResponderID_byKey: {size_t Top_oldret = ret;
ret = 0;
e = encode_OCSPKeyHash(p, len, &((data))->u.byKey, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 2, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_oldret;
break;
}
case choice_OCSPResponderID_byName: {size_t Top_oldret = ret;
ret = 0;
e = encode_Name(p, len, &((data))->u.byName, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 1, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_oldret;
break;
}
};
*size = ret;
return 0;
}

int ASN1CALL
decode_OCSPResponderID(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, OCSPResponderID *data, size_t *size)
{
size_t ret = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int e HEIMDAL_UNUSED_ATTRIBUTE;

memset(data, 0, sizeof(*data));
if (der_match_tag(p, len, ASN1_C_CONTEXT, CONS, 1, NULL) == 0) {
{
size_t byName_datalen, byName_oldlen;
Der_type byName_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &byName_type, 1, &byName_datalen, &l);
if (e == 0 && byName_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
byName_oldlen = len;
if (byName_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = byName_datalen;
e = decode_Name(p, len, &(data)->u.byName, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = byName_oldlen - byName_datalen;
}
(data)->element = choice_OCSPResponderID_byName;
}
else if (der_match_tag(p, len, ASN1_C_CONTEXT, CONS, 2, NULL) == 0) {
{
size_t byKey_datalen, byKey_oldlen;
Der_type byKey_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &byKey_type, 2, &byKey_datalen, &l);
if (e == 0 && byKey_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
byKey_oldlen = len;
if (byKey_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = byKey_datalen;
e = decode_OCSPKeyHash(p, len, &(data)->u.byKey, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = byKey_oldlen - byKey_datalen;
}
(data)->element = choice_OCSPResponderID_byKey;
}
else {
e = ASN1_PARSE_ERROR;
goto fail;
}
if(size) *size = ret;
return 0;
fail:
free_OCSPResponderID(data);
return e;
}

void ASN1CALL
free_OCSPResponderID(OCSPResponderID *data)
{
switch((data)->element) {
case choice_OCSPResponderID_byName:
free_Name(&(data)->u.byName);
break;
case choice_OCSPResponderID_byKey:
free_OCSPKeyHash(&(data)->u.byKey);
break;
}
}

size_t ASN1CALL
length_OCSPResponderID(const OCSPResponderID *data)
{
size_t ret = 0;
switch((data)->element) {
case choice_OCSPResponderID_byName:
{
size_t Top_oldret = ret;
ret = 0;
ret += length_Name(&(data)->u.byName);
ret += 1 + der_length_len (ret);
ret += Top_oldret;
}
break;
case choice_OCSPResponderID_byKey:
{
size_t Top_oldret = ret;
ret = 0;
ret += length_OCSPKeyHash(&(data)->u.byKey);
ret += 1 + der_length_len (ret);
ret += Top_oldret;
}
break;
}
return ret;
}

int ASN1CALL
copy_OCSPResponderID(const OCSPResponderID *from, OCSPResponderID *to)
{
memset(to, 0, sizeof(*to));
(to)->element = (from)->element;
switch((from)->element) {
case choice_OCSPResponderID_byName:
if(copy_Name(&(from)->u.byName, &(to)->u.byName)) goto fail;
break;
case choice_OCSPResponderID_byKey:
if(copy_OCSPKeyHash(&(from)->u.byKey, &(to)->u.byKey)) goto fail;
break;
}
return 0;
fail:
free_OCSPResponderID(to);
return ENOMEM;
}



