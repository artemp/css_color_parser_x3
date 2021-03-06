#include <iostream>
#include <string>
#include <mapnik/config.hpp>
//#include <mapnik/svg2_color_grammar_def.hpp>
#include "css_color_grammar.hpp"

int main (int argc, char** argv)
{
    std::cerr << "css color parser" << std::endl;

    if (argc !=2 )
    {
        std::cerr << "Usage:" << argv[0] << " <css-color-string>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string str(argv[1]);

    auto & grammar = mapnik::css_color_grammar::expression;
    auto itr = str.begin();
    auto end = str.end();
    using namespace boost::spirit::x3::ascii;
    mapnik::color c;
    bool r = phrase_parse(itr, end, grammar, space, c);
    if (r && itr == end)
    {
        std::cerr << "OK" << std::endl;
        std::cerr << "color("
                  << (int)c.red() << ","
                  << (int)c.green() << ","
                  << (int)c.blue() << ","
                  << (int)c.alpha() << ")"
                  << std::endl;
    }
    else
    {
        std::string rest(itr,end);
        std::cout << "FAIL" << std::endl;
        std::cout << "stopped at: \"" << rest << "\"" << std::endl;
    }

    return EXIT_SUCCESS;
}
