#include <boost/geometry.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/adapted/boost_tuple.hpp>
BOOST_GEOMETRY_REGISTER_BOOST_TUPLE_CS(cs::cartesian)
#include <iostream>
#include <tuple>
typedef boost::tuple<double, double> point;
typedef boost::geometry::model::polygon<point> polygon;

int main() {
    polygon a{{
        {-0.90478776881879274807, .51756843862589896332},
        {-0.91, .48},
        {-1.2, .4},
        {-1.4, 1.9},
        {-0.90478776881879274807, .51756843862589896332},
    }};
    polygon b{{
        {-0.91943242964602156508, .55292377741135378955},
        {-0.90478776881879174887, .51756843862590162786},
        {-0.91, .48},
    }};
    std::vector<polygon> output;
    boost::geometry::union_(a, b, output);

    std::cout << "a: " << boost::geometry::to_wkt(a) << "\n";
    std::cout << "b: " << boost::geometry::to_wkt(b) << "\n";

    for (const auto& pg : output)
    {
        int i = 0;
        for (const auto& out: pg.outer())
        {
            std::cout<<"i "<<i<<"\n";
            ++i;
            std::cout <<"{" << out.get<0>()<<","<<out.get<1>()<<"}," << "\n";
        }
    }
}