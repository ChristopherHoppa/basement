
#ifndef CERTIFICATE_MANAGER_H
#define CERTIFICATE_MANAGER_H

#include <openssl/x509.h>
#include <vector>
#include <string>

class CertificateManager {
public:
    X509_REQ* generateCSR(const std::string& subjectName, EVP_PKEY* publicKey);

    void storeCertificate(X509* certificate);

    X509* findCertificateBySubject(const std::string& subjectName);

    bool isCertificateRevoked(const X509* certificate);

    void addRevokedCertificateToCRL(const X509* certificate);

private:
    std::vector<X509*> certificateRepository;
    std::vector<X509*> certificateRevocationList;
};

#endif 
