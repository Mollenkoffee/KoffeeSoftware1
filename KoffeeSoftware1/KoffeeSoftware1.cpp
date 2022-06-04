// KoffeeSoftware1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

using std::cout;
using std::endl;

// 1. Counter-Strike: Global Offensive - Direct3D 9
LPCSTR applicationName = "Counter-Strike: Global Offensive - Direct3D 9";

int main()
{
    cout << "-> KoffeeSoftware1" << endl;

    HWND applicationWindow = FindWindowA(NULL, applicationName);
    if (applicationWindow == NULL)
    {
        cout << "-> searching for applicationWindow" << endl;
        while (applicationWindow == NULL)
        {
            applicationWindow = FindWindowA(NULL, applicationName);
        }
    }
    if (applicationWindow != NULL)
    {
        cout << "-> applicationWindow found" << endl;
        cout << "-> " << applicationWindow << endl;

        DWORD processId = GetWindowThreadProcessId(applicationWindow, &processId);
        HANDLE applicationHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);

        if (processId == NULL)
        {
            cout << "-> searching for processId";
            while (processId == NULL)
            {
                processId = GetWindowThreadProcessId(applicationWindow, &processId);
                applicationHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
            }
        }
        if (processId != NULL)
        {
            cout << "-> processId found" << endl;
            cout << "-> " << processId << endl;

            /* 
            
            read/write memory example

            int sampleValue;
            WriteProcessMemory(applicationHandle, (LPVOID)0x00AAAAAA, &sampleValue, sizeof(sampleValue), 0);
            ReadProcessMemory(applicationHandle, (PBYTE*)0x00AAAAAA, &sampleValue, sizeof(sampleValue), 0);

            */
        }
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
