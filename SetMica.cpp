#include <Windows.h>
#include <dwmapi.h>
#include <cwchar>

int wmain (int argc, wchar_t ** argw) {
    if (argc >= 7) {
        auto classname = argw [2];
        auto backdrop = (DWM_SYSTEMBACKDROP_TYPE) std::wcstoul (argw [1], nullptr, 0);

        MARGINS margins = {
            (int) std::wcstol (argw [3], nullptr, 0),
            (int) std::wcstol (argw [4], nullptr, 0),
            (int) std::wcstol (argw [5], nullptr, 0),
            (int) std::wcstol (argw [6], nullptr, 0)
        };

        if (auto hWnd = FindWindowEx (NULL, NULL, classname, NULL)) {
            std::wprintf (L"window %p\n", hWnd);

            HRESULT hr = DwmExtendFrameIntoClientArea (hWnd, &margins);
            if (SUCCEEDED (hr)) {
                std::wprintf (L"window %p, extended frame to: %d %d, %d, %d\n",
                              hWnd, margins.cxLeftWidth, margins.cxRightWidth, margins.cyTopHeight, margins.cyBottomHeight);

                hr = DwmSetWindowAttribute (hWnd, DWMWA_SYSTEMBACKDROP_TYPE, &backdrop, sizeof backdrop);

                if (SUCCEEDED (hr)) {
                    std::wprintf (L"window %p, set backdrop to: %lu\n", hWnd, backdrop);

                    COLORREF clr = DWMWA_COLOR_NONE;
                    hr = DwmSetWindowAttribute (hWnd, DWMWA_CAPTION_COLOR, &clr, sizeof clr);

                    if (SUCCEEDED (hr)) {
                        std::wprintf (L"window %p, removed caption color\n", hWnd);

                    } else {
                        std::wprintf (L"failed DwmSetWindowAttribute (DWMWA_CAPTION_COLOR = DWMWA_COLOR_NONE) error %08X\n",  hr);
                    }
                } else {
                    std::wprintf (L"failed DwmSetWindowAttribute (DWMWA_SYSTEMBACKDROP_TYPE) %lu, error %08X\n", backdrop, hr);
                }
            } else {
                std::wprintf (L"failed DwmExtendFrameIntoClientArea %d %d, %d, %d, error %08X\n",
                              margins.cxLeftWidth, margins.cxRightWidth, margins.cyTopHeight, margins.cyBottomHeight,
                              hr);
            }
        } else {
            std::wprintf (L"no window of class %s\n", classname);
        }
    } else {
        std::wprintf (L"usage: %s iMica \"CLASSNAME\" pxLeft pxRight pxTop pxBottom\n", argw [0]);
    }
    return 0;
}
