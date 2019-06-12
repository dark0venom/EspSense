/* Generated from /usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/gssapi/spnego/spnego.asn1 */
/* Do not edit */

#define  ASN1_LIB

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <krb5-types.h>
#include <spnego_asn1.h>
#include <spnego_asn1-priv.h>
#include <asn1_err.h>
#include <der.h>
#include <der-private.h>
#include <asn1-template.h>
#include <parse_units.h>

int ASN1CALL
encode_NegotiationTokenWin(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const NegotiationTokenWin *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;


switch((data)->element) {
case choice_NegotiationTokenWin_negTokenInit: {size_t Top_oldret = ret;
ret = 0;
e = encode_NegTokenInitWin(p, len, &((data))->u.negTokenInit, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 0, &l);
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
decode_NegotiationTokenWin(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, NegotiationTokenWin *data, size_t *size)
{
size_t ret = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int e HEIMDAL_UNUSED_ATTRIBUTE;

memset(data, 0, sizeof(*data));
if (der_match_tag(p, len, ASN1_C_CONTEXT, CONS, 0, NULL) == 0) {
{
size_t negTokenInit_datalen, negTokenInit_oldlen;
Der_type negTokenInit_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &negTokenInit_type, 0, &negTokenInit_datalen, &l);
if (e == 0 && negTokenInit_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
negTokenInit_oldlen = len;
if (negTokenInit_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = negTokenInit_datalen;
e = decode_NegTokenInitWin(p, len, &(data)->u.negTokenInit, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = negTokenInit_oldlen - negTokenInit_datalen;
}
(data)->element = choice_NegotiationTokenWin_negTokenInit;
}
else {
e = ASN1_PARSE_ERROR;
goto fail;
}
if(size) *size = ret;
return 0;
fail:
free_NegotiationTokenWin(data);
return e;
}

void ASN1CALL
free_NegotiationTokenWin(NegotiationTokenWin *data)
{
switch((data)->element) {
case choice_NegotiationTokenWin_negTokenInit:
free_NegTokenInitWin(&(data)->u.negTokenInit);
break;
}
}

size_t ASN1CALL
length_NegotiationTokenWin(const NegotiationTokenWin *data)
{
size_t ret = 0;
switch((data)->element) {
case choice_NegotiationTokenWin_negTokenInit:
{
size_t Top_oldret = ret;
ret = 0;
ret += length_NegTokenInitWin(&(data)->u.negTokenInit);
ret += 1 + der_length_len (ret);
ret += Top_oldret;
}
break;
}
return ret;
}

int ASN1CALL
copy_NegotiationTokenWin(const NegotiationTokenWin *from, NegotiationTokenWin *to)
{
memset(to, 0, sizeof(*to));
(to)->element = (from)->element;
switch((from)->element) {
case choice_NegotiationTokenWin_negTokenInit:
if(copy_NegTokenInitWin(&(from)->u.negTokenInit, &(to)->u.negTokenInit)) goto fail;
break;
}
return 0;
fail:
free_NegotiationTokenWin(to);
return ENOMEM;
}



