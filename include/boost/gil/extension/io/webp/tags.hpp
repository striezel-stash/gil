//
// Copyright 2024 Dirk Stolle
//
// Distributed under the Boost Software License, Version 1.0
// See the accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt
//
#ifndef BOOST_GIL_EXTENSION_IO_WEBP_TAGS_HPP
#define BOOST_GIL_EXTENSION_IO_WEBP_TAGS_HPP

#include <boost/gil/io/base.hpp>

namespace boost {
namespace gil {

/// Defines webp tag.
struct webp_tag : format_tag {};

/// Defines type for image width property.
struct webp_image_width : property_base< int > {};

/// Defines type for image height property.
struct webp_image_height : property_base< int > {};

/// Whether the bitstream contains an alpha channel.
struct webp_has_alpha : property_base< bool > {};

/// Whether the bitstream is an animated image.
struct webp_has_animation : property_base< bool > {};

/// Defines type for format property.
struct webp_format : property_base< int >
{
    static const type undefined = 0; /// undefined or mixed
    static const type lossy     = 1; /// lossy compression
    static const type lossless  = 2; /// lossless compression
};

/// Read information for WebP images.
///
/// The structure is returned when using read_image_info.
template<>
struct image_read_info< webp_tag >
{
    /// Default contructor.
    image_read_info()
    : width(0)
    , height(0)
    , has_alpha(false)
    , has_animation(false)
    , format(webp_format::undefined)
    {}

    /// The image width in pixels.
    webp_image_width::type  width;

    /// The image height in pixels.
    webp_image_height::type height;

    /// Whether the bitstream contains an alpha channel.
    webp_has_alpha::type has_alpha;

    /// Whether the bitstream is an animated image.
    webp_has_animation::type has_animation;

    /// The format / compression being used. See above for a list of possible values.
    webp_format::type format;
};

/// Read settings for WebP images.
///
/// The structure can be used for all read_xxx functions, except read_image_info.
template<>
struct image_read_settings< webp_tag > : public image_read_settings_base
{
    /// Default constructor
    image_read_settings()
    : image_read_settings_base()
    {}

    /// Constructor
    /// \param top_left Top left coordinate for reading partial image.
    /// \param dim      Dimensions for reading partial image.
    image_read_settings( point_t const& top_left
                       , point_t const& dim
                       )
    : image_read_settings_base( top_left
                              , dim
                              )
    {}
};

/// Write information for WebP images.
///
/// The structure can be used for write_view() function.
template<>
struct image_write_info< webp_tag >
{
};

} // namespace gil
} // namespace boost

#endif
