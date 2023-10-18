#include <windows.h>
#include <wincrypt.h>
#include <iostream>
#include <vector>

int wmain(int argc, wchar_t* argv[])
{
	HCERTSTORE hCertStore = CertOpenSystemStore(NULL, argc > 1 ? argv[1] : L"root");
	PCCERT_CONTEXT pCert = nullptr;

	while (pCert = CertEnumCertificatesInStore(hCertStore, pCert))
	{
		DWORD size = 0;

		CryptBinaryToString(pCert->pbCertEncoded, pCert->cbCertEncoded,
			CRYPT_STRING_BASE64HEADER,
			nullptr, &size);

		std::vector<wchar_t> pem(size);

		CryptBinaryToString(pCert->pbCertEncoded, pCert->cbCertEncoded,
			CRYPT_STRING_BASE64HEADER,
			pem.data(), &size);

		std::wcout << static_cast<wchar_t*>(pem.data());
	}

	CertCloseStore(hCertStore, 0);

	return 0;
}
