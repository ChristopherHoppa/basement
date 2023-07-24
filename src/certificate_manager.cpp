
#include "certificate_manager.h"

X509_REQ* CertificateManager::generateCSR(const std::string& subjectName, EVP_PKEY* publicKey){

}

void CertificateManager::storeCertificate(X509* certificate) {
    certificateRepository.push_back(certificate);
}

X509* CertificateManager::findCertificateBySubject(const std::string& subjectName) {
}

bool CertificateManager::isCertificateRevoked(const X509* certificate) {

}

void CertificateManager::addRevokedCertificateToCRL(const X509* certificate) {

    certificateRevocationList.push_back(certificate);
}
