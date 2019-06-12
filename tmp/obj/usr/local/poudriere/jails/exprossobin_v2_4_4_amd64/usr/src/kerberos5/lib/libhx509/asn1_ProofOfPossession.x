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
encode_ProofOfPossession(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const ProofOfPossession *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;


switch((data)->element) {
case choice_ProofOfPossession_keyAgreement: {size_t Top_oldret = ret;
ret = 0;
e = encode_POPOPrivKey(p, len, &((data))->u.keyAgreement, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 3, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_oldret;
break;
}
case choice_ProofOfPossession_keyEncipherment: {size_t Top_oldret = ret;
ret = 0;
e = encode_POPOPrivKey(p, len, &((data))->u.keyEncipherment, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 2, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_oldret;
break;
}
case choice_ProofOfPossession_signature: {size_t Top_oldret = ret;
ret = 0;
e = encode_POPOSigningKey(p, len, &((data))->u.signature, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 1, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_oldret;
break;
}
case choice_ProofOfPossession_raVerified: {size_t Top_oldret = ret;
ret = 0;
/* NULL */
e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_Null, &l);
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
decode_ProofOfPossession(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, ProofOfPossession *data, size_t *size)
{
size_t ret = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int e HEIMDAL_UNUSED_ATTRIBUTE;

memset(data, 0, sizeof(*data));
if (der_match_tag(p, len, ASN1_C_CONTEXT, CONS, 0, NULL) == 0) {
{
size_t raVerified_datalen, raVerified_oldlen;
Der_type raVerified_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &raVerified_type, 0, &raVerified_datalen, &l);
if (e == 0 && raVerified_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
raVerified_oldlen = len;
if (raVerified_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = raVerified_datalen;
{
size_t raVerified_Tag_datalen, raVerified_Tag_oldlen;
Der_type raVerified_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &raVerified_Tag_type, UT_Null, &raVerified_Tag_datalen, &l);
if (e == 0 && raVerified_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
raVerified_Tag_oldlen = len;
if (raVerified_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = raVerified_Tag_datalen;
/* NULL */
len = raVerified_Tag_oldlen - raVerified_Tag_datalen;
}
len = raVerified_oldlen - raVerified_datalen;
}
(data)->element = choice_ProofOfPossession_raVerified;
}
else if (der_match_tag(p, len, ASN1_C_CONTEXT, CONS, 1, NULL) == 0) {
{
size_t signature_datalen, signature_oldlen;
Der_type signature_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &signature_type, 1, &signature_datalen, &l);
if (e == 0 && signature_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
signature_oldlen = len;
if (signature_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = signature_datalen;
e = decode_POPOSigningKey(p, len, &(data)->u.signature, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = signature_oldlen - signature_datalen;
}
(data)->element = choice_ProofOfPossession_signature;
}
else if (der_match_tag(p, len, ASN1_C_CONTEXT, CONS, 2, NULL) == 0) {
{
size_t keyEncipherment_datalen, keyEncipherment_oldlen;
Der_type keyEncipherment_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &keyEncipherment_type, 2, &keyEncipherment_datalen, &l);
if (e == 0 && keyEncipherment_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
keyEncipherment_oldlen = len;
if (keyEncipherment_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = keyEncipherment_datalen;
e = decode_POPOPrivKey(p, len, &(data)->u.keyEncipherment, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = keyEncipherment_oldlen - keyEncipherment_datalen;
}
(data)->element = choice_ProofOfPossession_keyEncipherment;
}
else if (der_match_tag(p, len, ASN1_C_CONTEXT, CONS, 3, NULL) == 0) {
{
size_t keyAgreement_datalen, keyAgreement_oldlen;
Der_type keyAgreement_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &keyAgreement_type, 3, &keyAgreement_datalen, &l);
if (e == 0 && keyAgreement_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
keyAgreement_oldlen = len;
if (keyAgreement_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = keyAgreement_datalen;
e = decode_POPOPrivKey(p, len, &(data)->u.keyAgreement, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = keyAgreement_oldlen - keyAgreement_datalen;
}
(data)->element = choice_ProofOfPossession_keyAgreement;
}
else {
e = ASN1_PARSE_ERROR;
goto fail;
}
if(size) *size = ret;
return 0;
fail:
free_ProofOfPossession(data);
return e;
}

void ASN1CALL
free_ProofOfPossession(ProofOfPossession *data)
{
switch((data)->element) {
case choice_ProofOfPossession_raVerified:
break;
case choice_ProofOfPossession_signature:
free_POPOSigningKey(&(data)->u.signature);
break;
case choice_ProofOfPossession_keyEncipherment:
free_POPOPrivKey(&(data)->u.keyEncipherment);
break;
case choice_ProofOfPossession_keyAgreement:
free_POPOPrivKey(&(data)->u.keyAgreement);
break;
}
}

size_t ASN1CALL
length_ProofOfPossession(const ProofOfPossession *data)
{
size_t ret = 0;
switch((data)->element) {
case choice_ProofOfPossession_raVerified:
{
size_t Top_oldret = ret;
ret = 0;
/* NULL */
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_oldret;
}
break;
case choice_ProofOfPossession_signature:
{
size_t Top_oldret = ret;
ret = 0;
ret += length_POPOSigningKey(&(data)->u.signature);
ret += 1 + der_length_len (ret);
ret += Top_oldret;
}
break;
case choice_ProofOfPossession_keyEncipherment:
{
size_t Top_oldret = ret;
ret = 0;
ret += length_POPOPrivKey(&(data)->u.keyEncipherment);
ret += 1 + der_length_len (ret);
ret += Top_oldret;
}
break;
case choice_ProofOfPossession_keyAgreement:
{
size_t Top_oldret = ret;
ret = 0;
ret += length_POPOPrivKey(&(data)->u.keyAgreement);
ret += 1 + der_length_len (ret);
ret += Top_oldret;
}
break;
}
return ret;
}

int ASN1CALL
copy_ProofOfPossession(const ProofOfPossession *from, ProofOfPossession *to)
{
memset(to, 0, sizeof(*to));
(to)->element = (from)->element;
switch((from)->element) {
case choice_ProofOfPossession_raVerified:
break;
case choice_ProofOfPossession_signature:
if(copy_POPOSigningKey(&(from)->u.signature, &(to)->u.signature)) goto fail;
break;
case choice_ProofOfPossession_keyEncipherment:
if(copy_POPOPrivKey(&(from)->u.keyEncipherment, &(to)->u.keyEncipherment)) goto fail;
break;
case choice_ProofOfPossession_keyAgreement:
if(copy_POPOPrivKey(&(from)->u.keyAgreement, &(to)->u.keyAgreement)) goto fail;
break;
}
return 0;
fail:
free_ProofOfPossession(to);
return ENOMEM;
}



