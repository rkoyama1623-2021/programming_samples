#include "boost/python/numpy.hpp"

namespace p = boost::python;
namespace np = boost::python::numpy;

np::ndarray new_zero1(unsigned int N) {
  p::tuple shape = p::make_tuple(N);
  np::dtype dtype = np::dtype::get_builtin<double>();
  return np::zeros(shape, dtype);
}

BOOST_PYTHON_MODULE(mymodule) {
  Py_Initialize();
  np::initialize();

  p::def("new_zero", new_zero1);
}
// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <iostream>
int main () {
  std::cout << "hello world!" << std::endl;
  return 0;
};
