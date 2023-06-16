#include <iostream>
#include <string>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>

int main()
{
    std::string plaintext = "Hello, World!";
    std::string password = "ThisIsAStrongPassword";

    // Encryption
    CryptoPP::SecByteBlock key(CryptoPP::AES::MAX_KEYLENGTH);
    CryptoPP::SecByteBlock iv(CryptoPP::AES::BLOCKSIZE);

    CryptoPP::AES::Encryption aesEncryption(reinterpret_cast<const byte*>(password.c_str()), CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);

    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext));
    stfEncryptor.Put(reinterpret_cast<const byte*>(plaintext.c_str()), plaintext.length() + 1);
    stfEncryptor.MessageEnd();

    std::string ciphertext;
    CryptoPP::ArraySink as(reinterpret_cast<byte*>(&ciphertext[0]), ciphertext.size());
    stfEncryptor.CopyTo(as);
    as.MessageEnd();

    std::cout << "Ciphertext: " << ciphertext << std::endl;

    // Decryption
    CryptoPP::AES::Decryption aesDecryption(reinterpret_cast<const byte*>(password.c_str()), CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);

    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(recoveredtext));
    stfDecryptor.Put(reinterpret_cast<const byte*>(ciphertext.c_str()), ciphertext.size());
    stfDecryptor.MessageEnd();

    std::string recoveredtext;
    stfDecryptor.CopyTo(reinterpret_cast<byte*>(&recoveredtext[0]), recoveredtext.size());

    std::cout << "Recovered plaintext: " << recoveredtext << std::endl;

    return 0;
}
