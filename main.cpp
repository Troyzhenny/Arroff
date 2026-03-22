#include <windows.h>
#include <iostream>
#include "terminal_colors.h"

bool IsAdmin() {
    BOOL isMember = FALSE;
    PSID adminSID = NULL;
    SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;

    AllocateAndInitializeSid(
        &ntAuthority,
        2,
        SECURITY_BUILTIN_DOMAIN_RID,
        DOMAIN_ALIAS_RID_ADMINS,
        0, 0, 0, 0, 0, 0,
        &adminSID
    );

    CheckTokenMembership(NULL, adminSID, &isMember);
    FreeSid(adminSID);
    return isMember == TRUE;
}

bool GetArrowState() {
    HKEY hKey;
    LONG result = RegOpenKeyExW(
        HKEY_LOCAL_MACHINE,
        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Icons",
        0, KEY_READ, &hKey
    );

    if (result != ERROR_SUCCESS) return false;

    DWORD type, size = 0;
    LONG queryResult = RegQueryValueExW(hKey, L"29", nullptr, &type, nullptr, &size);
    RegCloseKey(hKey);

    return queryResult == ERROR_SUCCESS;
}

void RemoveArrow() {
    HKEY hKey;
    RegCreateKeyExW(
        HKEY_LOCAL_MACHINE,
        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Icons",
        0, nullptr, 0, KEY_SET_VALUE, nullptr, &hKey, nullptr
    );
    RegSetValueExW(hKey, L"29", 0, REG_SZ, (const BYTE*)L"", sizeof(wchar_t));
    RegCloseKey(hKey);
}

void RestoreArrow() {
    HKEY hKey;
    RegOpenKeyExW(
        HKEY_LOCAL_MACHINE,
        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Icons",
        0, KEY_SET_VALUE, &hKey
    );
    RegDeleteValueW(hKey, L"29");
    RegCloseKey(hKey);
}

void RestartExplorer() {
    system("taskkill /f /im explorer.exe");
    Sleep(1000);
    ShellExecuteW(nullptr, L"open", L"explorer.exe", nullptr, nullptr, SW_SHOW);
}

int main() {
    if (!IsAdmin()) {
        std::cout << LIGHT_ORANGE << "Arroff needs to run as Administrator. Right-click and select 'Run as administrator'." << RESET << std::endl;
        system("pause");
        return 1;
    }

    bool arrowRemoved = GetArrowState();

    std::cout << LIGHT_BLUE << "Arroff - Shortcut Arrow Toggle" << RESET << std::endl;
    std::cout << LIGHT_BLUE << "------------------------------" << RESET << std::endl;
    std::cout << "Current state: " << (arrowRemoved ? LIGHT_BLUE "Arrow REMOVED" : LIGHT_ORANGE "Arrow PRESENT") << RESET << std::endl;
    std::cout << std::endl;

    if (arrowRemoved) {
        std::cout << "1) " << LIGHT_BLUE << "Restore arrow" << RESET << std::endl;
    } else {
        std::cout << "1) " << LIGHT_ORANGE << "Remove arrow" << RESET << std::endl;
    }

    std::cout << "2) Exit" << std::endl;
    std::cout << std::endl;
    std::cout << "Choice: ";

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        if (arrowRemoved) {
            RestoreArrow();
            std::cout << LIGHT_BLUE << "Arrow restored." << RESET << std::endl;
        } else {
            RemoveArrow();
            std::cout << LIGHT_ORANGE << "Arrow removed." << RESET << std::endl;
        }
        std::cout << "Restarting Explorer..." << std::endl;
        RestartExplorer();
        std::cout << LIGHT_BLUE << "Done." << RESET << std::endl;
    }

    system("pause");
    return 0;
}
