/* OpenSSH capabilities */

#cmakedefine OPENSSH_VERSION_MAJOR ${OPENSSH_VERSION_MAJOR}
#cmakedefine OPENSSH_VERSION_MINOR ${OPENSSH_VERSION_MINOR}

#cmakedefine OPENSSH_CIPHERS "${OPENSSH_CIPHERS}"
#cmakedefine OPENSSH_MACS "${OPENSSH_MACS}"
#cmakedefine OPENSSH_KEX "${OPENSSH_KEX}"
#cmakedefine OPENSSH_KEYS "${OPENSSH_KEYS}"


#cmakedefine OPENSSH_3DES_CBC 1
#cmakedefine OPENSSH_AES128_CBC 1
#cmakedefine OPENSSH_AES192_CBC 1
#cmakedefine OPENSSH_AES256_CBC 1
#cmakedefine OPENSSH_RIJNDAEL_CBC_LYSATOR_LIU_SE 1
#cmakedefine OPENSSH_AES128_CTR 1
#cmakedefine OPENSSH_AES192_CTR 1
#cmakedefine OPENSSH_AES256_CTR 1
#cmakedefine OPENSSH_AES128_GCM_OPENSSH_COM 1
#cmakedefine OPENSSH_AES256_GCM_OPENSSH_COM 1
#cmakedefine OPENSSH_CHACHA20_POLY1305_OPENSSH_COM 1
#cmakedefine OPENSSH_BLOWFISH_CBC 1
#cmakedefine OPENSSH_HMAC_SHA1 1
#cmakedefine OPENSSH_HMAC_SHA1_96 1
#cmakedefine OPENSSH_HMAC_SHA2_256 1
#cmakedefine OPENSSH_HMAC_SHA2_512 1
#cmakedefine OPENSSH_HMAC_MD5 1
#cmakedefine OPENSSH_HMAC_MD5_96 1
#cmakedefine OPENSSH_UMAC_64_OPENSSH_COM 1
#cmakedefine OPENSSH_UMAC_128_OPENSSH_COM 1
#cmakedefine OPENSSH_HMAC_SHA1_ETM_OPENSSH_COM 1
#cmakedefine OPENSSH_HMAC_SHA1_96_ETM_OPENSSH_COM 1
#cmakedefine OPENSSH_HMAC_SHA2_256_ETM_OPENSSH_COM 1
#cmakedefine OPENSSH_HMAC_SHA2_512_ETM_OPENSSH_COM 1
#cmakedefine OPENSSH_HMAC_MD5_ETM_OPENSSH_COM 1
#cmakedefine OPENSSH_HMAC_MD5_96_ETM_OPENSSH_COM 1
#cmakedefine OPENSSH_UMAC_64_ETM_OPENSSH_COM 1
#cmakedefine OPENSSH_UMAC_128_ETM_OPENSSH_COM 1
#cmakedefine OPENSSH_DIFFIE_HELLMAN_GROUP1_SHA1 1
#cmakedefine OPENSSH_DIFFIE_HELLMAN_GROUP14_SHA1 1
#cmakedefine OPENSSH_DIFFIE_HELLMAN_GROUP14_SHA256 1
#cmakedefine OPENSSH_DIFFIE_HELLMAN_GROUP16_SHA512 1
#cmakedefine OPENSSH_DIFFIE_HELLMAN_GROUP18_SHA512 1
#cmakedefine OPENSSH_DIFFIE_HELLMAN_GROUP_EXCHANGE_SHA1 1
#cmakedefine OPENSSH_DIFFIE_HELLMAN_GROUP_EXCHANGE_SHA256 1
#cmakedefine OPENSSH_ECDH_SHA2_NISTP256 1
#cmakedefine OPENSSH_ECDH_SHA2_NISTP384 1
#cmakedefine OPENSSH_ECDH_SHA2_NISTP521 1
#cmakedefine OPENSSH_CURVE25519_SHA256 1
#cmakedefine OPENSSH_CURVE25519_SHA256_LIBSSH_ORG 1
#cmakedefine OPENSSH_SSH_ED25519 1
#cmakedefine OPENSSH_SSH_ED25519_CERT_V01_OPENSSH_COM 1
#cmakedefine OPENSSH_SSH_RSA 1
#cmakedefine OPENSSH_ECDSA_SHA2_NISTP256 1
#cmakedefine OPENSSH_ECDSA_SHA2_NISTP384 1
#cmakedefine OPENSSH_ECDSA_SHA2_NISTP521 1
#cmakedefine OPENSSH_SSH_RSA_CERT_V01_OPENSSH_COM 1
#cmakedefine OPENSSH_ECDSA_SHA2_NISTP256_CERT_V01_OPENSSH_COM 1
#cmakedefine OPENSSH_ECDSA_SHA2_NISTP384_CERT_V01_OPENSSH_COM 1
#cmakedefine OPENSSH_ECDSA_SHA2_NISTP521_CERT_V01_OPENSSH_COM 1

/* Available programs */

#cmakedefine NCAT_EXECUTABLE "${NCAT_EXECUTABLE}"
#cmakedefine SSHD_EXECUTABLE "${SSHD_EXECUTABLE}"
#cmakedefine SSH_EXECUTABLE "${SSH_EXECUTABLE}"
#cmakedefine WITH_TIMEOUT ${WITH_TIMEOUT}
#cmakedefine TIMEOUT_EXECUTABLE "${TIMEOUT_EXECUTABLE}"
#cmakedefine SOFTHSM2_LIBRARY "${SOFTHSM2_LIBRARY}"
#cmakedefine PKCS11SPY "${PKCS11SPY}"
