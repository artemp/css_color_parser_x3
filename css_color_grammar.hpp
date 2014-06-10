/*****************************************************************************
 *
 * This file is part of Mapnik (c++ mapping toolkit)
 *
 * Copyright (C) 2014 Artem Pavlenko
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *****************************************************************************/

// http://www.w3.org/TR/SVG2/color.html
// TODO: should be renamed to SVG2 color grammar ^^

#ifndef MAPNIK_CSS_COLOR_GRAMMAR_HPP
#define MAPNIK_CSS_COLOR_GRAMMAR_HPP

// boost
#include <boost/spirit/home/x3.hpp>
//#include <boost/fusion/adapted/adt.hpp>
#include <boost/fusion/adapted/struct.hpp>

// stl
#include <string>

namespace mapnik {

class color
{
public:
    color()
        : red_(0),
          green_(0),
          blue_(0),
          alpha_(0) {}

    color (std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255)
        : red_(red),
          green_(green),
          blue_(blue),
          alpha_(alpha) {}

    inline std::uint8_t red() const { return red_ ;}
    inline std::uint8_t green() const { return green_ ;}
    inline std::uint8_t blue() const { return blue_ ;}
    inline std::uint8_t alpha() const { return alpha_ ;}
    inline void set_red(std::uint8_t red) { red_ = red;}
    inline void set_green(std::uint8_t green) { green_ = green;}
    inline void set_blue(std::uint8_t blue) { blue_ = blue;}
    inline void set_alpha(std::uint8_t alpha) { alpha_ = alpha;}
//private:
    std::uint8_t red_;
    std::uint8_t green_;
    std::uint8_t blue_;
    std::uint8_t alpha_;
};

}

BOOST_FUSION_ADAPT_STRUCT (
    mapnik::color,
    (std::uint8_t, red_)
    (std::uint8_t, green_)
    (std::uint8_t, blue_)
    (std::uint8_t, alpha_)
    )


//BOOST_FUSION_ADAPT_ADT(
//    mapnik::color,
//    (std::uint8_t, std::uint8_t, obj.red(), obj.set_red(val))
//    (std::uint8_t, std::uint8_t, obj.green(), obj.set_green(val))
//    (std::uint8_t, std::uint8_t, obj.blue(), obj.set_blue(val))
//    (std::uint8_t, std::uint8_t, obj.alpha(), obj.set_alpha(val))
//    )

namespace mapnik {

namespace x3 = boost::spirit::x3;

namespace css_color_grammar {

using x3::lit;
using x3::uint_parser;
using x3::hex;
using x3::symbols;
using x3::omit;
using x3::attr;
using x3::double_;
//using x3::no_case;

symbols<char, mapnik::color> const named_colors =
{
    {"aliceblue", mapnik::color(240, 248, 255)},
    {"antiquewhite", mapnik::color(250, 235, 215)},
    {"aqua", mapnik::color(0, 255, 255)},
    {"aquamarine", mapnik::color(127, 255, 212)},
    {"azure", mapnik::color(240, 255, 255)},
    {"beige", mapnik::color(245, 245, 220)},
    {"bisque", mapnik::color(255, 228, 196)},
    {"black", mapnik::color(0, 0, 0)},
    {"blanchedalmond", mapnik::color(255,235,205)},
    {"blue", mapnik::color(0, 0, 255)},
    {"blueviolet", mapnik::color(138, 43, 226)},
    {"brown", mapnik::color(165, 42, 42)},
    {"burlywood", mapnik::color(222, 184, 135)},
    {"cadetblue", mapnik::color(95, 158, 160)},
    {"chartreuse", mapnik::color(127, 255, 0)},
    {"chocolate", mapnik::color(210, 105, 30)},
    {"coral", mapnik::color(255, 127, 80)},
    {"cornflowerblue", mapnik::color(100, 149, 237)},
    {"cornsilk", mapnik::color(255, 248, 220)},
    {"crimson", mapnik::color(220, 20, 60)},
    {"cyan", mapnik::color(0, 255, 255)},
    {"darkblue", mapnik::color(0, 0, 139)},
    {"darkcyan", mapnik::color(0, 139, 139)},
    {"darkgoldenrod", mapnik::color(184, 134, 11)},
    {"darkgray", mapnik::color(169, 169, 169)},
    {"darkgreen", mapnik::color(0, 100, 0)},
    {"darkgrey", mapnik::color(169, 169, 169)},
    {"darkkhaki", mapnik::color(189, 183, 107)},
    {"darkmagenta", mapnik::color(139, 0, 139)},
    {"darkolivegreen", mapnik::color(85, 107, 47)},
    {"darkorange", mapnik::color(255, 140, 0)},
    {"darkorchid", mapnik::color(153, 50, 204)},
    {"darkred", mapnik::color(139, 0, 0)},
    {"darksalmon", mapnik::color(233, 150, 122)},
    {"darkseagreen", mapnik::color(143, 188, 143)},
    {"darkslateblue", mapnik::color(72, 61, 139)},
    {"darkslategrey", mapnik::color(47, 79, 79)},
    {"darkturquoise", mapnik::color(0, 206, 209)},
    {"darkviolet", mapnik::color(148, 0, 211)},
    {"deeppink", mapnik::color(255, 20, 147)},
    {"deepskyblue", mapnik::color(0, 191, 255)},
    {"dimgray", mapnik::color(105, 105, 105)},
    {"dimgrey", mapnik::color(105, 105, 105)},
    {"dodgerblue", mapnik::color(30, 144, 255)},
    {"firebrick", mapnik::color(178, 34, 34)},
    {"floralwhite", mapnik::color(255, 250, 240)},
    {"forestgreen", mapnik::color(34, 139, 34)},
    {"fuchsia", mapnik::color(255, 0, 255)},
    {"gainsboro", mapnik::color(220, 220, 220)},
    {"ghostwhite", mapnik::color(248, 248, 255)},
    {"gold", mapnik::color(255, 215, 0)},
    {"goldenrod", mapnik::color(218, 165, 32)},
    {"gray", mapnik::color(128, 128, 128)},
    {"grey", mapnik::color(128, 128, 128)},
    {"green", mapnik::color(0, 128, 0)},
    {"greenyellow", mapnik::color(173, 255, 47)},
    {"honeydew", mapnik::color(240, 255, 240)},
    {"hotpink", mapnik::color(255, 105, 180)},
    {"indianred", mapnik::color(205, 92, 92)},
    {"indigo", mapnik::color(75, 0, 130)},
    {"ivory", mapnik::color(255, 255, 240)},
    {"khaki", mapnik::color(240, 230, 140)},
    {"lavender", mapnik::color(230, 230, 250)},
    {"lavenderblush", mapnik::color(255, 240, 245)},
    {"lawngreen", mapnik::color(124, 252, 0)},
    {"lemonchiffon", mapnik::color(255, 250, 205)},
    {"lightblue", mapnik::color(173, 216, 230)},
    {"lightcoral", mapnik::color(240, 128, 128)},
    {"lightcyan", mapnik::color(224, 255, 255)},
    {"lightgoldenrodyellow", mapnik::color(250, 250, 210)},
    {"lightgray", mapnik::color(211, 211, 211)},
    {"lightgreen", mapnik::color(144, 238, 144)},
    {"lightgrey", mapnik::color(211, 211, 211)},
    {"lightpink", mapnik::color(255, 182, 193)},
    {"lightsalmon", mapnik::color(255, 160, 122)},
    {"lightseagreen", mapnik::color(32, 178, 170)},
    {"lightskyblue", mapnik::color(135, 206, 250)},
    {"lightslategray", mapnik::color(119, 136, 153)},
    {"lightslategrey", mapnik::color(119, 136, 153)},
    {"lightsteelblue", mapnik::color(176, 196, 222)},
    {"lightyellow", mapnik::color(255, 255, 224)},
    {"lime", mapnik::color(0, 255, 0)},
    {"limegreen", mapnik::color(50, 205, 50)},
    {"linen", mapnik::color(250, 240, 230)},
    {"magenta", mapnik::color(255, 0, 255)},
    {"maroon", mapnik::color(128, 0, 0)},
    {"mediumaquamarine", mapnik::color(102, 205, 170)},
    {"mediumblue", mapnik::color(0, 0, 205)},
    {"mediumorchid", mapnik::color(186, 85, 211)},
    {"mediumpurple", mapnik::color(147, 112, 219)},
    {"mediumseagreen", mapnik::color(60, 179, 113)},
    {"mediumslateblue", mapnik::color(123, 104, 238)},
    {"mediumspringgreen", mapnik::color(0, 250, 154)},
    {"mediumturquoise", mapnik::color(72, 209, 204)},
    {"mediumvioletred", mapnik::color(199, 21, 133)},
    {"midnightblue", mapnik::color(25, 25, 112)},
    {"mintcream", mapnik::color(245, 255, 250)},
    {"mistyrose", mapnik::color(255, 228, 225)},
    {"moccasin", mapnik::color(255, 228, 181)},
    {"navajowhite", mapnik::color(255, 222, 173)},
    {"navy", mapnik::color(0, 0, 128)},
    {"oldlace", mapnik::color(253, 245, 230)},
    {"olive", mapnik::color(128, 128, 0)},
    {"olivedrab", mapnik::color(107, 142, 35)},
    {"orange", mapnik::color(255, 165, 0)},
    {"orangered", mapnik::color(255, 69, 0)},
    {"orchid", mapnik::color(218, 112, 214)},
    {"palegoldenrod", mapnik::color(238, 232, 170)},
    {"palegreen", mapnik::color(152, 251, 152)},
    {"paleturquoise", mapnik::color(175, 238, 238)},
    {"palevioletred", mapnik::color(219, 112, 147)},
    {"papayawhip", mapnik::color(255, 239, 213)},
    {"peachpuff", mapnik::color(255, 218, 185)},
    {"peru", mapnik::color(205, 133, 63)},
    {"pink", mapnik::color(255, 192, 203)},
    {"plum", mapnik::color(221, 160, 221)},
    {"powderblue", mapnik::color(176, 224, 230)},
    {"purple", mapnik::color(128, 0, 128)},
    {"red", mapnik::color(255, 0, 0)},
    {"rosybrown", mapnik::color(188, 143, 143)},
    {"royalblue", mapnik::color(65, 105, 225)},
    {"saddlebrown", mapnik::color(139, 69, 19)},
    {"salmon", mapnik::color(250, 128, 114)},
    {"sandybrown", mapnik::color(244, 164, 96)},
    {"seagreen", mapnik::color(46, 139, 87)},
    {"seashell", mapnik::color(255, 245, 238)},
    {"sienna", mapnik::color(160, 82, 45)},
    {"silver", mapnik::color(192, 192, 192)},
    {"skyblue", mapnik::color(135, 206, 235)},
    {"slateblue", mapnik::color(106, 90, 205)},
    {"slategray", mapnik::color(112, 128, 144)},
    {"slategrey", mapnik::color(112, 128, 144)},
    {"snow", mapnik::color(255, 250, 250)},
    {"springgreen", mapnik::color(0, 255, 127)},
    {"steelblue", mapnik::color(70, 130, 180)},
    {"tan", mapnik::color(210, 180, 140)},
    {"teal", mapnik::color(0, 128, 128)},
    {"thistle", mapnik::color(216, 191, 216)},
    {"tomato", mapnik::color(255, 99, 71)},
    {"turquoise", mapnik::color(64, 224, 208)},
    {"violet", mapnik::color(238, 130, 238)},
    {"wheat", mapnik::color(245, 222, 179)},
    {"white", mapnik::color(255, 255, 255)},
    {"whitesmoke", mapnik::color(245, 245, 245)},
    {"yellow", mapnik::color(255, 255, 0)},
    {"yellowgreen", mapnik::color(154, 205, 50)},
    {"transparent", mapnik::color(0, 0, 0, 0)}
};

x3::uint_parser<std::uint8_t, 16, 2, 2> hex2;
x3::uint_parser<std::uint8_t, 16, 1, 1> hex1;
x3::uint_parser<std::uint8_t, 10, 1, 3> dec3;

x3::rule<class css_color, mapnik::color> const css_color("css_color");
x3::rule<class hex2_color, mapnik::color> const hex2_color("hex2_color");
x3::rule<class hex1_color, mapnik::color> const hex1_color("hex1_color");
x3::rule<class rgb_color, mapnik::color> const rgb_color("rgb_color");
x3::rule<class rgba_color, mapnik::color> const rgba_color("rgba_color");

struct clip_opacity
{
    static double call(double val)
    {
        if (val > 1.0) return 1.0;
        if (val < 0.0) return 0.0;
        return val;
    }
};

auto dec_red = [](auto& ctx)
{
    _val(ctx).red_ = _attr(ctx);
};

auto dec_green = [](auto& ctx)
{
    _val(ctx).green_ = _attr(ctx);
};

auto dec_blue = [](auto& ctx)
{
    _val(ctx).blue_ = _attr(ctx);
};

auto opacity = [](auto& ctx)
{
    _val(ctx).alpha_ = uint8_t((255.0 * clip_opacity::call(_attr(ctx))) + 0.5);
};

auto hex1_red = [](auto& ctx)
{
    _val(ctx).red_ = _attr(ctx) | _attr(ctx) << 4;
};

auto hex1_green = [](auto& ctx)
{
    _val(ctx).green_ = _attr(ctx) | _attr(ctx) << 4;
};

auto hex1_blue = [](auto& ctx)
{
    _val(ctx).blue_ = _attr(ctx) | _attr(ctx) << 4;
};

auto hex1_opacity = [](auto& ctx)
{
    _val(ctx).alpha_ = _attr(ctx) | _attr(ctx) << 4;
};

auto const hex2_color_def = lit('#') >> hex2 >> hex2 >> hex2 >> (hex2 | attr(255)) ;
auto const hex1_color_def = lit('#') >> hex1[hex1_red] >> hex1[hex1_green] >> hex1[hex1_blue] >> (hex1[hex1_opacity] | attr(15)[hex1_opacity]);
auto const rgb_color_def = lit("rgb") >> lit('(') >> dec3 >> lit(',') >> dec3 >> lit(',') >> dec3 >> attr(255) >> lit(')');

auto const rgba_color_def = lit("rgba")
    >> lit('(') >> dec3[dec_red]
    >> lit(',') >> dec3[dec_green]
    >> lit(',') >> dec3[dec_blue]
    >> lit(',') >> double_[opacity] >> lit(')');

auto const css_color_def = named_colors | hex2_color | hex1_color | rgb_color | rgba_color;

BOOST_SPIRIT_DEFINE(
    css_color=css_color_def,
    hex2_color=hex2_color_def,
    hex1_color=hex1_color_def,
    rgb_color=rgb_color_def,
    rgba_color=rgba_color_def
    );

auto const expression = css_color;

}}

#endif //MAPNIK_CSS_COLOR_GRAMMAR_HPP
