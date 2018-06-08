// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <boost/assert.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/box.hpp>
#include <boost/geometry/algorithms/disjoint.hpp>
#include <iostream>

#include <boost/timer/timer.hpp>

namespace bg = boost::geometry;

typedef bg::model::d2::point_xy<double> point;
typedef bg::model::box<point> box;

int main()
{

boost::timer::auto_cpu_timer t;
// A. disjoint
// a
// +------+
// |      |
// |      |
// +------+  b
//           +------+
//           |      |
//           |      |
//           +------+
  {
    const box a(point(0, 0), point(3, 3));
    const box b(point(4, 4), point(7, 7));

    const bool result = bg::disjoint(a, b);
    if (result) {std::cout << "true!"<< std::endl;}
    else {std::cout << "false!"<< std::endl;}
    BOOST_ASSERT(result);
  }

// B. not disjoint
// a
// +------+
// |   b  |
// |   +--+---+
// +---+--+   |
//     |      |
//     +------+
  {
    const box a(point(0, 0), point(3, 3));
    const box b(point(2, 2), point(5, 5));

    const bool result = bg::disjoint(a, b);
    BOOST_ASSERT(!result);
    if (result) {std::cout << "true!"<< std::endl;}
    else {std::cout << "false!"<< std::endl;}
  }
}
