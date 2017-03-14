/*
<%
cfg['compiler_args'] = ['-std=c++11']
cfg['include_dirs'] = ["/usr/include/eigen3"]
setup_pybind11(cfg)
%>
*/

#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <Eigen/LU>

namespace py = pybind11;

Eigen::MatrixXd inv(Eigen::MatrixXd xs) {
    return xs.inverse();
}

double det(Eigen::MatrixXd xs) {
    return xs.determinant();
}

Eigen::VectorXd scale_by_2_1(Eigen::VectorXd v) {
  v *= 2;
  return v;
}

Eigen::Ref<Eigen::VectorXd> scale_by_2_2(Eigen::Ref<Eigen::VectorXd> v) {
  v *= 2;
  return v;
}
Eigen::Ref<Eigen::VectorXd> scale_by_2_3(Eigen::Ref<Eigen::VectorXd> v) {
  v *= 2;
  return v;
}

PYBIND11_PLUGIN(code) {
    pybind11::module m("code", "auto-compiled c++ extension");
    m.attr("have_eigen") = true;
    m.def("inv", &inv);
    m.def("det", &det);
    m.def("scale_by_2_1", &scale_by_2_1);
    m.def("scale_by_2_2", &scale_by_2_2);
    m.def("scale_by_2_3", &scale_by_2_3, py::return_value_policy::reference_internal);
    return m.ptr();
}
