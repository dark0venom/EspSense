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
encode_POPOSigningKey(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const POPOSigningKey *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* signature */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_bit_string(p, len, &(data)->signature, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_BitString, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* algorithmIdentifier */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_AlgorithmIdentifier(p, len, &(data)->algorithmIdentifier, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* poposkInput */
if((data)->poposkInput) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_POPOSigningKeyInput(p, len, (data)->poposkInput, &l);
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
decode_POPOSigningKey(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, POPOSigningKey *data, size_t *size)
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
size_t poposkInput_datalen, poposkInput_oldlen;
Der_type poposkInput_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &poposkInput_type, 0, &poposkInput_datalen, &l);
if (e == 0 && poposkInput_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->poposkInput = NULL;
} else {
(data)->poposkInput = calloc(1, sizeof(*(data)->poposkInput));
if ((data)->poposkInput == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
poposkInput_oldlen = len;
if (poposkInput_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = poposkInput_datalen;
e = decode_POPOSigningKeyInput(p, len, (data)->poposkInput, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = poposkInput_oldlen - poposkInput_datalen;
}
}
e = decode_AlgorithmIdentifier(p, len, &(data)->algorithmIdentifier, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
{
size_t signature_datalen, signature_oldlen;
Der_type signature_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &signature_type, UT_BitString, &signature_datalen, &l);
if (e == 0 && signature_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
signature_oldlen = len;
if (signature_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = signature_datalen;
e = der_get_bit_string(p, len, &(data)->signature, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = signature_oldlen - signature_datalen;
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_POPOSigningKey(data);
return e;
}

void ASN1CALL
free_POPOSigningKey(POPOSigningKey *data)
{
if((data)->poposkInput) {
free_POPOSigningKeyInput((data)->poposkInput);
free((data)->poposkInput);
(data)->poposkInput = NULL;
}
free_AlgorithmIdentifier(&(data)->algorithmIdentifier);
der_free_bit_string(&(data)->signature);
}

size_t ASN1CALL
length_POPOSigningKey(const POPOSigningKey *data)
{
size_t ret = 0;
if((data)->poposkInput){
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_POPOSigningKeyInput((data)->poposkInput);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_AlgorithmIdentifier(&(data)->algorithmIdentifier);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_bit_string(&(data)->signature);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_POPOSigningKey(const POPOSigningKey *from, POPOSigningKey *to)
{
memset(to, 0, sizeof(*to));
if((from)->poposkInput) {
(to)->poposkInput = malloc(sizeof(*(to)->poposkInput));
if((to)->poposkInput == NULL) goto fail;
if(copy_POPOSigningKeyInput((from)->poposkInput, (to)->poposkInput)) goto fail;
}else
(to)->poposkInput = NULL;
if(copy_AlgorithmIdentifier(&(from)->algorithmIdentifier, &(to)->algorithmIdentifier)) goto fail;
if(der_copy_bit_string(&(from)->signature, &(to)->signature)) goto fail;
return 0;
fail:
free_POPOSigningKey(to);
return ENOMEM;
}



