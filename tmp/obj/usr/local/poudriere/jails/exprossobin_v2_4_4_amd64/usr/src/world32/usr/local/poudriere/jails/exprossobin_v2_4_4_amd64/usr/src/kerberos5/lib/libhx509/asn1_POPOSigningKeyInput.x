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
encode_POPOSigningKeyInput(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const POPOSigningKeyInput *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* publicKey */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_SubjectPublicKeyInfo(p, len, &(data)->publicKey, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* authInfo */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;

switch((&(data)->authInfo)->element) {
case choice_POPOSigningKeyInput_authInfo_publicKeyMAC: {size_t authInfo_oldret = ret;
ret = 0;
e = encode_PKMACValue(p, len, &((&(data)->authInfo))->u.publicKeyMAC, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += authInfo_oldret;
break;
}
case choice_POPOSigningKeyInput_authInfo_sender: {size_t authInfo_oldret = ret;
ret = 0;
e = encode_GeneralName(p, len, &((&(data)->authInfo))->u.sender, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 0, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += authInfo_oldret;
break;
}
};
ret += Top_tag_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, CONS, UT_Sequence, &l);
if (e) return e;
p -= l; len -= l; ret += l;

*size = ret;
return 0;
}

int ASN1CALL
decode_POPOSigningKeyInput(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, POPOSigningKeyInput *data, size_t *size)
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
if (der_match_tag(p, len, ASN1_C_CONTEXT, CONS, 0, NULL) == 0) {
{
size_t sender_datalen, sender_oldlen;
Der_type sender_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &sender_type, 0, &sender_datalen, &l);
if (e == 0 && sender_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
sender_oldlen = len;
if (sender_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = sender_datalen;
e = decode_GeneralName(p, len, &(&(data)->authInfo)->u.sender, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = sender_oldlen - sender_datalen;
}
(&(data)->authInfo)->element = choice_POPOSigningKeyInput_authInfo_sender;
}
else if (der_match_tag(p, len, ASN1_C_UNIV, CONS, UT_Sequence, NULL) == 0) {
e = decode_PKMACValue(p, len, &(&(data)->authInfo)->u.publicKeyMAC, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
(&(data)->authInfo)->element = choice_POPOSigningKeyInput_authInfo_publicKeyMAC;
}
else {
e = ASN1_PARSE_ERROR;
goto fail;
}
e = decode_SubjectPublicKeyInfo(p, len, &(data)->publicKey, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_POPOSigningKeyInput(data);
return e;
}

void ASN1CALL
free_POPOSigningKeyInput(POPOSigningKeyInput *data)
{
switch((&(data)->authInfo)->element) {
case choice_POPOSigningKeyInput_authInfo_sender:
free_GeneralName(&(&(data)->authInfo)->u.sender);
break;
case choice_POPOSigningKeyInput_authInfo_publicKeyMAC:
free_PKMACValue(&(&(data)->authInfo)->u.publicKeyMAC);
break;
}
free_SubjectPublicKeyInfo(&(data)->publicKey);
}

size_t ASN1CALL
length_POPOSigningKeyInput(const POPOSigningKeyInput *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
switch((&(data)->authInfo)->element) {
case choice_POPOSigningKeyInput_authInfo_sender:
{
size_t authInfo_oldret = ret;
ret = 0;
ret += length_GeneralName(&(&(data)->authInfo)->u.sender);
ret += 1 + der_length_len (ret);
ret += authInfo_oldret;
}
break;
case choice_POPOSigningKeyInput_authInfo_publicKeyMAC:
{
size_t authInfo_oldret = ret;
ret = 0;
ret += length_PKMACValue(&(&(data)->authInfo)->u.publicKeyMAC);
ret += authInfo_oldret;
}
break;
}
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_SubjectPublicKeyInfo(&(data)->publicKey);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_POPOSigningKeyInput(const POPOSigningKeyInput *from, POPOSigningKeyInput *to)
{
memset(to, 0, sizeof(*to));
(&(to)->authInfo)->element = (&(from)->authInfo)->element;
switch((&(from)->authInfo)->element) {
case choice_POPOSigningKeyInput_authInfo_sender:
if(copy_GeneralName(&(&(from)->authInfo)->u.sender, &(&(to)->authInfo)->u.sender)) goto fail;
break;
case choice_POPOSigningKeyInput_authInfo_publicKeyMAC:
if(copy_PKMACValue(&(&(from)->authInfo)->u.publicKeyMAC, &(&(to)->authInfo)->u.publicKeyMAC)) goto fail;
break;
}
if(copy_SubjectPublicKeyInfo(&(from)->publicKey, &(to)->publicKey)) goto fail;
return 0;
fail:
free_POPOSigningKeyInput(to);
return ENOMEM;
}



