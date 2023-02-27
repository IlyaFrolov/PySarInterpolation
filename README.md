0. dependencies

pybind 11
https://github.com/pybind/pybind11.git

Catch2
https://github.com/catchorg/Catch2.git

MPI, OpenMP

1. Download
git clone https://github.com/IlyaFrolov/PySarInterpolation.git
cd PySarInterpolation
git submodule update --init --recursive

2. Build
python3 setup.py bdist_wheel

3. Install
cd dist
pip install PySarInterpolation-0.0.1-cp310-cp310-linux_x86_64.whl


