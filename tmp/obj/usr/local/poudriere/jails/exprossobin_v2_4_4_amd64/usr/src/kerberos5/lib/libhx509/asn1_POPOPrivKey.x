/* Generated from /usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/crmf.asn1 */
/* Do not edit */

#define  ASN1_LIB

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <krb5-types.h>
#include <crmf_asn1.h>
#include <crmf_asn1-priv.h>
#include <asn1_err.h>
#include <der.h>
#include <der-private.h>
#include <asn1-template.h>
#include <parse_units.h>

int ASN1CALL
encode_POPOPrivKey(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const POPOPrivKey *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;


switch((data)->element) {
case choice_POPOPrivKey_encryptedKey: {size_t Top_oldret = ret;
ret = 0;
e = encode_heim_any(p, len, &((data))->u.encryptedKey, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 4, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_oldret;
break;
}
case choice_POPOPrivKey_agreeMAC: {size_t Top_oldret = ret;
ret = 0;
e = encode_PKMACValue(p, len, &((data))->u.agreeMAC, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 3, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_oldret;
break;
}
case choice_POPOPrivKey_dhMAC: {size_t Top_oldret = ret;
ret = 0;
e = der_put_bit_string(p, len, &((data))->u.dhMAC, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_BitString, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 2, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_oldret;
break;
}
case choice_POPOPrivKey_subsequentMessage: {size_t Top_oldret = ret;
ret = 0;
e = encode_SubsequentMessage(p, len, &((data))->u.subsequentMessage, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 1, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_oldret;
break;
}
case choice_POPOPrivKey_thisMessage: {size_t Top_oldret = ret;
ret = 0;
e = der_put_bit_string(p, len, &((data))->u.thisMessage, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_BitString, &l);
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
decode_POPOPrivKey(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, POPOPrivKey *data, size_t *size)
{
size_t ret = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int e HEIMDAL_UNUSED_ATTRIBUTE;

memset(data, 0, sizeof(*data));
if (der_match_tag(p, len, ASN1_C_CONTEXT, CONS, 0, NULL) == 0) {
{
size_t thisMessage_datalen, thisMessage_oldlen;
Der_type thisMessage_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &thisMessage_type, 0, &thisMessage_datalen, &l);
if (e == 0 && thisMessage_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
thisMessage_oldlen = len;
if (thisMessage_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = thisMessage_datalen;
{
size_t thisMessage_Tag_datalen, thisMessage_Tag_oldlen;
Der_type thisMessage_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &thisMessage_Tag_type, UT_BitString, &thisMessage_Tag_datalen, &l);
if (e == 0 && thisMessage_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
thisMessage_Tag_oldlen = len;
if (thisMessage_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = thisMessage_Tag_datalen;
e = der_get_bit_string(p, len, &(data)->u.thisMessage, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = thisMessage_Tag_oldlen - thisMessage_Tag_datalen;
}
len = thisMessage_oldlen - thisMessage_datalen;
}
(data)->element = choice_POPOPrivKey_thisMessage;
}
else if (der_match_tag(p, len, ASN1_C_CONTEXT, CONS, 1, NULL) == 0) {
{
size_t subsequentMessage_datalen, subsequentMessage_oldlen;
Der_type subsequentMessage_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &subsequentMessage_type, 1, &subsequentMessage_datalen, &l);
if (e == 0 && subsequentMessage_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
subsequentMessage_oldlen = len;
if (subsequentMessage_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = subsequentMessage_datalen;
e = decode_SubsequentMessage(p, len, &(data)->u.subsequentMessage, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = subsequentMessage_oldlen - subsequentMessage_datalen;
}
(data)->element = choice_POPOPrivKey_subsequentMessage;
}
else if (der_match_tag(p, len, ASN1_C_CONTEXT, CONS, 2, NULL) == 0) {
{
size_t dhMAC_datalen, dhMAC_oldlen;
Der_type dhMAC_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &dhMAC_type, 2, &dhMAC_datalen, &l);
if (e == 0 && dhMAC_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
dhMAC_oldlen = len;
if (dhMAC_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = dhMAC_datalen;
{
size_t dhMAC_Tag_datalen, dhMAC_Tag_oldlen;
Der_type dhMAC_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &dhMAC_Tag_type, UT_BitString, &dhMAC_Tag_datalen, &l);
if (e == 0 && dhMAC_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
dhMAC_Tag_oldlen = len;
if (dhMAC_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = dhMAC_Tag_datalen;
e = der_get_bit_string(p, len, &(data)->u.dhMAC, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = dhMAC_Tag_oldlen - dhMAC_Tag_datalen;
}
len = dhMAC_oldlen - dhMAC_datalen;
}
(data)->element = choice_POPOPrivKey_dhMAC;
}
else if (der_match_tag(p, len, ASN1_C_CONTEXT, CONS, 3, NULL) == 0) {
{
size_t agreeMAC_datalen, agreeMAC_oldlen;
Der_type agreeMAC_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &agreeMAC_type, 3, &agreeMAC_datalen, &l);
if (e == 0 && agreeMAC_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
agreeMAC_oldlen = len;
if (agreeMAC_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = agreeMAC_datalen;
e = decode_PKMACValue(p, len, &(data)->u.agreeMAC, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = agreeMAC_oldlen - agreeMAC_datalen;
}
(data)->element = choice_POPOPrivKey_agreeMAC;
}
else if (der_match_tag(p, len, ASN1_C_CONTEXT, CONS, 4, NULL) == 0) {
{
size_t encryptedKey_datalen, encryptedKey_oldlen;
Der_type encryptedKey_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &encryptedKey_type, 4, &encryptedKey_datalen, &l);
if (e == 0 && encryptedKey_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
encryptedKey_oldlen = len;
if (encryptedKey_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = encryptedKey_datalen;
e = decode_heim_any(p, len, &(data)->u.encryptedKey, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = encryptedKey_oldlen - encryptedKey_datalen;
}
(data)->element = choice_POPOPrivKey_encryptedKey;
}
else {
e = ASN1_PARSE_ERROR;
goto fail;
}
if(size) *size = ret;
return 0;
fail:
free_POPOPrivKey(data);
return e;
}

void ASN1CALL
free_POPOPrivKey(POPOPrivKey *data)
{
switch((data)->element) {
case choice_POPOPrivKey_thisMessage:
der_free_bit_string(&(data)->u.thisMessage);
break;
case choice_POPOPrivKey_subsequentMessage:
free_SubsequentMessage(&(data)->u.subsequentMessage);
break;
case choice_POPOPrivKey_dhMAC:
der_free_bit_string(&(data)->u.dhMAC);
break;
case choice_POPOPrivKey_agreeMAC:
free_PKMACValue(&(data)->u.agreeMAC);
break;
case choice_POPOPrivKey_encryptedKey:
free_heim_any(&(data)->u.encryptedKey);
break;
}
}

size_t ASN1CALL
length_POPOPrivKey(const POPOPrivKey *data)
{
size_t ret = 0;
switch((data)->element) {
case choice_POPOPrivKey_thisMessage:
{
size_t Top_oldret = ret;
ret = 0;
ret += der_length_bit_string(&(data)->u.thisMessage);
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_oldret;
}
break;
case choice_POPOPrivKey_subsequentMessage:
{
size_t Top_oldret = ret;
ret = 0;
ret += length_SubsequentMessage(&(data)->u.subsequentMessage);
ret += 1 + der_length_len (ret);
ret += Top_oldret;
}
break;
case choice_POPOPrivKey_dhMAC:
{
size_t Top_oldret = ret;
ret = 0;
ret += der_length_bit_string(&(data)->u.dhMAC);
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_oldret;
}
break;
case choice_POPOPrivKey_agreeMAC:
{
size_t Top_oldret = ret;
ret = 0;
ret += length_PKMACValue(&(data)->u.agreeMAC);
ret += 1 + der_length_len (ret);
ret += Top_oldret;
}
break;
case choice_POPOPrivKey_encryptedKey:
{
size_t Top_oldret = ret;
ret = 0;
ret += length_heim_any(&(data)->u.encryptedKey);
ret += 1 + der_length_len (ret);
ret += Top_oldret;
}
break;
}
return ret;
}

int ASN1CALL
copy_POPOPrivKey(const POPOPrivKey *from, POPOPrivKey *to)
{
memset(to, 0, sizeof(*to));
(to)->element = (from)->element;
switch((from)->element) {
case choice_POPOPrivKey_thisMessage:
if(der_copy_bit_string(&(from)->u.thisMessage, &(to)->u.thisMessage)) goto fail;
break;
case choice_POPOPrivKey_subsequentMessage:
if(copy_SubsequentMessage(&(from)->u.subsequentMessage, &(to)->u.subsequentMessage)) goto fail;
break;
case choice_POPOPrivKey_dhMAC:
if(der_copy_bit_string(&(from)->u.dhMAC, &(to)->u.dhMAC)) goto fail;
break;
case choice_POPOPrivKey_agreeMAC:
if(copy_PKMACValue(&(from)->u.agreeMAC, &(to)->u.agreeMAC)) goto fail;
break;
case choice_POPOPrivKey_encryptedKey:
if(copy_heim_any(&(from)->u.encryptedKey, &(to)->u.encryptedKey)) goto fail;
break;
}
return 0;
fail:
free_POPOPrivKey(to);
return ENOMEM;
}



