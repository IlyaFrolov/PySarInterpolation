#include <pybind11/pybind11.h>
//#include "Eigen/Dense"
#include <pybind11/eigen.h>
#include "interpolation.hpp"
//#include "interpolation.hpp"
/*
Eigen::MatrixXd interpolate_py(Eigen::MatrixXd samples, Eigen::MatrixXd new_indexes, Eigen::MatrixXd kernels)
{
	Eigen::MatrixXd result;
	interpolation::interpolate_cpu(kernels, samples, new_indexes, result);
	return result;
}

Eigen::MatrixXd generate_sinc_kernels_py(double step, int stencil_size)
{
	return interpolation::generate_sinc_kernels<double>(step, stencil_size);
}
*/
Eigen::MatrixXd interpolate(Eigen::MatrixXd samples, Eigen::MatrixXd new_indexes, Eigen::MatrixXd kernels)
{
	Eigen::MatrixXd res;
	interpolation::interpolate_cpu(kernels, samples, new_indexes, res);
	return res;
}

Eigen::MatrixXd generate_sinc_kernels(double step, int stencil_size)
{
	return interpolation::generate_sinc_kernels<double>(step, stencil_size);
}

PYBIND11_MODULE(PySarInterpolation, m) {
	m.def("interpolate", &interpolate, "interpolate func");
	m.def("generate_sinc_kernels", &generate_sinc_kernels, "generate sinc kernels func");
//	m.def("interpolate", &interpolate_py, "interpolation");
//	m.def("generate_sinc_kernels", &generate_sinc_kernels_py, "generate sinc kernels");
}
