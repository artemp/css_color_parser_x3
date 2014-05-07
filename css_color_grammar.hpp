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

#ifndef MAPNIK_CSS_COLOR_GRAMMAR_HPP
#define MAPNIK_CSS_COLOR_GRAMMAR_HPP

// boost
#include <boost/fusion/adapted/adt.hpp>
#include <boost/fusion/adapted/struct.hpp>
#include <boost/spirit/home/x3.hpp>
// stl
#include <string>

namespace mapnik {

struct color
{
    std::uint8_t red_;
    std::uint8_t green_;
    std::uint8_t blue_;
    std::uint8_t alpha_;
//public:
    //inline std::uint8_t red() const { return red_ ;}
    //inline std::uint8_t green() const { return green_ ;}
    //inline std::uint8_t blue() const { return blue_ ;}
    //inline std::uint8_t alpha() const { return alpha_ ;}
    //inline void set_red(std::uint8_t red) { red_ = red;}
    //inline void set_green(std::uint8_t green) { green_ = green;}
    //inline void set_blue(std::uint8_t blue) { blue_ = blue;}
    //inline void set_alpha(std::uint8_t alpha) { alpha_ = alpha;}
};

}

//

BOOST_FUSION_ADAPT_STRUCT (
    mapnik::color,
    (std::uint8_t, red_)
    (std::uint8_t, green_)
    (std::uint8_t, blue_)
    (std::uint8_t, alpha_)
    )

/*
BOOST_FUSION_ADAPT_ADT(
mapnik::color,
    (unsigned, unsigned, obj.red(), obj.set_red(val))
    (unsigned, unsigned, obj.green(), obj.set_green(val))
    (unsigned, unsigned, obj.blue(), obj.set_blue(val))
    (unsigned, unsigned, obj.alpha(), obj.set_alpha(val))
    )
*/

struct fun_action
{
    template <typename T0, typename T1>
        void operator()(T0 arg0, T1 arg1) const
    {
        std::cerr << typeid(T0).name() << " " << typeid(T1).name() << " " <<  std::endl;
    }
};

namespace mapnik {

namespace x3 = boost::spirit::x3;

namespace css_color_grammar {

using x3::ascii::char_;
//using x3::_1;
//using x3::_val;
using x3::lit;
using x3::int_;
using x3::uint_parser;
using x3::double_;
using x3::strict_ureal_policies;
using x3::skip;
using x3::no_skip;
using x3::hex;
using x3::symbols;
using x3::omit;
//using x3::rule;

x3::real_parser<double, strict_ureal_policies<double> > strict_udouble;
x3::uint_parser<unsigned, 16, 2, 2> hex2;
x3::uint_parser<unsigned, 16, 1, 1> hex1;
x3::uint_parser<unsigned, 10, 1, 3> dec3;

x3::rule<class css_color, mapnik::color> css_color("css-color");
//x3::rule<class css_color, mapnik::expressions::ast::expr_node> const css_color("CSS colour");

auto quote_char = lit('\'') | lit('"');

auto const css_color_def = lit('#') >> hex2/*[fun_action()]*/ >> omit[hex2] >> omit[hex2] >> -omit[hex2] ; //hex >> hex >> hex >> hex;
auto const expression = x3::grammar("css-color-grammar", css_color = css_color_def);

}}

#endif //MAPNIK_CSS_COLOR_GRAMMAR_HPP
