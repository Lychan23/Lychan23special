using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;

public class AESEncryptionApp
{
    private static byte[] EncryptStringToBytes(string plainText, byte[] key, byte[] iv)
    {
        using (Aes aesAlg = Aes.Create())
        {
            aesAlg.Key = key;
            aesAlg.IV = iv;

            ICryptoTransform encryptor = aesAlg.CreateEncryptor(aesAlg.Key, aesAlg.IV);

            using (MemoryStream msEncrypt = new MemoryStream())
            {
                using (CryptoStream csEncrypt = new CryptoStream(msEncrypt, encryptor, CryptoStreamMode.Write))
                {
                    using (StreamWriter swEncrypt = new StreamWriter(csEncrypt))
                    {
                        swEncrypt.Write(plainText);
                    }
                    return msEncrypt.ToArray();
                }
            }
        }
    }

    private static string DecryptStringFromBytes(byte[] cipherText, byte[] key, byte[] iv)
    {
        using (Aes aesAlg = Aes.Create())
        {
            aesAlg.Key = key;
            aesAlg.IV = iv;

            ICryptoTransform decryptor = aesAlg.CreateDecryptor(aesAlg.Key, aesAlg.IV);

            using (MemoryStream msDecrypt = new MemoryStream(cipherText))
            {
                using (CryptoStream csDecrypt = new CryptoStream(msDecrypt, decryptor, CryptoStreamMode.Read))
                {
                    using (StreamReader srDecrypt = new StreamReader(csDecrypt))
                    {
                        return srDecrypt.ReadToEnd();
                    }
                }
            }
        }
    }

    public static void Main()
    {
        string originalText = "Hello, AES!";
        byte[] key = Encoding.UTF8.GetBytes("0123456789ABCDEF");
        byte[] iv = Encoding.UTF8.GetBytes("ABCDEF0123456789");

        byte[] encryptedBytes = EncryptStringToBytes(originalText, key, iv);
        string decryptedText = DecryptStringFromBytes(encryptedBytes, key, iv);

        Console.WriteLine("Original: " + originalText);
        Console.WriteLine("Encrypted: " + Convert.ToBase64String(encryptedBytes));
        Console.WriteLine("Decrypted: " + decryptedText);
    }
}
