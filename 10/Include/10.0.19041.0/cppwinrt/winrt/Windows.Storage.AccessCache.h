// C++/WinRT v2.0.190620.2

// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef WINRT_Windows_Storage_AccessCache_H
#define WINRT_Windows_Storage_AccessCache_H
#include "winrt/base.h"
static_assert(winrt::check_version(CPPWINRT_VERSION, "2.0.190620.2"), "Mismatched C++/WinRT headers.");
#include "winrt/Windows.Storage.h"
#include "winrt/impl/Windows.Foundation.2.h"
#include "winrt/impl/Windows.Foundation.Collections.2.h"
#include "winrt/impl/Windows.Storage.2.h"
#include "winrt/impl/Windows.System.2.h"
#include "winrt/impl/Windows.Storage.AccessCache.2.h"
namespace winrt::impl
{
    template <typename D> auto consume_Windows_Storage_AccessCache_IItemRemovedEventArgs<D>::RemovedEntry() const
    {
        Windows::Storage::AccessCache::AccessListEntry value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IItemRemovedEventArgs)->get_RemovedEntry(put_abi(value)));
        return value;
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageApplicationPermissionsStatics<D>::FutureAccessList() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics)->get_FutureAccessList(&value));
        return Windows::Storage::AccessCache::StorageItemAccessList{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageApplicationPermissionsStatics<D>::MostRecentlyUsedList() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics)->get_MostRecentlyUsedList(&value));
        return Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageApplicationPermissionsStatics2<D>::GetFutureAccessListForUser(Windows::System::User const& user) const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics2)->GetFutureAccessListForUser(*(void**)(&user), &value));
        return Windows::Storage::AccessCache::StorageItemAccessList{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageApplicationPermissionsStatics2<D>::GetMostRecentlyUsedListForUser(Windows::System::User const& user) const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics2)->GetMostRecentlyUsedListForUser(*(void**)(&user), &value));
        return Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList{ value, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::Add(Windows::Storage::IStorageItem const& file) const
    {
        void* token{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemAccessList)->AddOverloadDefaultMetadata(*(void**)(&file), &token));
        return hstring{ token, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::Add(Windows::Storage::IStorageItem const& file, param::hstring const& metadata) const
    {
        void* token{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemAccessList)->Add(*(void**)(&file), *(void**)(&metadata), &token));
        return hstring{ token, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::AddOrReplace(param::hstring const& token, Windows::Storage::IStorageItem const& file) const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemAccessList)->AddOrReplaceOverloadDefaultMetadata(*(void**)(&token), *(void**)(&file)));
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::AddOrReplace(param::hstring const& token, Windows::Storage::IStorageItem const& file, param::hstring const& metadata) const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemAccessList)->AddOrReplace(*(void**)(&token), *(void**)(&file), *(void**)(&metadata)));
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::GetItemAsync(param::hstring const& token) const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemAccessList)->GetItemAsync(*(void**)(&token), &operation));
        return Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::GetFileAsync(param::hstring const& token) const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemAccessList)->GetFileAsync(*(void**)(&token), &operation));
        return Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::GetFolderAsync(param::hstring const& token) const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemAccessList)->GetFolderAsync(*(void**)(&token), &operation));
        return Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::GetItemAsync(param::hstring const& token, Windows::Storage::AccessCache::AccessCacheOptions const& options) const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemAccessList)->GetItemWithOptionsAsync(*(void**)(&token), static_cast<uint32_t>(options), &operation));
        return Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::GetFileAsync(param::hstring const& token, Windows::Storage::AccessCache::AccessCacheOptions const& options) const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemAccessList)->GetFileWithOptionsAsync(*(void**)(&token), static_cast<uint32_t>(options), &operation));
        return Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::GetFolderAsync(param::hstring const& token, Windows::Storage::AccessCache::AccessCacheOptions const& options) const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemAccessList)->GetFolderWithOptionsAsync(*(void**)(&token), static_cast<uint32_t>(options), &operation));
        return Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>{ operation, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::Remove(param::hstring const& token) const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemAccessList)->Remove(*(void**)(&token)));
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::ContainsItem(param::hstring const& token) const
    {
        bool value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemAccessList)->ContainsItem(*(void**)(&token), &value));
        return value;
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::Clear() const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemAccessList)->Clear());
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::CheckAccess(Windows::Storage::IStorageItem const& file) const
    {
        bool value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemAccessList)->CheckAccess(*(void**)(&file), &value));
        return value;
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::Entries() const
    {
        void* entries{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemAccessList)->get_Entries(&entries));
        return Windows::Storage::AccessCache::AccessListEntryView{ entries, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::MaximumItemsAllowed() const
    {
        uint32_t value;
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemAccessList)->get_MaximumItemsAllowed(&value));
        return value;
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemMostRecentlyUsedList<D>::ItemRemoved(Windows::Foundation::TypedEventHandler<Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList, Windows::Storage::AccessCache::ItemRemovedEventArgs> const& handler) const
    {
        winrt::event_token eventCookie;
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList)->add_ItemRemoved(*(void**)(&handler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Storage_AccessCache_IStorageItemMostRecentlyUsedList<D>::ItemRemoved_revoker consume_Windows_Storage_AccessCache_IStorageItemMostRecentlyUsedList<D>::ItemRemoved(auto_revoke_t, Windows::Foundation::TypedEventHandler<Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList, Windows::Storage::AccessCache::ItemRemovedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ItemRemoved_revoker>(this, ItemRemoved(handler));
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemMostRecentlyUsedList<D>::ItemRemoved(winrt::event_token const& eventCookie) const noexcept
    {
        WINRT_VERIFY_(0, WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList)->remove_ItemRemoved(impl::bind_in(eventCookie)));
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemMostRecentlyUsedList2<D>::Add(Windows::Storage::IStorageItem const& file, param::hstring const& metadata, Windows::Storage::AccessCache::RecentStorageItemVisibility const& visibility) const
    {
        void* token{};
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList2)->AddWithMetadataAndVisibility(*(void**)(&file), *(void**)(&metadata), static_cast<int32_t>(visibility), &token));
        return hstring{ token, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_Storage_AccessCache_IStorageItemMostRecentlyUsedList2<D>::AddOrReplace(param::hstring const& token, Windows::Storage::IStorageItem const& file, param::hstring const& metadata, Windows::Storage::AccessCache::RecentStorageItemVisibility const& visibility) const
    {
        check_hresult(WINRT_IMPL_SHIM(Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList2)->AddOrReplaceWithMetadataAndVisibility(*(void**)(&token), *(void**)(&file), *(void**)(&metadata), static_cast<int32_t>(visibility)));
    }
    template <typename D>
    struct produce<D, Windows::Storage::AccessCache::IItemRemovedEventArgs> : produce_base<D, Windows::Storage::AccessCache::IItemRemovedEventArgs>
    {
        int32_t __stdcall get_RemovedEntry(struct struct_Windows_Storage_AccessCache_AccessListEntry* value) noexcept final try
        {
            zero_abi<Windows::Storage::AccessCache::AccessListEntry>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Storage::AccessCache::AccessListEntry>(this->shim().RemovedEntry());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics> : produce_base<D, Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics>
    {
        int32_t __stdcall get_FutureAccessList(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Storage::AccessCache::StorageItemAccessList>(this->shim().FutureAccessList());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MostRecentlyUsedList(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList>(this->shim().MostRecentlyUsedList());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics2> : produce_base<D, Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics2>
    {
        int32_t __stdcall GetFutureAccessListForUser(void* user, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Storage::AccessCache::StorageItemAccessList>(this->shim().GetFutureAccessListForUser(*reinterpret_cast<Windows::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetMostRecentlyUsedListForUser(void* user, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList>(this->shim().GetMostRecentlyUsedListForUser(*reinterpret_cast<Windows::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Storage::AccessCache::IStorageItemAccessList> : produce_base<D, Windows::Storage::AccessCache::IStorageItemAccessList>
    {
        int32_t __stdcall AddOverloadDefaultMetadata(void* file, void** token) noexcept final try
        {
            clear_abi(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<hstring>(this->shim().Add(*reinterpret_cast<Windows::Storage::IStorageItem const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Add(void* file, void* metadata, void** token) noexcept final try
        {
            clear_abi(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<hstring>(this->shim().Add(*reinterpret_cast<Windows::Storage::IStorageItem const*>(&file), *reinterpret_cast<hstring const*>(&metadata)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddOrReplaceOverloadDefaultMetadata(void* token, void* file) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddOrReplace(*reinterpret_cast<hstring const*>(&token), *reinterpret_cast<Windows::Storage::IStorageItem const*>(&file));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddOrReplace(void* token, void* file, void* metadata) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddOrReplace(*reinterpret_cast<hstring const*>(&token), *reinterpret_cast<Windows::Storage::IStorageItem const*>(&file), *reinterpret_cast<hstring const*>(&metadata));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetItemAsync(void* token, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem>>(this->shim().GetItemAsync(*reinterpret_cast<hstring const*>(&token)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFileAsync(void* token, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>>(this->shim().GetFileAsync(*reinterpret_cast<hstring const*>(&token)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFolderAsync(void* token, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>>(this->shim().GetFolderAsync(*reinterpret_cast<hstring const*>(&token)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetItemWithOptionsAsync(void* token, uint32_t options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem>>(this->shim().GetItemAsync(*reinterpret_cast<hstring const*>(&token), *reinterpret_cast<Windows::Storage::AccessCache::AccessCacheOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFileWithOptionsAsync(void* token, uint32_t options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>>(this->shim().GetFileAsync(*reinterpret_cast<hstring const*>(&token), *reinterpret_cast<Windows::Storage::AccessCache::AccessCacheOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFolderWithOptionsAsync(void* token, uint32_t options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>>(this->shim().GetFolderAsync(*reinterpret_cast<hstring const*>(&token), *reinterpret_cast<Windows::Storage::AccessCache::AccessCacheOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Remove(void* token) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<hstring const*>(&token));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ContainsItem(void* token, bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ContainsItem(*reinterpret_cast<hstring const*>(&token)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Clear() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CheckAccess(void* file, bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CheckAccess(*reinterpret_cast<Windows::Storage::IStorageItem const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Entries(void** entries) noexcept final try
        {
            clear_abi(entries);
            typename D::abi_guard guard(this->shim());
            *entries = detach_from<Windows::Storage::AccessCache::AccessListEntryView>(this->shim().Entries());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaximumItemsAllowed(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaximumItemsAllowed());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList> : produce_base<D, Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList>
    {
        int32_t __stdcall add_ItemRemoved(void* handler, winrt::event_token* eventCookie) noexcept final try
        {
            zero_abi<winrt::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<winrt::event_token>(this->shim().ItemRemoved(*reinterpret_cast<Windows::Foundation::TypedEventHandler<Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList, Windows::Storage::AccessCache::ItemRemovedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ItemRemoved(winrt::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemRemoved(*reinterpret_cast<winrt::event_token const*>(&eventCookie));
            return 0;
        }
    };
    template <typename D>
    struct produce<D, Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList2> : produce_base<D, Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList2>
    {
        int32_t __stdcall AddWithMetadataAndVisibility(void* file, void* metadata, int32_t visibility, void** token) noexcept final try
        {
            clear_abi(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<hstring>(this->shim().Add(*reinterpret_cast<Windows::Storage::IStorageItem const*>(&file), *reinterpret_cast<hstring const*>(&metadata), *reinterpret_cast<Windows::Storage::AccessCache::RecentStorageItemVisibility const*>(&visibility)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddOrReplaceWithMetadataAndVisibility(void* token, void* file, void* metadata, int32_t visibility) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddOrReplace(*reinterpret_cast<hstring const*>(&token), *reinterpret_cast<Windows::Storage::IStorageItem const*>(&file), *reinterpret_cast<hstring const*>(&metadata), *reinterpret_cast<Windows::Storage::AccessCache::RecentStorageItemVisibility const*>(&visibility));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
}
namespace winrt::Windows::Storage::AccessCache
{
    constexpr auto operator|(AccessCacheOptions const left, AccessCacheOptions const right) noexcept
    {
        return static_cast<AccessCacheOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(AccessCacheOptions& left, AccessCacheOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(AccessCacheOptions const left, AccessCacheOptions const right) noexcept
    {
        return static_cast<AccessCacheOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(AccessCacheOptions& left, AccessCacheOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(AccessCacheOptions const value) noexcept
    {
        return static_cast<AccessCacheOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(AccessCacheOptions const left, AccessCacheOptions const right) noexcept
    {
        return static_cast<AccessCacheOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(AccessCacheOptions& left, AccessCacheOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto StorageApplicationPermissions::FutureAccessList()
    {
        return impl::call_factory<StorageApplicationPermissions, Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics>([&](auto&& f) { return f.FutureAccessList(); });
    }
    inline auto StorageApplicationPermissions::MostRecentlyUsedList()
    {
        return impl::call_factory<StorageApplicationPermissions, Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics>([&](auto&& f) { return f.MostRecentlyUsedList(); });
    }
    inline auto StorageApplicationPermissions::GetFutureAccessListForUser(Windows::System::User const& user)
    {
        return impl::call_factory<StorageApplicationPermissions, Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics2>([&](auto&& f) { return f.GetFutureAccessListForUser(user); });
    }
    inline auto StorageApplicationPermissions::GetMostRecentlyUsedListForUser(Windows::System::User const& user)
    {
        return impl::call_factory<StorageApplicationPermissions, Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics2>([&](auto&& f) { return f.GetMostRecentlyUsedListForUser(user); });
    }
}
namespace std
{
    template<> struct hash<winrt::Windows::Storage::AccessCache::IItemRemovedEventArgs> : winrt::impl::hash_base<winrt::Windows::Storage::AccessCache::IItemRemovedEventArgs> {};
    template<> struct hash<winrt::Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics> : winrt::impl::hash_base<winrt::Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics> {};
    template<> struct hash<winrt::Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics2> : winrt::impl::hash_base<winrt::Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics2> {};
    template<> struct hash<winrt::Windows::Storage::AccessCache::IStorageItemAccessList> : winrt::impl::hash_base<winrt::Windows::Storage::AccessCache::IStorageItemAccessList> {};
    template<> struct hash<winrt::Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList> : winrt::impl::hash_base<winrt::Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList> {};
    template<> struct hash<winrt::Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList2> : winrt::impl::hash_base<winrt::Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList2> {};
    template<> struct hash<winrt::Windows::Storage::AccessCache::AccessListEntryView> : winrt::impl::hash_base<winrt::Windows::Storage::AccessCache::AccessListEntryView> {};
    template<> struct hash<winrt::Windows::Storage::AccessCache::ItemRemovedEventArgs> : winrt::impl::hash_base<winrt::Windows::Storage::AccessCache::ItemRemovedEventArgs> {};
    template<> struct hash<winrt::Windows::Storage::AccessCache::StorageApplicationPermissions> : winrt::impl::hash_base<winrt::Windows::Storage::AccessCache::StorageApplicationPermissions> {};
    template<> struct hash<winrt::Windows::Storage::AccessCache::StorageItemAccessList> : winrt::impl::hash_base<winrt::Windows::Storage::AccessCache::StorageItemAccessList> {};
    template<> struct hash<winrt::Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList> : winrt::impl::hash_base<winrt::Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList> {};
}
#endif
