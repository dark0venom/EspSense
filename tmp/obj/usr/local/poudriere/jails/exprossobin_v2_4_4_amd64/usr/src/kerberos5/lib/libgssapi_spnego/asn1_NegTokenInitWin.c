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
encode_NegTokenInitWin(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const NegTokenInitWin *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* negHints */
if((data)->negHints) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_NegHints(p, len, (data)->negHints, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 3, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* mechToken */
if((data)->mechToken) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_octet_string(p, len, (data)->mechToken, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_OctetString, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 2, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* reqFlags */
if((data)->reqFlags) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_ContextFlags(p, len, (data)->reqFlags, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 1, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* mechTypes */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_MechTypeList(p, len, &(data)->mechTypes, &l);
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
decode_NegTokenInitWin(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, NegTokenInitWin *data, size_t *size)
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
size_t mechTypes_datalen, mechTypes_oldlen;
Der_type mechTypes_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &mechTypes_type, 0, &mechTypes_datalen, &l);
if (e == 0 && mechTypes_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
mechTypes_oldlen = len;
if (mechTypes_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = mechTypes_datalen;
e = decode_MechTypeList(p, len, &(data)->mechTypes, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = mechTypes_oldlen - mechTypes_datalen;
}
{
size_t reqFlags_datalen, reqFlags_oldlen;
Der_type reqFlags_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &reqFlags_type, 1, &reqFlags_datalen, &l);
if (e == 0 && reqFlags_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->reqFlags = NULL;
} else {
(data)->reqFlags = calloc(1, sizeof(*(data)->reqFlags));
if ((data)->reqFlags == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
reqFlags_oldlen = len;
if (reqFlags_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = reqFlags_datalen;
e = decode_ContextFlags(p, len, (data)->reqFlags, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = reqFlags_oldlen - reqFlags_datalen;
}
}
{
size_t mechToken_datalen, mechToken_oldlen;
Der_type mechToken_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &mechToken_type, 2, &mechToken_datalen, &l);
if (e == 0 && mechToken_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->mechToken = NULL;
} else {
(data)->mechToken = calloc(1, sizeof(*(data)->mechToken));
if ((data)->mechToken == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
mechToken_oldlen = len;
if (mechToken_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = mechToken_datalen;
{
size_t mechToken_Tag_datalen, mechToken_Tag_oldlen;
Der_type mechToken_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &mechToken_Tag_type, UT_OctetString, &mechToken_Tag_datalen, &l);
if (e == 0 && mechToken_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
mechToken_Tag_oldlen = len;
if (mechToken_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = mechToken_Tag_datalen;
e = der_get_octet_string(p, len, (data)->mechToken, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = mechToken_Tag_oldlen - mechToken_Tag_datalen;
}
len = mechToken_oldlen - mechToken_datalen;
}
}
{
size_t negHints_datalen, negHints_oldlen;
Der_type negHints_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &negHints_type, 3, &negHints_datalen, &l);
if (e == 0 && negHints_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->negHints = NULL;
} else {
(data)->negHints = calloc(1, sizeof(*(data)->negHints));
if ((data)->negHints == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
negHints_oldlen = len;
if (negHints_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = negHints_datalen;
e = decode_NegHints(p, len, (data)->negHints, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = negHints_oldlen - negHints_datalen;
}
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_NegTokenInitWin(data);
return e;
}

void ASN1CALL
free_NegTokenInitWin(NegTokenInitWin *data)
{
free_MechTypeList(&(data)->mechTypes);
if((data)->reqFlags) {
free_ContextFlags((data)->reqFlags);
free((data)->reqFlags);
(data)->reqFlags = NULL;
}
if((data)->mechToken) {
der_free_octet_string((data)->mechToken);
free((data)->mechToken);
(data)->mechToken = NULL;
}
if((data)->negHints) {
free_NegHints((data)->negHints);
free((data)->negHints);
(data)->negHints = NULL;
}
}

size_t ASN1CALL
length_NegTokenInitWin(const NegTokenInitWin *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_MechTypeList(&(data)->mechTypes);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->reqFlags){
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_ContextFlags((data)->reqFlags);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->mechToken){
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_octet_string((data)->mechToken);
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->negHints){
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_NegHints((data)->negHints);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_NegTokenInitWin(const NegTokenInitWin *from, NegTokenInitWin *to)
{
memset(to, 0, sizeof(*to));
if(copy_MechTypeList(&(from)->mechTypes, &(to)->mechTypes)) goto fail;
if((from)->reqFlags) {
(to)->reqFlags = malloc(sizeof(*(to)->reqFlags));
if((to)->reqFlags == NULL) goto fail;
if(copy_ContextFlags((from)->reqFlags, (to)->reqFlags)) goto fail;
}else
(to)->reqFlags = NULL;
if((from)->mechToken) {
(to)->mechToken = malloc(sizeof(*(to)->mechToken));
if((to)->mechToken == NULL) goto fail;
if(der_copy_octet_string((from)->mechToken, (to)->mechToken)) goto fail;
}else
(to)->mechToken = NULL;
if((from)->negHints) {
(to)->negHints = malloc(sizeof(*(to)->negHints));
if((to)->negHints == NULL) goto fail;
if(copy_NegHints((from)->negHints, (to)->negHints)) goto fail;
}else
(to)->negHints = NULL;
return 0;
fail:
free_NegTokenInitWin(to);
return ENOMEM;
}



