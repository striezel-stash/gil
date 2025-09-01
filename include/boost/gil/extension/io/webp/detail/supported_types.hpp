//
// Copyright 2025 Dirk Stolle
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#ifndef BOOST_GIL_EXTENSION_IO_WEBP_DETAIL_SUPPORTED_TYPES_HPP
#define BOOST_GIL_EXTENSION_IO_WEBP_DETAIL_SUPPORTED_TYPES_HPP

#include <boost/gil/extension/io/webp/tags.hpp>

#include <boost/gil/bit_aligned_pixel_reference.hpp>
#include <boost/gil/channel.hpp>
#include <boost/gil/color_base.hpp>
#include <boost/gil/packed_pixel.hpp>
#include <boost/gil/io/base.hpp>

#include <type_traits>

namespace boost { namespace gil { namespace detail {

// Read support

template< typename Channel, typename ColorSpace >
struct webp_read_support : read_support_false
{
};

template<>
struct webp_read_support<uint8_t, rgb_t> : read_support_true
{
};

template<>
struct webp_read_support<uint8_t, rgba_t> : read_support_true
{
};


// Write support

template< typename Channel, typename ColorSpace >
struct webp_write_support : write_support_false
{
};

template<>
struct webp_write_support<uint8_t, rgb_t> : write_support_true
{
};

template<>
struct webp_write_support<uint8_t, rgba_t> : write_support_true
{
};

} // namespace detail

template<typename Pixel>
struct is_read_supported<Pixel, webp_tag>
    : std::integral_constant
    <
        bool,
        detail::webp_read_support
        <
            typename channel_type<Pixel>::type,
            typename color_space_type<Pixel>::type
        >::is_supported
    >
{
};

template<typename Pixel>
struct is_write_supported<Pixel, webp_tag>
    : std::integral_constant
    <
        bool,
        detail::webp_write_support
        <
            typename channel_type<Pixel>::type,
            typename color_space_type<Pixel>::type
        >::is_supported
    >
{};

} // namespace gil
} // namespace boost

#endif
