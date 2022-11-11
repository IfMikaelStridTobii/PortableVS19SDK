// C++/WinRT v2.0.190620.2

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef WINRT_Windows_Devices_Scanners_H
#define WINRT_Windows_Devices_Scanners_H
#include "winrt/base.h"
static_assert(winrt::check_version(CPPWINRT_VERSION, "2.0.190620.2"), "Mismatched C++/WinRT headers.");
#include "winrt/Windows.Devices.h"
#include "winrt/impl/Windows.Foundation.2.h"
#include "winrt/impl/Windows.Foundation.Collections.2.h"
#include "winrt/impl/Windows.Graphics.Printing.2.h"
#include "winrt/impl/Windows.Storage.2.h"
#include "winrt/impl/Windows.Storage.Streams.2.h"
#include "winrt/impl/Windows.Devices.Scanners.2.h"
namespace winrt::impl
{
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScanner<D>::DeviceId() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScanner)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScanner<D>::DefaultScanSource() const
    {
        Windows::Devices::Scanners::ImageScannerScanSource value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScanner)->get_DefaultScanSource(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScanner<D>::IsScanSourceSupported(Windows::Devices::Scanners::ImageScannerScanSource const& value) const
    {
        bool result;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScanner)->IsScanSourceSupported(static_cast<int32_t>(value), &result));
        return result;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScanner<D>::FlatbedConfiguration() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScanner)->get_FlatbedConfiguration(&value));
        return Windows::Devices::Scanners::ImageScannerFlatbedConfiguration{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScanner<D>::FeederConfiguration() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScanner)->get_FeederConfiguration(&value));
        return Windows::Devices::Scanners::ImageScannerFeederConfiguration{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScanner<D>::AutoConfiguration() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScanner)->get_AutoConfiguration(&value));
        return Windows::Devices::Scanners::ImageScannerAutoConfiguration{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScanner<D>::IsPreviewSupported(Windows::Devices::Scanners::ImageScannerScanSource const& scanSource) const
    {
        bool result;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScanner)->IsPreviewSupported(static_cast<int32_t>(scanSource), &result));
        return result;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScanner<D>::ScanPreviewToStreamAsync(Windows::Devices::Scanners::ImageScannerScanSource const& scanSource, Windows::Storage::Streams::IRandomAccessStream const& targetStream) const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScanner)->ScanPreviewToStreamAsync(static_cast<int32_t>(scanSource), *(void**)(&targetStream), &operation));
        return Windows::Foundation::IAsyncOperation<Windows::Devices::Scanners::ImageScannerPreviewResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScanner<D>::ScanFilesToFolderAsync(Windows::Devices::Scanners::ImageScannerScanSource const& scanSource, Windows::Storage::StorageFolder const& storageFolder) const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScanner)->ScanFilesToFolderAsync(static_cast<int32_t>(scanSource), *(void**)(&storageFolder), &operation));
        return Windows::Foundation::IAsyncOperationWithProgress<Windows::Devices::Scanners::ImageScannerScanResult, uint32_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::CanAutoDetectPageSize() const
    {
        bool value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFeederConfiguration)->get_CanAutoDetectPageSize(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::AutoDetectPageSize() const
    {
        bool value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFeederConfiguration)->get_AutoDetectPageSize(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::AutoDetectPageSize(bool value) const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFeederConfiguration)->put_AutoDetectPageSize(value));
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::PageSize() const
    {
        Windows::Graphics::Printing::PrintMediaSize value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFeederConfiguration)->get_PageSize(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::PageSize(Windows::Graphics::Printing::PrintMediaSize const& value) const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFeederConfiguration)->put_PageSize(static_cast<int32_t>(value)));
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::PageOrientation() const
    {
        Windows::Graphics::Printing::PrintOrientation value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFeederConfiguration)->get_PageOrientation(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::PageOrientation(Windows::Graphics::Printing::PrintOrientation const& value) const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFeederConfiguration)->put_PageOrientation(static_cast<int32_t>(value)));
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::PageSizeDimensions() const
    {
        Windows::Foundation::Size value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFeederConfiguration)->get_PageSizeDimensions(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::IsPageSizeSupported(Windows::Graphics::Printing::PrintMediaSize const& pageSize, Windows::Graphics::Printing::PrintOrientation const& pageOrientation) const
    {
        bool result;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFeederConfiguration)->IsPageSizeSupported(static_cast<int32_t>(pageSize), static_cast<int32_t>(pageOrientation), &result));
        return result;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::MaxNumberOfPages() const
    {
        uint32_t value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFeederConfiguration)->get_MaxNumberOfPages(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::MaxNumberOfPages(uint32_t value) const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFeederConfiguration)->put_MaxNumberOfPages(value));
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::CanScanDuplex() const
    {
        bool value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFeederConfiguration)->get_CanScanDuplex(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::Duplex() const
    {
        bool value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFeederConfiguration)->get_Duplex(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::Duplex(bool value) const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFeederConfiguration)->put_Duplex(value));
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::CanScanAhead() const
    {
        bool value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFeederConfiguration)->get_CanScanAhead(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::ScanAhead() const
    {
        bool value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFeederConfiguration)->get_ScanAhead(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFeederConfiguration<D>::ScanAhead(bool value) const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFeederConfiguration)->put_ScanAhead(value));
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFormatConfiguration<D>::DefaultFormat() const
    {
        Windows::Devices::Scanners::ImageScannerFormat value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFormatConfiguration)->get_DefaultFormat(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFormatConfiguration<D>::Format() const
    {
        Windows::Devices::Scanners::ImageScannerFormat value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFormatConfiguration)->get_Format(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFormatConfiguration<D>::Format(Windows::Devices::Scanners::ImageScannerFormat const& value) const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFormatConfiguration)->put_Format(static_cast<int32_t>(value)));
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerFormatConfiguration<D>::IsFormatSupported(Windows::Devices::Scanners::ImageScannerFormat const& value) const
    {
        bool result;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerFormatConfiguration)->IsFormatSupported(static_cast<int32_t>(value), &result));
        return result;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerPreviewResult<D>::Succeeded() const
    {
        bool value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerPreviewResult)->get_Succeeded(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerPreviewResult<D>::Format() const
    {
        Windows::Devices::Scanners::ImageScannerFormat value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerPreviewResult)->get_Format(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerScanResult<D>::ScannedFiles() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerScanResult)->get_ScannedFiles(&value));
        return Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::MinScanArea() const
    {
        Windows::Foundation::Size value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_MinScanArea(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::MaxScanArea() const
    {
        Windows::Foundation::Size value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_MaxScanArea(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::SelectedScanRegion() const
    {
        Windows::Foundation::Rect value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_SelectedScanRegion(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::SelectedScanRegion(Windows::Foundation::Rect const& value) const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->put_SelectedScanRegion(impl::bind_in(value)));
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::AutoCroppingMode() const
    {
        Windows::Devices::Scanners::ImageScannerAutoCroppingMode value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_AutoCroppingMode(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::AutoCroppingMode(Windows::Devices::Scanners::ImageScannerAutoCroppingMode const& value) const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->put_AutoCroppingMode(static_cast<int32_t>(value)));
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::IsAutoCroppingModeSupported(Windows::Devices::Scanners::ImageScannerAutoCroppingMode const& value) const
    {
        bool result;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->IsAutoCroppingModeSupported(static_cast<int32_t>(value), &result));
        return result;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::MinResolution() const
    {
        Windows::Devices::Scanners::ImageScannerResolution value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_MinResolution(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::MaxResolution() const
    {
        Windows::Devices::Scanners::ImageScannerResolution value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_MaxResolution(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::OpticalResolution() const
    {
        Windows::Devices::Scanners::ImageScannerResolution value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_OpticalResolution(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::DesiredResolution() const
    {
        Windows::Devices::Scanners::ImageScannerResolution value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_DesiredResolution(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::DesiredResolution(Windows::Devices::Scanners::ImageScannerResolution const& value) const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->put_DesiredResolution(impl::bind_in(value)));
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::ActualResolution() const
    {
        Windows::Devices::Scanners::ImageScannerResolution value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_ActualResolution(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::DefaultColorMode() const
    {
        Windows::Devices::Scanners::ImageScannerColorMode value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_DefaultColorMode(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::ColorMode() const
    {
        Windows::Devices::Scanners::ImageScannerColorMode value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_ColorMode(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::ColorMode(Windows::Devices::Scanners::ImageScannerColorMode const& value) const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->put_ColorMode(static_cast<int32_t>(value)));
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::IsColorModeSupported(Windows::Devices::Scanners::ImageScannerColorMode const& value) const
    {
        bool result;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->IsColorModeSupported(static_cast<int32_t>(value), &result));
        return result;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::MinBrightness() const
    {
        int32_t value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_MinBrightness(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::MaxBrightness() const
    {
        int32_t value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_MaxBrightness(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::BrightnessStep() const
    {
        uint32_t value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_BrightnessStep(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::DefaultBrightness() const
    {
        int32_t value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_DefaultBrightness(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::Brightness() const
    {
        int32_t value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_Brightness(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::Brightness(int32_t value) const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->put_Brightness(value));
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::MinContrast() const
    {
        int32_t value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_MinContrast(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::MaxContrast() const
    {
        int32_t value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_MaxContrast(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::ContrastStep() const
    {
        uint32_t value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_ContrastStep(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::DefaultContrast() const
    {
        int32_t value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_DefaultContrast(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::Contrast() const
    {
        int32_t value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->get_Contrast(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerSourceConfiguration<D>::Contrast(int32_t value) const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerSourceConfiguration)->put_Contrast(value));
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerStatics<D>::FromIdAsync(param::hstring const& deviceId) const
    {
        void* asyncInfo{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerStatics)->FromIdAsync(*(void**)(&deviceId), &asyncInfo));
        return Windows::Foundation::IAsyncOperation<Windows::Devices::Scanners::ImageScanner>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Devices_Scanners_IImageScannerStatics<D>::GetDeviceSelector() const
    {
        void* selector{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Devices::Scanners::IImageScannerStatics)->GetDeviceSelector(&selector));
        return hstring{ selector, take_ownership_from_abi };
    }
    template <typename D>
    struct produce<D, Windows::Devices::Scanners::IImageScanner> : produce_base<D, Windows::Devices::Scanners::IImageScanner>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DefaultScanSource(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Devices::Scanners::ImageScannerScanSource>(this->shim().DefaultScanSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsScanSourceSupported(int32_t value, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsScanSourceSupported(*reinterpret_cast<Windows::Devices::Scanners::ImageScannerScanSource const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FlatbedConfiguration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Devices::Scanners::ImageScannerFlatbedConfiguration>(this->shim().FlatbedConfiguration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FeederConfiguration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Devices::Scanners::ImageScannerFeederConfiguration>(this->shim().FeederConfiguration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AutoConfiguration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Devices::Scanners::ImageScannerAutoConfiguration>(this->shim().AutoConfiguration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsPreviewSupported(int32_t scanSource, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsPreviewSupported(*reinterpret_cast<Windows::Devices::Scanners::ImageScannerScanSource const*>(&scanSource)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ScanPreviewToStreamAsync(int32_t scanSource, void* targetStream, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<Windows::Devices::Scanners::ImageScannerPreviewResult>>(this->shim().ScanPreviewToStreamAsync(*reinterpret_cast<Windows::Devices::Scanners::ImageScannerScanSource const*>(&scanSource), *reinterpret_cast<Windows::Storage::Streams::IRandomAccessStream const*>(&targetStream)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ScanFilesToFolderAsync(int32_t scanSource, void* storageFolder, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperationWithProgress<Windows::Devices::Scanners::ImageScannerScanResult, uint32_t>>(this->shim().ScanFilesToFolderAsync(*reinterpret_cast<Windows::Devices::Scanners::ImageScannerScanSource const*>(&scanSource), *reinterpret_cast<Windows::Storage::StorageFolder const*>(&storageFolder)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Devices::Scanners::IImageScannerFeederConfiguration> : produce_base<D, Windows::Devices::Scanners::IImageScannerFeederConfiguration>
    {
        int32_t __stdcall get_CanAutoDetectPageSize(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanAutoDetectPageSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AutoDetectPageSize(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AutoDetectPageSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AutoDetectPageSize(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoDetectPageSize(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PageSize(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Graphics::Printing::PrintMediaSize>(this->shim().PageSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PageSize(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PageSize(*reinterpret_cast<Windows::Graphics::Printing::PrintMediaSize const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PageOrientation(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Graphics::Printing::PrintOrientation>(this->shim().PageOrientation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PageOrientation(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PageOrientation(*reinterpret_cast<Windows::Graphics::Printing::PrintOrientation const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PageSizeDimensions(Windows::Foundation::Size* value) noexcept final try
        {
            zero_abi<Windows::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Foundation::Size>(this->shim().PageSizeDimensions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsPageSizeSupported(int32_t pageSize, int32_t pageOrientation, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsPageSizeSupported(*reinterpret_cast<Windows::Graphics::Printing::PrintMediaSize const*>(&pageSize), *reinterpret_cast<Windows::Graphics::Printing::PrintOrientation const*>(&pageOrientation)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxNumberOfPages(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxNumberOfPages());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaxNumberOfPages(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxNumberOfPages(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanScanDuplex(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanScanDuplex());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Duplex(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Duplex());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Duplex(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Duplex(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanScanAhead(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanScanAhead());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ScanAhead(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ScanAhead());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ScanAhead(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScanAhead(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Devices::Scanners::IImageScannerFormatConfiguration> : produce_base<D, Windows::Devices::Scanners::IImageScannerFormatConfiguration>
    {
        int32_t __stdcall get_DefaultFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Devices::Scanners::ImageScannerFormat>(this->shim().DefaultFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Format(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Devices::Scanners::ImageScannerFormat>(this->shim().Format());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Format(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Format(*reinterpret_cast<Windows::Devices::Scanners::ImageScannerFormat const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsFormatSupported(int32_t value, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsFormatSupported(*reinterpret_cast<Windows::Devices::Scanners::ImageScannerFormat const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Devices::Scanners::IImageScannerPreviewResult> : produce_base<D, Windows::Devices::Scanners::IImageScannerPreviewResult>
    {
        int32_t __stdcall get_Succeeded(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Succeeded());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Format(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Devices::Scanners::ImageScannerFormat>(this->shim().Format());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Devices::Scanners::IImageScannerScanResult> : produce_base<D, Windows::Devices::Scanners::IImageScannerScanResult>
    {
        int32_t __stdcall get_ScannedFiles(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>>(this->shim().ScannedFiles());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Devices::Scanners::IImageScannerSourceConfiguration> : produce_base<D, Windows::Devices::Scanners::IImageScannerSourceConfiguration>
    {
        int32_t __stdcall get_MinScanArea(Windows::Foundation::Size* value) noexcept final try
        {
            zero_abi<Windows::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Foundation::Size>(this->shim().MinScanArea());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxScanArea(Windows::Foundation::Size* value) noexcept final try
        {
            zero_abi<Windows::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Foundation::Size>(this->shim().MaxScanArea());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectedScanRegion(Windows::Foundation::Rect* value) noexcept final try
        {
            zero_abi<Windows::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Foundation::Rect>(this->shim().SelectedScanRegion());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SelectedScanRegion(Windows::Foundation::Rect value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectedScanRegion(*reinterpret_cast<Windows::Foundation::Rect const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AutoCroppingMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Devices::Scanners::ImageScannerAutoCroppingMode>(this->shim().AutoCroppingMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AutoCroppingMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoCroppingMode(*reinterpret_cast<Windows::Devices::Scanners::ImageScannerAutoCroppingMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsAutoCroppingModeSupported(int32_t value, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsAutoCroppingModeSupported(*reinterpret_cast<Windows::Devices::Scanners::ImageScannerAutoCroppingMode const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution* value) noexcept final try
        {
            zero_abi<Windows::Devices::Scanners::ImageScannerResolution>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Devices::Scanners::ImageScannerResolution>(this->shim().MinResolution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution* value) noexcept final try
        {
            zero_abi<Windows::Devices::Scanners::ImageScannerResolution>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Devices::Scanners::ImageScannerResolution>(this->shim().MaxResolution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OpticalResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution* value) noexcept final try
        {
            zero_abi<Windows::Devices::Scanners::ImageScannerResolution>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Devices::Scanners::ImageScannerResolution>(this->shim().OpticalResolution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DesiredResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution* value) noexcept final try
        {
            zero_abi<Windows::Devices::Scanners::ImageScannerResolution>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Devices::Scanners::ImageScannerResolution>(this->shim().DesiredResolution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DesiredResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredResolution(*reinterpret_cast<Windows::Devices::Scanners::ImageScannerResolution const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActualResolution(struct struct_Windows_Devices_Scanners_ImageScannerResolution* value) noexcept final try
        {
            zero_abi<Windows::Devices::Scanners::ImageScannerResolution>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Devices::Scanners::ImageScannerResolution>(this->shim().ActualResolution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DefaultColorMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Devices::Scanners::ImageScannerColorMode>(this->shim().DefaultColorMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ColorMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Devices::Scanners::ImageScannerColorMode>(this->shim().ColorMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ColorMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ColorMode(*reinterpret_cast<Windows::Devices::Scanners::ImageScannerColorMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsColorModeSupported(int32_t value, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsColorModeSupported(*reinterpret_cast<Windows::Devices::Scanners::ImageScannerColorMode const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinBrightness(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().MinBrightness());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxBrightness(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().MaxBrightness());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BrightnessStep(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().BrightnessStep());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DefaultBrightness(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().DefaultBrightness());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Brightness(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Brightness());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Brightness(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Brightness(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinContrast(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().MinContrast());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxContrast(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().MaxContrast());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContrastStep(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ContrastStep());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DefaultContrast(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().DefaultContrast());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Contrast(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Contrast());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Contrast(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Contrast(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Devices::Scanners::IImageScannerStatics> : produce_base<D, Windows::Devices::Scanners::IImageScannerStatics>
    {
        int32_t __stdcall FromIdAsync(void* deviceId, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<Windows::Foundation::IAsyncOperation<Windows::Devices::Scanners::ImageScanner>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelector(void** selector) noexcept final try
        {
            clear_abi(selector);
            typename D::abi_guard guard(this->shim());
            *selector = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
}
namespace winrt::Windows::Devices::Scanners
{
    inline auto ImageScanner::FromIdAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<ImageScanner, Windows::Devices::Scanners::IImageScannerStatics>([&](auto&& f) { return f.FromIdAsync(deviceId); });
    }
    inline auto ImageScanner::GetDeviceSelector()
    {
        return impl::call_factory<ImageScanner, Windows::Devices::Scanners::IImageScannerStatics>([&](auto&& f) { return f.GetDeviceSelector(); });
    }
}
namespace std
{
    template<> struct hash<winrt::Windows::Devices::Scanners::IImageScanner> : winrt::impl::hash_base<winrt::Windows::Devices::Scanners::IImageScanner> {};
    template<> struct hash<winrt::Windows::Devices::Scanners::IImageScannerFeederConfiguration> : winrt::impl::hash_base<winrt::Windows::Devices::Scanners::IImageScannerFeederConfiguration> {};
    template<> struct hash<winrt::Windows::Devices::Scanners::IImageScannerFormatConfiguration> : winrt::impl::hash_base<winrt::Windows::Devices::Scanners::IImageScannerFormatConfiguration> {};
    template<> struct hash<winrt::Windows::Devices::Scanners::IImageScannerPreviewResult> : winrt::impl::hash_base<winrt::Windows::Devices::Scanners::IImageScannerPreviewResult> {};
    template<> struct hash<winrt::Windows::Devices::Scanners::IImageScannerScanResult> : winrt::impl::hash_base<winrt::Windows::Devices::Scanners::IImageScannerScanResult> {};
    template<> struct hash<winrt::Windows::Devices::Scanners::IImageScannerSourceConfiguration> : winrt::impl::hash_base<winrt::Windows::Devices::Scanners::IImageScannerSourceConfiguration> {};
    template<> struct hash<winrt::Windows::Devices::Scanners::IImageScannerStatics> : winrt::impl::hash_base<winrt::Windows::Devices::Scanners::IImageScannerStatics> {};
    template<> struct hash<winrt::Windows::Devices::Scanners::ImageScanner> : winrt::impl::hash_base<winrt::Windows::Devices::Scanners::ImageScanner> {};
    template<> struct hash<winrt::Windows::Devices::Scanners::ImageScannerAutoConfiguration> : winrt::impl::hash_base<winrt::Windows::Devices::Scanners::ImageScannerAutoConfiguration> {};
    template<> struct hash<winrt::Windows::Devices::Scanners::ImageScannerFeederConfiguration> : winrt::impl::hash_base<winrt::Windows::Devices::Scanners::ImageScannerFeederConfiguration> {};
    template<> struct hash<winrt::Windows::Devices::Scanners::ImageScannerFlatbedConfiguration> : winrt::impl::hash_base<winrt::Windows::Devices::Scanners::ImageScannerFlatbedConfiguration> {};
    template<> struct hash<winrt::Windows::Devices::Scanners::ImageScannerPreviewResult> : winrt::impl::hash_base<winrt::Windows::Devices::Scanners::ImageScannerPreviewResult> {};
    template<> struct hash<winrt::Windows::Devices::Scanners::ImageScannerScanResult> : winrt::impl::hash_base<winrt::Windows::Devices::Scanners::ImageScannerScanResult> {};
}
#endif
