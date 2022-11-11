// C++/WinRT v2.0.190620.2

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef WINRT_Windows_ApplicationModel_SocialInfo_Provider_1_H
#define WINRT_Windows_ApplicationModel_SocialInfo_Provider_1_H
#include "winrt/impl/Windows.ApplicationModel.SocialInfo.Provider.0.h"
namespace winrt::Windows::ApplicationModel::SocialInfo::Provider
{
    struct __declspec(empty_bases) ISocialDashboardItemUpdater :
        Windows::Foundation::IInspectable,
        impl::consume_t<ISocialDashboardItemUpdater>
    {
        ISocialDashboardItemUpdater(std::nullptr_t = nullptr) noexcept {}
        ISocialDashboardItemUpdater(void* ptr, take_ownership_from_abi_t) noexcept : Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISocialFeedUpdater :
        Windows::Foundation::IInspectable,
        impl::consume_t<ISocialFeedUpdater>
    {
        ISocialFeedUpdater(std::nullptr_t = nullptr) noexcept {}
        ISocialFeedUpdater(void* ptr, take_ownership_from_abi_t) noexcept : Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISocialInfoProviderManagerStatics :
        Windows::Foundation::IInspectable,
        impl::consume_t<ISocialInfoProviderManagerStatics>
    {
        ISocialInfoProviderManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ISocialInfoProviderManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif