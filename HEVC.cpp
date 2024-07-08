#include <windows.h>
#include <cmath>
#include <math.h>
DWORD random() {
	DWORD number = __rdtsc();
	
	number ^= number << 13;
	number ^= number << 17;
	number ^= number << 5;

	return number;
}
DWORD WINAPI spin(LPVOID lpstart) {
	HDC hdc = GetDC(0);
	RECT rekt;
	POINT rotate[3];

	while (true) {
		int rnd = random() % 65 + 60;

		for (int i = 0; i < rnd; i += 20) {
			GetWindowRect(GetDesktopWindow(), &rekt);

			rotate[0].x = rekt.left + i;
			rotate[0].y = rekt.top - i;
			rotate[1].x = rekt.right + i;
			rotate[1].y = rekt.top + i;
			rotate[2].x = rekt.left - i;
			rotate[2].y = rekt.bottom - i;

			PlgBlt(hdc, rotate, hdc, 0, 0, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
			Sleep(40);
		}
	}
}

DWORD WINAPI transpire(LPVOID lpParam)
{
    int hSrc;
    int wSrc;
    HDC hdcDest;
    GetDC(0);
    wSrc = GetSystemMetrics(0);
    for (hSrc = GetSystemMetrics(1);
        ;
        StretchBlt(hdcDest, -10, -10, wSrc + 20, hSrc + 20, hdcDest, 0, 0, wSrc, hSrc, 0xCC0020u))
    {
        hdcDest = GetDC(0);
        (hdcDest, 4);
        StretchBlt(hdcDest, 10, 10, wSrc - 20, hSrc - 20, hdcDest, 0, 0, wSrc, hSrc, 0xCC0020u);
    }
}

DWORD WINAPI dupe(LPVOID lpParam)
{
	HDC hdc = GetDC(HWND_DESKTOP);
	int X = GetSystemMetrics(SM_CXSCREEN);
	int Y = GetSystemMetrics(SM_CYSCREEN);
	
	while (TRUE)
	{
		HDC hdc = GetDC(HWND_DESKTOP);
		int X = GetSystemMetrics(SM_CXSCREEN);
		int Y = GetSystemMetrics(SM_CYSCREEN);
		BitBlt(hdc, rand() % (X - 0), rand() % (Y - 0), rand() % (X - 0), rand() % (Y - 0), hdc, rand() % (X - 0), rand() % (Y - 0), 0x999999);
		Sleep(10); // to prevent memleak
	}
}

DWORD WINAPI proctatic(LPVOID lpParam)
{
	HDC hdc = GetDC(0);
    RECT wRect;
    POINT wPt[3];
    while (1)
    {
    GetWindowRect(GetDesktopWindow(), &wRect);
    wPt[0].x = wRect.left + 71 + 1;
    wPt[0].y = wRect.top + 12 + 30;
    wPt[1].x = wRect.right + 18 + 5;
    wPt[1].y = wRect.top + 71 + 16;
    wPt[2].x = wRect.left - 15 - 34;
    wPt[2].y = wRect.bottom - 62 - 10;
    PlgBlt(hdc, wPt, hdc, wRect.left, wRect.top, wRect.right - wRect.left, wRect.bottom - wRect.top, 0, 0, 0);
    }
}

int main () {
	Sleep(3000);
	if (MessageBoxW(NULL, L"This malware is safety, continue", L"HEVC", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
	{
		ExitProcess(0);
	}
	else
	{
		if (MessageBoxW(NULL, L"Are you sure", L"HEVC", MB_YESNO | MB_ICONQUESTION) == IDNO)
		{
			ExitProcess(0);
		}
		else
	
	Sleep(2000);
	{
		HANDLE thread1 = CreateThread(0, 0, spin, 0, 0, 0);
		HANDLE thread2 = CreateThread(0, 0, transpire, 0, 0, 0);
		Sleep(15000);
		TerminateThread(thread1, 0);
		TerminateThread(thread2, 0);
		CloseHandle(thread1);
	InvalidateRect(0, 0, 0);	
		CloseHandle(thread2);
	InvalidateRect(0, 0, 0);	
	Sleep(1000);
		HANDLE thread3 = CreateThread(0, 0, dupe, 0, 0, 0);
		Sleep(15000);
		TerminateThread(thread3, 0);
		CloseHandle(thread3);
	InvalidateRect(0, 0, 0);
	Sleep(1000);	
		HANDLE thread4 = CreateThread(0, 0, proctatic, 0, 0, 0);
		Sleep(15000);
		TerminateThread(thread4, 0);
		CloseHandle(thread4);
	InvalidateRect(0, 0, 0);	
		HANDLE thread5 = CreateThread(0, 0, spin, 0, 0, 0);
		HANDLE thread6 = CreateThread(0, 0, transpire, 0, 0, 0);
		HANDLE thread7 = CreateThread(0, 0, dupe, 0, 0, 0);
		HANDLE thread8 = CreateThread(0, 0, proctatic, 0, 0, 0);
		Sleep(15000);
	}
}
}
