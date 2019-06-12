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
encode_OCSPSignature(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const OCSPSignature *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* certs */
if((data)->certs) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
for(i = (int)((data)->certs)->len - 1; i >= 0; --i) {
size_t certs_tag_tag_for_oldret = ret;
ret = 0;
e = encode_Certificate(p, len, &((data)->certs)->val[i], &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += certs_tag_tag_for_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, CONS, UT_Sequence, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 0, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
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
/* signatureAlgorithm */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_AlgorithmIdentifier(p, len, &(data)->signatureAlgorithm, &l);
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
decode_OCSPSignature(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, OCSPSignature *data, size_t *size)
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
e = decode_AlgorithmIdentifier(p, len, &(data)->signatureAlgorithm, &l);
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
{
size_t certs_datalen, certs_oldlen;
Der_type certs_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &certs_type, 0, &certs_datalen, &l);
if (e == 0 && certs_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->certs = NULL;
} else {
(data)->certs = calloc(1, sizeof(*(data)->certs));
if ((data)->certs == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
certs_oldlen = len;
if (certs_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = certs_datalen;
{
size_t certs_Tag_datalen, certs_Tag_oldlen;
Der_type certs_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &certs_Tag_type, UT_Sequence, &certs_Tag_datalen, &l);
if (e == 0 && certs_Tag_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
certs_Tag_oldlen = len;
if (certs_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = certs_Tag_datalen;
{
size_t certs_Tag_Tag_origlen = len;
size_t certs_Tag_Tag_oldret = ret;
size_t certs_Tag_Tag_olen = 0;
void *certs_Tag_Tag_tmp;
ret = 0;
((data)->certs)->len = 0;
((data)->certs)->val = NULL;
while(ret < certs_Tag_Tag_origlen) {
size_t certs_Tag_Tag_nlen = certs_Tag_Tag_olen + sizeof(*(((data)->certs)->val));
if (certs_Tag_Tag_olen > certs_Tag_Tag_nlen) { e = ASN1_OVERFLOW; goto fail; }
certs_Tag_Tag_olen = certs_Tag_Tag_nlen;
certs_Tag_Tag_tmp = realloc(((data)->certs)->val, certs_Tag_Tag_olen);
if (certs_Tag_Tag_tmp == NULL) { e = ENOMEM; goto fail; }
((data)->certs)->val = certs_Tag_Tag_tmp;
e = decode_Certificate(p, len, &((data)->certs)->val[((data)->certs)->len], &l);
if(e) goto fail;
p += l; len -= l; ret += l;
((data)->certs)->len++;
len = certs_Tag_Tag_origlen - ret;
}
ret += certs_Tag_Tag_oldret;
}
len = certs_Tag_oldlen - certs_Tag_datalen;
}
len = certs_oldlen - certs_datalen;
}
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_OCSPSignature(data);
return e;
}

void ASN1CALL
free_OCSPSignature(OCSPSignature *data)
{
free_AlgorithmIdentifier(&(data)->signatureAlgorithm);
der_free_bit_string(&(data)->signature);
if((data)->certs) {
while(((data)->certs)->len){
free_Certificate(&((data)->certs)->val[((data)->certs)->len-1]);
((data)->certs)->len--;
}
free(((data)->certs)->val);
((data)->certs)->val = NULL;
free((data)->certs);
(data)->certs = NULL;
}
}

size_t ASN1CALL
length_OCSPSignature(const OCSPSignature *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_AlgorithmIdentifier(&(data)->signatureAlgorithm);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_bit_string(&(data)->signature);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->certs){
size_t Top_tag_oldret = ret;
ret = 0;
{
size_t certs_tag_tag_oldret = ret;
int i;
ret = 0;
for(i = ((data)->certs)->len - 1; i >= 0; --i){
size_t certs_tag_tag_for_oldret = ret;
ret = 0;
ret += length_Certificate(&((data)->certs)->val[i]);
ret += certs_tag_tag_for_oldret;
}
ret += certs_tag_tag_oldret;
}
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_OCSPSignature(const OCSPSignature *from, OCSPSignature *to)
{
memset(to, 0, sizeof(*to));
if(copy_AlgorithmIdentifier(&(from)->signatureAlgorithm, &(to)->signatureAlgorithm)) goto fail;
if(der_copy_bit_string(&(from)->signature, &(to)->signature)) goto fail;
if((from)->certs) {
(to)->certs = malloc(sizeof(*(to)->certs));
if((to)->certs == NULL) goto fail;
if((((to)->certs)->val = malloc(((from)->certs)->len * sizeof(*((to)->certs)->val))) == NULL && ((from)->certs)->len != 0)
goto fail;
for(((to)->certs)->len = 0; ((to)->certs)->len < ((from)->certs)->len; ((to)->certs)->len++){
if(copy_Certificate(&((from)->certs)->val[((to)->certs)->len], &((to)->certs)->val[((to)->certs)->len])) goto fail;
}
}else
(to)->certs = NULL;
return 0;
fail:
free_OCSPSignature(to);
return ENOMEM;
}



