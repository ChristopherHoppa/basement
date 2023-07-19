#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/x509_vfy.h>
#include <openssl/rsa.h>
#include <openssl/ssl.h>
#include <openssl/err.h>


X509* genSelfSignedCert() {

    X509* certificate = X509_new();
    X509_set_version(certificate, 2);
    RSA* rsaKey = RSA_generate_key(2048, RSA_F4, nullptr, nullptr);
    EVP_PKEY* privateKey = EVP_PKEY_new();
    EVP_PKEY_assign_RSA(privateKey, rsaKey);
    X509_set_pubkey(certificate, privateKey);
    X509_NAME* name = X509_NAME_new();
    X509_NAME_add_entry_by_txt(name, "CN", MBSTRING_ASC, (unsigned char*)"baseMENT", -1, -1, 0);
    X509_set_subject_name(certificate, name);
    X509_set_issuer_name(certificate, name);

    X509_gmtime_adj(X509_get_notBefore(certificate), 0);
    X509_gmtime_adj(X509_get_notAfter(certificate), 31536000L);  //= 1 year

    X509_sign(certificate, privateKey, EVP_sha256()); //signature

    EVP_PKEY_free(privateKey);
    X509_NAME_free(name);

    return certificate;


}