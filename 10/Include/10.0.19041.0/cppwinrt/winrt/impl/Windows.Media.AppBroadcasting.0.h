// C++/WinRT v2.0.190620.2

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef WINRT_Windows_Media_AppBroadcasting_0_H
#define WINRT_Windows_Media_AppBroadcasting_0_H
namespace winrt::Windows::Foundation
{
    struct EventRegistrationToken;
    template <typename TSender, typename TResult> struct TypedEventHandler;
}
namespace winrt::Windows::System
{
    struct User;
}
namespace winrt::Windows::Media::AppBroadcasting
{
    struct IAppBroadcastingMonitor;
    struct IAppBroadcastingStatus;
    struct IAppBroadcastingStatusDetails;
    struct IAppBroadcastingUI;
    struct IAppBroadcastingUIStatics;
    struct AppBroadcastingMonitor;
    struct AppBroadcastingStatus;
    struct AppBroadcastingStatusDetails;
    struct AppBroadcastingUI;
}
namespace winrt::impl
{
    template <> struct category<Windows::Media::AppBroadcasting::IAppBroadcastingMonitor>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Media::AppBroadcasting::IAppBroadcastingStatus>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Media::AppBroadcasting::IAppBroadcastingStatusDetails>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Media::AppBroadcasting::IAppBroadcastingUI>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Media::AppBroadcasting::IAppBroadcastingUIStatics>
    {
        using type = interface_category;
    };
    template <> struct category<Windows::Media::AppBroadcasting::AppBroadcastingMonitor>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Media::AppBroadcasting::AppBroadcastingStatus>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Media::AppBroadcasting::AppBroadcastingStatusDetails>
    {
        using type = class_category;
    };
    template <> struct category<Windows::Media::AppBroadcasting::AppBroadcastingUI>
    {
        using type = class_category;
    };
    template <> struct name<Windows::Media::AppBroadcasting::IAppBroadcastingMonitor>
    {
        static constexpr auto & value{ L"Windows.Media.AppBroadcasting.IAppBroadcastingMonitor" };
    };
    template <> struct name<Windows::Media::AppBroadcasting::IAppBroadcastingStatus>
    {
        static constexpr auto & value{ L"Windows.Media.AppBroadcasting.IAppBroadcastingStatus" };
    };
    template <> struct name<Windows::Media::AppBroadcasting::IAppBroadcastingStatusDetails>
    {
        static constexpr auto & value{ L"Windows.Media.AppBroadcasting.IAppBroadcastingStatusDetails" };
    };
    template <> struct name<Windows::Media::AppBroadcasting::IAppBroadcastingUI>
    {
        static constexpr auto & value{ L"Windows.Media.AppBroadcasting.IAppBroadcastingUI" };
    };
    template <> struct name<Windows::Media::AppBroadcasting::IAppBroadcastingUIStatics>
    {
        static constexpr auto & value{ L"Windows.Media.AppBroadcasting.IAppBroadcastingUIStatics" };
    };
    template <> struct name<Windows::Media::AppBroadcasting::AppBroadcastingMonitor>
    {
        static constexpr auto & value{ L"Windows.Media.AppBroadcasting.AppBroadcastingMonitor" };
    };
    template <> struct name<Windows::Media::AppBroadcasting::AppBroadcastingStatus>
    {
        static constexpr auto & value{ L"Windows.Media.AppBroadcasting.AppBroadcastingStatus" };
    };
    template <> struct name<Windows::Media::AppBroadcasting::AppBroadcastingStatusDetails>
    {
        static constexpr auto & value{ L"Windows.Media.AppBroadcasting.AppBroadcastingStatusDetails" };
    };
    template <> struct name<Windows::Media::AppBroadcasting::AppBroadcastingUI>
    {
        static constexpr auto & value{ L"Windows.Media.AppBroadcasting.AppBroadcastingUI" };
    };
    template <> struct guid_storage<Windows::Media::AppBroadcasting::IAppBroadcastingMonitor>
    {
        static constexpr guid value{ 0x00F95A68,0x8907,0x48A0,{ 0xB8,0xEF,0x24,0xD2,0x08,0x13,0x75,0x42 } };
    };
    template <> struct guid_storage<Windows::Media::AppBroadcasting::IAppBroadcastingStatus>
    {
        static constexpr guid value{ 0x1225E4DF,0x03A1,0x42F8,{ 0x8B,0x80,0xC9,0x22,0x8C,0xD9,0xCF,0x2E } };
    };
    template <> struct guid_storage<Windows::Media::AppBroadcasting::IAppBroadcastingStatusDetails>
    {
        static constexpr guid value{ 0x069DADA4,0xB573,0x4E3C,{ 0x8E,0x19,0x1B,0xAF,0xAC,0xD0,0x97,0x13 } };
    };
    template <> struct guid_storage<Windows::Media::AppBroadcasting::IAppBroadcastingUI>
    {
        static constexpr guid value{ 0xE56F9F8F,0xEE99,0x4DCA,{ 0xA3,0xC3,0x70,0xAF,0x3D,0xB4,0x4F,0x5F } };
    };
    template <> struct guid_storage<Windows::Media::AppBroadcasting::IAppBroadcastingUIStatics>
    {
        static constexpr guid value{ 0x55A8A79D,0x23CB,0x4579,{ 0x9C,0x34,0x88,0x6F,0xE0,0x2C,0x04,0x5A } };
    };
    template <> struct default_interface<Windows::Media::AppBroadcasting::AppBroadcastingMonitor>
    {
        using type = Windows::Media::AppBroadcasting::IAppBroadcastingMonitor;
    };
    template <> struct default_interface<Windows::Media::AppBroadcasting::AppBroadcastingStatus>
    {
        using type = Windows::Media::AppBroadcasting::IAppBroadcastingStatus;
    };
    template <> struct default_interface<Windows::Media::AppBroadcasting::AppBroadcastingStatusDetails>
    {
        using type = Windows::Media::AppBroadcasting::IAppBroadcastingStatusDetails;
    };
    template <> struct default_interface<Windows::Media::AppBroadcasting::AppBroadcastingUI>
    {
        using type = Windows::Media::AppBroadcasting::IAppBroadcastingUI;
    };
    template <> struct abi<Windows::Media::AppBroadcasting::IAppBroadcastingMonitor>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsCurrentAppBroadcasting(bool*) noexcept = 0;
            virtual int32_t __stdcall add_IsCurrentAppBroadcastingChanged(void*, winrt::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_IsCurrentAppBroadcastingChanged(winrt::event_token) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Media::AppBroadcasting::IAppBroadcastingStatus>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CanStartBroadcast(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Details(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Media::AppBroadcasting::IAppBroadcastingStatusDetails>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsAnyAppBroadcasting(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsCaptureResourceUnavailable(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsGameStreamInProgress(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsGpuConstrained(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsAppInactive(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsBlockedForApp(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsDisabledByUser(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsDisabledBySystem(bool*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Media::AppBroadcasting::IAppBroadcastingUI>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetStatus(void**) noexcept = 0;
            virtual int32_t __stdcall ShowBroadcastUI() noexcept = 0;
        };
    };
    template <> struct abi<Windows::Media::AppBroadcasting::IAppBroadcastingUIStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
            virtual int32_t __stdcall GetForUser(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_AppBroadcasting_IAppBroadcastingMonitor
    {
        [[nodiscard]] auto IsCurrentAppBroadcasting() const;
        auto IsCurrentAppBroadcastingChanged(Windows::Foundation::TypedEventHandler<Windows::Media::AppBroadcasting::AppBroadcastingMonitor, Windows::Foundation::IInspectable> const& handler) const;
        using IsCurrentAppBroadcastingChanged_revoker = impl::event_revoker<Windows::Media::AppBroadcasting::IAppBroadcastingMonitor, &impl::abi_t<Windows::Media::AppBroadcasting::IAppBroadcastingMonitor>::remove_IsCurrentAppBroadcastingChanged>;
        IsCurrentAppBroadcastingChanged_revoker IsCurrentAppBroadcastingChanged(auto_revoke_t, Windows::Foundation::TypedEventHandler<Windows::Media::AppBroadcasting::AppBroadcastingMonitor, Windows::Foundation::IInspectable> const& handler) const;
        auto IsCurrentAppBroadcastingChanged(winrt::event_token const& token) const noexcept;
    };
    template <> struct consume<Windows::Media::AppBroadcasting::IAppBroadcastingMonitor>
    {
        template <typename D> using type = consume_Windows_Media_AppBroadcasting_IAppBroadcastingMonitor<D>;
    };
    template <typename D>
    struct consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatus
    {
        [[nodiscard]] auto CanStartBroadcast() const;
        [[nodiscard]] auto Details() const;
    };
    template <> struct consume<Windows::Media::AppBroadcasting::IAppBroadcastingStatus>
    {
        template <typename D> using type = consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatus<D>;
    };
    template <typename D>
    struct consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatusDetails
    {
        [[nodiscard]] auto IsAnyAppBroadcasting() const;
        [[nodiscard]] auto IsCaptureResourceUnavailable() const;
        [[nodiscard]] auto IsGameStreamInProgress() const;
        [[nodiscard]] auto IsGpuConstrained() const;
        [[nodiscard]] auto IsAppInactive() const;
        [[nodiscard]] auto IsBlockedForApp() const;
        [[nodiscard]] auto IsDisabledByUser() const;
        [[nodiscard]] auto IsDisabledBySystem() const;
    };
    template <> struct consume<Windows::Media::AppBroadcasting::IAppBroadcastingStatusDetails>
    {
        template <typename D> using type = consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatusDetails<D>;
    };
    template <typename D>
    struct consume_Windows_Media_AppBroadcasting_IAppBroadcastingUI
    {
        auto GetStatus() const;
        auto ShowBroadcastUI() const;
    };
    template <> struct consume<Windows::Media::AppBroadcasting::IAppBroadcastingUI>
    {
        template <typename D> using type = consume_Windows_Media_AppBroadcasting_IAppBroadcastingUI<D>;
    };
    template <typename D>
    struct consume_Windows_Media_AppBroadcasting_IAppBroadcastingUIStatics
    {
        auto GetDefault() const;
        auto GetForUser(Windows::System::User const& user) const;
    };
    template <> struct consume<Windows::Media::AppBroadcasting::IAppBroadcastingUIStatics>
    {
        template <typename D> using type = consume_Windows_Media_AppBroadcasting_IAppBroadcastingUIStatics<D>;
    };
}
#endif
